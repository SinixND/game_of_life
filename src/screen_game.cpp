#include "screens.h"

#include <iostream>
#include <vector>

#include "raylib.h"
#include "raygui.h"

#include "globals.h"
#include "agents.h"
#include "panels.h"
#include "benchmark.h"
//#define BENCHMARK_ON

// SET GUI ELEMENTS
//---------------------------------
cPanel menubar(windowWidth, (guiButtonBaseHeight + 20), 0, 0, 10);
cPanel statusbar(windowWidth, (txtSmall + 20), 0, (windowHeight - (txtSmall + 20)), 10);
cPanel display(windowWidth, windowHeight - menubar.mPanelHeight - statusbar.mPanelHeight, 0, menubar.mPanelHeight, 10);

const char *txtButtonPause = "[P]ause";
const char *txtButtonDarkMode;

// AGENTS / ENVIRONMENT
//---------------------------------
bool pauseState = false;
bool evolutionState = true;
bool agentsInitialized = false;
int colsX = display.GetPanelContentWidth() / (agentWidth + agentGap);
int rowsY = display.GetPanelContentHeight() / (agentHeight + agentGap);
int agentsSize = colsX * rowsY;

std::vector<std::vector<cAgent>> agents;

// LOGIC
//---------------------------------
float lifeDensity = 0.25; // in %, eg. 25
float timePassed = 0;
int day = 0;
std::vector<int> agentsState0;
std::vector<int> agentsState1;
std::vector<int> agentsState2;

// GAME END OVERLAY
//---------------------------------
bool gameEndOverlayVisible = true;
Rectangle rectGameEndBackground{0, 0, float(windowWidth), float(windowHeight)};

// FUNCTION DECLARATION
//---------------------------------
void InitialiseGameScreen();
void ProcessGameScreen();
void UpdateGameScreen();
void OutputGameScreen();

void RunGameScreen() {
  if (agentsInitialized == false) {
    InitialiseGameScreen();
    OutputGameScreen();
    agentsInitialized = true;
  }

  ProcessGameScreen();
  UpdateGameScreen();
  OutputGameScreen();

  ShowBenchmark();
}

// FUNCTION DEFINITION
//---------------------------------
void InitialiseGameScreen() {
  // INITIALISE AGENTS
  //---------------------------------
  for (int rowY = 0; rowY < rowsY; ++rowY) {
    std::vector<cAgent> row;
    agents.push_back(row);

    for (int colX = 0; colX < colsX; ++colX) {
      agents[rowY].push_back(cAgent(rowY, colX));

      cAgent& agent = agents[rowY][colX];

      if (((rand() % 100) * 0.01) <= lifeDensity) {
        agent.mStatusIs = true; // make alive
      }
    }
  }
}

void ProcessGameScreen() {
  if (IsKeyPressed(KEY_P)) {
    pauseState = !pauseState;
  }

  if (pauseState == true) {
    return;
  }

  if (timePassed <= evolutionTime) {
    return;
  }

  #ifdef BENCHMARK_ON
    StartBenchmark("bm_process_game_screen");
  #endif

  // DETERMINE NEXT DAY AGENTS STATE
  //---------------------------------
  for (int rowY = 0; rowY < rowsY; ++rowY) {
    for (int colX = 0; colX < colsX; ++colX) {
      cAgent& agent = agents[rowY][colX];

      // Default Ruleset:
      // AdjacentAgent count = 2 -> remain.
      // AdjacentAgent count = 3 -> alive.
      // All other die.

      if (agent.mCheckStatus == false)
      {
        continue;
      }
      agent.mCheckStatus = false;

      switch (agent.CountAdjacentAgents(agents)){
      case 2:
        agent.SetStatusNext(agent.mStatusIs);
        break;
      
      case 3:
        agent.SetStatusNext(true);
        break;
      
      default:
        agent.SetStatusNext(false);
        break;
      }
    }
  }

  #ifdef BENCHMARK_ON
    StopBenchmark("bm_process_game_screen");
  #endif

  if ((evolutionState == false) && (gameEndOverlayVisible == true)) {
    if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), rectGameEndBackground)) || IsKeyPressed(KEY_ENTER)) {
      gameEndOverlayVisible = false;
    }
  }
}

void UpdateGameScreen() {
  // MENUBAR
  //---------------------------------
  if (darkMode == true) {
    txtButtonDarkMode = "Light";
  } else {
    txtButtonDarkMode = "Dark";
  }

  if (pauseState == true) {
    txtButtonPause = "Resume";
    return;
  } else {
    txtButtonPause = "Pause";
  }

  // DISPLAY
  //---------------------------------
  if (evolutionState == false) {
    return;
  }

  if (timePassed <= evolutionTime) {
    timePassed += GetFrameTime() * 1000;
    return;
  }

  #ifdef BENCHMARK_ON
    StartBenchmark("bm_update_display");
  #endif

  timePassed = 0;
  day += 1;

  // remember last 3 agents states for game end condition
  agentsState2 = agentsState1;
  agentsState1 = agentsState0;
  agentsState0.clear();

  // UPDATE AGENTS
  //---------------------------------
  for (int rowY = 0; rowY < rowsY; ++rowY) {
    for (int colX = 0; colX < colsX; ++colX) {
      cAgent& agent = agents[rowY][colX];

      if (agent.mStatusChanging == true) {
        agent.PingAdjacentAgents(agents);

        if (agent.GetStatusNext() == true) {
          agent.mStatusIs = true;

          if (decayingAgents == true) {
            agent.mVitality = 4;
          }
        } else {
          agent.mStatusIs = false;
        }
      }

      if (agent.mStatusIs == true) {
        agentsState0.push_back(1);
      } else {
        agentsState0.push_back(0);
        agent.DecreaseVitality();
      }
    }
  }

  if (agentsState0 == agentsState2) {
    evolutionState = false;
  }

  #ifdef BENCHMARK_ON
    StopBenchmark("bm_update_display");
  #endif
}

