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
cPanel panelMenubarScreenGame(config.windowWidth, (global.guiButtonBaseHeight + 20), 0, 0, 10);
cPanel panelStatusbarScreenGame(config.windowWidth, (global.txtSmall + 20), 0, (config.windowHeight - (global.txtSmall + 20)), 10);
cPanel panelMainScreenGame(config.windowWidth, config.windowHeight - panelMenubarScreenGame.mPanelHeight - panelStatusbarScreenGame.mPanelHeight, 0, panelMenubarScreenGame.mPanelHeight, 10);

const char *txtButtonBackScreenGame = "Back";
const char *txtButtonPause = "[P]ause";
const char *txtButtonDarkModeScreenGame;

// GAME OF LIFE / GRID
//---------------------------------
bool pauseState = false;
bool evolutionState = true;
bool gameScreenInitialized = false;
float timePassed = 0;

bool ScreenGameInitialized = false;

int rowsY = panelMainScreenGame.GetPanelContentHeight() / (config.agentHeight + config.agentGap);
int colsX = panelMainScreenGame.GetPanelContentWidth() / (config.agentWidth + config.agentGap);

// GAME END OVERLAY
//---------------------------------
bool gameEndOverlayVisible = true;
Rectangle rectGameEndBackground{0, 0, float(config.windowWidth), float(config.windowHeight)};

// FUNCTION DECLARATION
//---------------------------------
void InitializeGameScreen();
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
void InitializeGameScreen() {
  if (ScreenGameInitialized == false) {
    static cGameOfLife GoL(rowsY, colsX);
    ScreenGameInitialized = true;
  }
};

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
  // MENUBAR PANEL
  //---------------------------------
  if (global.GetDarkMode() == true) {
    txtButtonDarkModeScreenGame = "Light";
  } else {
    txtButtonDarkModeScreenGame = "Dark";
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

  // MENUBAR PANEL
  //---------------------------------
  int rectButtonBackWidth = global.guiButtonBaseWidth + MeasureText(txtButtonBackScreenGame, DEFAULT);
  if (GuiButton(Rectangle{float(AlignHorizontalLeft(panelMenubarScreenGame, rectButtonBackWidth)), float(AlignVerticalTop(panelMenubarScreenGame, 0)), float(rectButtonBackWidth), float(global.guiButtonBaseHeight)}, txtButtonBackScreenGame)) {

    currentScreen = MENU;
  };

  int rectButtonPauseWidth = global.guiButtonBaseWidth + MeasureText("Resume", DEFAULT);
  if (GuiButton(Rectangle{float(AlignHorizontalCenter(panelMenubarScreenGame, rectButtonPauseWidth)), float(AlignVerticalTop(panelMenubarScreenGame, 0)), float(rectButtonPauseWidth), float(global.guiButtonBaseHeight)}, txtButtonPause)) {
    pauseState = !pauseState;
  };

  int rectButtonDarkModeWidth = global.guiButtonBaseWidth + MeasureText("Light", global.txtSmall);
  if (GuiButton(Rectangle{float(AlignHorizontalRight(panelMenubarScreenGame, rectButtonDarkModeWidth, 0)), float(AlignVerticalTop(panelMenubarScreenGame, 0)), float(rectButtonDarkModeWidth), float(global.guiButtonBaseHeight)}, txtButtonDarkModeScreenGame)) {
    global.SetDarkMode(!global.GetDarkMode());
  };

  // STATUSBAR PANEL
  //---------------------------------
  DrawText(TextFormat("TickTime: %.0f ms; Day: %i", config.tickTime * 1000, GoL.GetDay()), AlignHorizontalLeft(panelStatusbarScreenGame, 0), AlignVerticalCenter(panelStatusbarScreenGame, global.txtSmall), global.txtSmall, global.GetColorForeground());

  // MAIN PANEL
  //---------------------------------
  // draw agents
  for (auto& row : GoL.GetGrid()) {
    for (auto& agent : row) {
      Rectangle rectAgent{float(AlignHorizontalCenter(panelMainScreenGame, (colsX * (config.agentWidth + config.agentGap) - config.agentGap)) + (agent.mPosX * (config.agentWidth + config.agentGap))), float(AlignVerticalCenter(panelMainScreenGame, (rowsY * (config.agentHeight + config.agentGap) - config.agentGap)) + (agent.mPosY * (config.agentHeight + config.agentGap))), float(config.agentWidth), float(config.agentHeight)};

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
    Rectangle rectpanelMainScreenGame{float(panelMainScreenGame.mPanelLeftX), float(panelMainScreenGame.mPanelTopY), float(panelMainScreenGame.mPanelWidth), float(panelMainScreenGame.mPanelHeight)};

    DrawRectangleRec(Rectangle{float(panelMainScreenGame.mPanelLeftX), float(panelMainScreenGame.mPanelTopY), float(panelMainScreenGame.mPanelWidth), float(panelMainScreenGame.mPanelHeight)}, CLITERAL(Color){130, 130, 130, 175});

    DrawRectangleLinesEx(rectpanelMainScreenGame, 10, DARKGRAY);

    const char *txtPaused = TextFormat("[P]aused...");
    DrawText(txtPaused, AlignHorizontalRight(panelStatusbarScreenGame, MeasureText(txtPaused, global.txtSmall), 0), AlignVerticalCenter(panelStatusbarScreenGame, global.txtSmall), global.txtSmall, global.GetColorForeground());
  }

  //DrawFPS(GetScreenWidth() - 95, 10);
  EndDrawing();
}
