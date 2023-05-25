#include "screens.h"

#include <iostream>
#include <vector>

#include "raylib.h"
#define RAYBUI_IMPLEMENTATION
#include "raygui.h"

#include "globals.h"
#include "agents.h"
#include "panels.h"

// GAME SCREEN
//---------------------------------
bool pauseState = true;

// MENUBAR
//---------------------------------
cPanel menubar(windowWidth, 75, 0, 0, 10);
const char *txtButtonPause = "[P]ause";
const char *txtButtonDarkMode;

// STATUSBAR
//---------------------------------
cPanel statusbar(windowWidth, (txtSmall + 20), 0, (windowHeight - (txtSmall + 20)), 10);

// DISPLAY
//---------------------------------
cPanel display(windowWidth, windowHeight - menubar.getPanelHeight() - statusbar.getPanelHeight(), 0, menubar.getPanelHeight(), 10);

// AGENT
//---------------------------------
int agentWidth = 10;
int agentHeight = agentWidth; // independent height and width possible
int agentInnerBorderWeight = 1;
bool decayingAgents = true;

// AGENTS
//---------------------------------
int agentGap = 1;
int colsX = display.getPanelContentWidth() / (agentWidth + agentGap);
int rowsY = display.getPanelContentHeight() / (agentHeight + agentGap);
int agentsSize = colsX * rowsY;
bool evolutionState = true;
bool agentsInitialized = false;
std::vector<std::vector<cAgent>> agents;

// LOGIC
//---------------------------------
float lifeDensity = 0.25; // in %, eg. 25
int evolutionTime = 100;         // in ms
float timePassed = 0;
int day = 0;
std::vector<int> agentsState0;
std::vector<int> agentsState1;
std::vector<int> agentsState2;

// GAME END OVERLAY
//---------------------------------
bool gameEndOverlayVisible = true;
Rectangle rectGameEndBackground{0, 0, float(windowWidth), float(windowHeight)};

void initialiseGameScreen() {
  // INITIALISE AGENTS
  //---------------------------------
  for (int rowY = 0; rowY < rowsY; ++rowY) {
    std::vector<cAgent> row;
    agents.push_back(row);

    for (int colX = 0; colX < colsX; ++colX) {
      agents[rowY].push_back(cAgent(rowY, colX));

      cAgent &agent = agents[rowY][colX];

      if (((rand() % 100) * 0.01) <= lifeDensity) {
        agent.setStatusIs(true); // make alive
      }
    }
  }
}

void processGameScreen() {
  if (IsKeyPressed(KEY_P)) {
    pauseState = !pauseState;
  }

  if (pauseState == true) {
    return;
  }

  // DETERMINE NEXT DAY AGENTS STATE
  //---------------------------------
  for (int rowY = 0; rowY < rowsY; ++rowY) {
    for (int colX = 0; colX < colsX; ++colX) {
      cAgent &agent = agents[rowY][colX];

      // Default Ruleset:
      // Adjacent count = 2 -> remain.
      // Adjacent count = 3 -> alive.
      // All other die.

      if (agent.getCheckStatus() == false)
      {
        continue;
      }
      agent.setCheckStatus(false);

      if (agent.countAdjacents(agents) == 2) {
        agent.setStatusNext(agent.getStatusIs());
      } else if (agent.countAdjacents(agents) == 3) {
        agent.setStatusNext(true);
      } else {
        agent.setStatusNext(false);
      }
    }
  }

  if ((evolutionState == false) && (gameEndOverlayVisible == true)) {
    if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), rectGameEndBackground)) || IsKeyPressed(KEY_ENTER)) {
      gameEndOverlayVisible = false;
    }
  }
}

void updateGameScreen() {
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
      cAgent &agent = agents[rowY][colX];

      if (agent.getStatusChanging() == true) {
        agent.pingAdjacents(agents);

        if (agent.getStatusNext() == true) {
          agent.setStatusIs(true);

          if (decayingAgents == true) {
            agent.setVitality(4);
          }
        } else {
          agent.setStatusIs(false);
        }
      }

      if (agent.getStatusIs() == true) {
        agentsState0.push_back(1);
      } else {
        agentsState0.push_back(0);
        agent.decreaseVitality();
      }
    }
  }

  if (agentsState0 == agentsState2) {
    evolutionState = false;
  }
}

void outputGameScreen() {
  BeginDrawing();
  ClearBackground(BG);

  // MENUBAR
  //---------------------------------
  int rectButtonPauseWidth = MeasureText("Resume", txtSmall);
  if (GuiButton(Rectangle{float(alignHorizontalCenter(menubar, rectButtonPauseWidth)), float(alignVerticalTop(menubar, 0)), float(rectButtonPauseWidth), float(txtSmall + 10)}, txtButtonPause)) {
    pauseState = !pauseState;
  };

  int rectButtonDarkModeWidth = MeasureText("Light", txtSmall);
  if (GuiButton(Rectangle{float(alignHorizontalRight(menubar, rectButtonDarkModeWidth, 0)), float(alignVerticalTop(menubar, 0)), float(rectButtonDarkModeWidth), float(txtSmall + 10)}, txtButtonDarkMode)) {
    darkMode = !darkMode;
  };

  // STATUSBAR
  //---------------------------------
  DrawText(TextFormat("Time: %i ms; Day: %i", evolutionTime, day), alignHorizontalLeft(statusbar, 0), alignVerticalTop(statusbar, 0), txtSmall, FG);

  // DISPLAY
  //---------------------------------
  // draw agents
  for (int rowY = 0; rowY < rowsY; ++rowY) {
    for (int colX = 0; colX < colsX; ++colX) {
      cAgent &agent = agents[rowY][colX];

      Rectangle rectAgent{float(alignHorizontalCenter(display, (colsX * (agentWidth + agentGap) - agentGap)) + (colX * (agentWidth + agentGap))), float(alignVerticalCenter(display, (rowsY * (agentHeight + agentGap) - agentGap)) + (rowY * (agentHeight + agentGap))), float(agentWidth), float(agentHeight)};

      if (agent.getStatusIs() == true) {
        DrawRectangleRec(rectAgent, FG);
      } else {
        Color agentVitalityColor;
        switch (agent.getVitality()) {
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
    Rectangle rectDisplay{float(display.getPanelLeftX()), float(display.getPanelTopY()), float(display.getPanelWidth()), float(display.getPanelHeight())};

    DrawRectangleRec(Rectangle{float(display.getPanelLeftX()), float(display.getPanelTopY()), float(display.getPanelWidth()), float(display.getPanelHeight())}, CLITERAL(Color){130, 130, 130, 175});

    DrawRectangleLinesEx(rectDisplay, 10, DARKGRAY);

    const char *txtPaused = TextFormat("[P]aused...");
    DrawText(txtPaused, alignHorizontalRight(statusbar, MeasureText(txtPaused, txtNormal), 0), alignVerticalCenter(statusbar, txtNormal), txtNormal, FG);
  }

  DrawFPS(GetScreenWidth() - 95, 10);
  EndDrawing();
}

void runGameScreen() {
  if (agentsInitialized == false) {
    initialiseGameScreen();
    outputGameScreen();
    agentsInitialized = true;
  }

  processGameScreen();
  updateGameScreen();

  outputGameScreen();
}