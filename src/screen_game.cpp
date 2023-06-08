#include "screens.h"

#include <iostream>
#include <vector>

#include "raylib.h"
#include "raygui.h"

#include "globals.h" // provide object "global" for not configurable application parameters
#include "configs.h" // provide object "config" for configurable parameters
#include "gameoflife.h"
#include "panels.h"

// SET GUI ELEMENTS
//---------------------------------
cPanel menubar(config.windowWidth, (global.guiButtonBaseHeight + 20), 0, 0, 10);
cPanel statusbar(config.windowWidth, (global.txtSmall + 20), 0, (config.windowHeight - (global.txtSmall + 20)), 10);
cPanel display(config.windowWidth, config.windowHeight - menubar.mPanelHeight - statusbar.mPanelHeight, 0, menubar.mPanelHeight, 10);

const char *txtButtonPause = "[P]ause";
const char *txtButtonDarkMode;

// GAME OF LIFE / GRID
//---------------------------------
bool pauseState = false;
bool evolutionState = true;
bool gameScreenInitialized = false;
float timePassed = 0;

int rowsY = display.GetPanelContentHeight() / (config.agentHeight + config.agentGap);
int colsX = display.GetPanelContentWidth() / (config.agentWidth + config.agentGap);

cGameOfLife GoL(rowsY, colsX);

// GAME END OVERLAY
//---------------------------------
bool gameEndOverlayVisible = true;
Rectangle rectGameEndBackground{0, 0, float(config.windowWidth), float(config.windowHeight)};

// FUNCTION DECLARATION
//---------------------------------
void ProcessGameScreen();
void UpdateGameScreen();
void OutputGameScreen();

void RunGameScreen() {
  ProcessGameScreen();
  UpdateGameScreen();
  OutputGameScreen();
}

// FUNCTION DEFINITION
//---------------------------------
void ProcessGameScreen() {
  if (IsKeyPressed(KEY_P)) {
    pauseState = !pauseState;
  }

  if (pauseState == true) {
    return;
  }

  if ((evolutionState == false) && (gameEndOverlayVisible == true)) {
    if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), rectGameEndBackground)) || IsKeyPressed(KEY_ENTER)) {
      gameEndOverlayVisible = false;
    }
    return;
  }

  if (timePassed <= config.tickTime) {
    timePassed += GetFrameTime();
    return;
  }

  timePassed = 0;
  GoL.EvolveGrid();
}

void UpdateGameScreen() {
  // MENUBAR
  //---------------------------------
  if (global.GetDarkMode() == true) {
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

  // GAME END CONDITION
  //---------------------------------
  if (evolutionState == false) {
    return;
  }

  int currentState = GoL.mGridStates.size() - 1;
  if (GoL.mGridStates[currentState] == GoL.mGridStates[currentState - 2]) {
    evolutionState = false;
  }
}

void OutputGameScreen() {
  BeginDrawing();
  ClearBackground(global.GetColorBackground());

  // MENUBAR
  //---------------------------------
  int rectButtonPauseWidth = global.guiButtonBaseWidth + MeasureText("Resume", DEFAULT);
  if (GuiButton(Rectangle{float(AlignHorizontalCenter(menubar, rectButtonPauseWidth)), float(AlignVerticalTop(menubar, 0)), float(rectButtonPauseWidth), float(global.guiButtonBaseHeight)}, txtButtonPause)) {
    pauseState = !pauseState;
  };

  int rectButtonDarkModeWidth = global.guiButtonBaseWidth + MeasureText("Light", global.txtSmall);
  if (GuiButton(Rectangle{float(AlignHorizontalRight(menubar, rectButtonDarkModeWidth, 0)), float(AlignVerticalTop(menubar, 0)), float(rectButtonDarkModeWidth), float(global.guiButtonBaseHeight)}, txtButtonDarkMode)) {
    global.SetDarkMode(!global.GetDarkMode());
  };

  // STATUSBAR
  //---------------------------------
  DrawText(TextFormat("TickTime: %f/%f ms; Day: %i", config.tickTime, config.targetTickTime, GoL.GetDay()), AlignHorizontalLeft(statusbar, 0), AlignVerticalCenter(statusbar, global.txtSmall), global.txtSmall, global.GetColorForeground());

  // DISPLAY
  //---------------------------------
  // draw agents
  for (auto& row : GoL.GetGrid()) {
    for (auto& agent : row) {
      Rectangle rectAgent{float(AlignHorizontalCenter(display, (colsX * (config.agentWidth + config.agentGap) - config.agentGap)) + (agent.mPosX * (config.agentWidth + config.agentGap))), float(AlignVerticalCenter(display, (rowsY * (config.agentHeight + config.agentGap) - config.agentGap)) + (agent.mPosY * (config.agentHeight + config.agentGap))), float(config.agentWidth), float(config.agentHeight)};

      if (agent.mStatusIs == true) {
        DrawRectangleRec(rectAgent, global.GetColorForeground());
      } else {
        Color agentVitalityColor;
        switch (agent.mVitality) {
        case 4:
          agentVitalityColor = global.GetColorForeground();
          DrawRectangleRec(rectAgent, agentVitalityColor);
          break;

        case 3:
          agentVitalityColor = global.GetColorAgentDecay1();
          DrawRectangleRec(rectAgent, agentVitalityColor);
          break;

        case 2:
          agentVitalityColor = global.GetColorAgentDecay2();
          DrawRectangleRec(rectAgent, agentVitalityColor);
          break;

        case 1:
          agentVitalityColor = global.GetColorAgentDecay3();
          DrawRectangleRec(rectAgent, agentVitalityColor);
          break;

        default:
          DrawRectangleLinesEx(rectAgent, config.agentInnerBorderWeight, GRAY);
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
    DrawText(TextFormat("Game over!\nUniverse survived for %d days. \nPress Enter or click to \ngo back to agents. \nPress ESC to leave.", GoL.GetDay()), 50, 50, global.txtNormal, RED);
  }

  // DRAW PAUSE OVERLAY
  //---------------------------------
  else if (pauseState == true) {
    Rectangle rectDisplay{float(display.mPanelLeftX), float(display.mPanelTopY), float(display.mPanelWidth), float(display.mPanelHeight)};

    DrawRectangleRec(Rectangle{float(display.mPanelLeftX), float(display.mPanelTopY), float(display.mPanelWidth), float(display.mPanelHeight)}, CLITERAL(Color){130, 130, 130, 175});

    DrawRectangleLinesEx(rectDisplay, 10, DARKGRAY);

    const char *txtPaused = TextFormat("[P]aused...");
    DrawText(txtPaused, AlignHorizontalRight(statusbar, MeasureText(txtPaused, global.txtSmall), 0), AlignVerticalCenter(statusbar, global.txtSmall), global.txtSmall, global.GetColorForeground());
  }

  //DrawFPS(GetScreenWidth() - 95, 10);
  EndDrawing();
}