void OutputGameScreen() {
  BeginDrawing();
  ClearBackground(BG);

  #ifdef BENCHMARK_ON
  if (pauseState == false) {
    StartBenchmark("bm_ouput_game_screen");
  }
  #endif

  // MENUBAR
  //---------------------------------
  int rectButtonPauseWidth = guiButtonBaseWidth + MeasureText("Resume", DEFAULT);
  if (GuiButton(Rectangle{float(AlignHorizontalCenter(menubar, rectButtonPauseWidth)), float(AlignVerticalTop(menubar, 0)), float(rectButtonPauseWidth), float(guiButtonBaseHeight)}, txtButtonPause)) {
    pauseState = !pauseState;
  };

  int rectButtonDarkModeWidth = guiButtonBaseWidth + MeasureText("Light", txtSmall);
  if (GuiButton(Rectangle{float(AlignHorizontalRight(menubar, rectButtonDarkModeWidth, 0)), float(AlignVerticalTop(menubar, 0)), float(rectButtonDarkModeWidth), float(guiButtonBaseHeight)}, txtButtonDarkMode)) {
    darkMode = !darkMode;
  };

  // STATUSBAR
  //---------------------------------
  DrawText(TextFormat("Time: %i ms; Day: %i", evolutionTime, day), AlignHorizontalLeft(statusbar, 0), AlignVerticalCenter(statusbar, txtSmall), txtSmall, FG);

  // DISPLAY
  //---------------------------------
  // draw agents
  for (int rowY = 0; rowY < rowsY; ++rowY) {
    for (int colX = 0; colX < colsX; ++colX) {
      cAgent& agent = agents[rowY][colX];

      Rectangle rectAgent{float(AlignHorizontalCenter(display, (colsX * (agentWidth + agentGap) - agentGap)) + (colX * (agentWidth + agentGap))), float(AlignVerticalCenter(display, (rowsY * (agentHeight + agentGap) - agentGap)) + (rowY * (agentHeight + agentGap))), float(agentWidth), float(agentHeight)};

      if (agent.mStatusIs == true) {
        DrawRectangleRec(rectAgent, FG);
      } else {
        Color agentVitalityColor;
        switch (agent.mVitality) {
        case 4:
          agentVitalityColor = FG;
          DrawRectangleRec(rectAgent, agentVitalityColor);
          break;

        case 3:
          agentVitalityColor = FG2;
          DrawRectangleRec(rectAgent, agentVitalityColor);
          break;

        case 2:
          agentVitalityColor = FG3;
          DrawRectangleRec(rectAgent, agentVitalityColor);
          break;

        case 1:
          agentVitalityColor = FG4;
          DrawRectangleRec(rectAgent, agentVitalityColor);
          break;

        default:
          DrawRectangleLinesEx(rectAgent, agentInnerBorderWeight, GRAY);
          break;
        }
      }
    }
  }

  // DRAW GAME END OVERLAY
  //---------------------------------
  if ((evolutionState == false) && (gameEndOverlayVisible == true)) {
    DrawRectangleRec(rectGameEndBackground, CLITERAL(Color){130, 130, 130, 175});
    DrawRectangleLinesEx(rectGameEndBackground, 10, DARKGRAY);
    DrawText(TextFormat("Game over!\nUniverse survived for %d days. \nPress Enter or click to \ngo back to agents. \nPress ESC to leave.", day), 50, 50, txtNormal, RED);
  }

  // DRAW PAUSE OVERLAY
  //---------------------------------
  else if (pauseState == true) {
    Rectangle rectDisplay{float(display.mPanelLeftX), float(display.mPanelTopY), float(display.mPanelWidth), float(display.mPanelHeight)};

    DrawRectangleRec(Rectangle{float(display.mPanelLeftX), float(display.mPanelTopY), float(display.mPanelWidth), float(display.mPanelHeight)}, CLITERAL(Color){130, 130, 130, 175});

    DrawRectangleLinesEx(rectDisplay, 10, DARKGRAY);

    const char *txtPaused = TextFormat("[P]aused...");
    DrawText(txtPaused, AlignHorizontalRight(statusbar, MeasureText(txtPaused, txtSmall), 0), AlignVerticalCenter(statusbar, txtSmall), txtSmall, FG);
  }

  #ifdef BENCHMARK_ON
  if (pauseState == false) {
    StopBenchmark("bm_ouput_game_screen");
  }
  #endif

  DrawFPS(GetScreenWidth() - 95, 10);
  EndDrawing();
}
