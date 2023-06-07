#include "screens.h"

#include "raylib.h"
#include "raygui.h"

#include "globals.h" // provide object "global" for not configurable application parameters
#include "configs.h" // provide object "config" for configurable parameters
#include "panels.h"

cPanel screenMenu(config.windowWidth, config.windowHeight, 0, 0, 10);

void ProcessMenuScreen();
void UpdateMenuScreen();
void OutputMenuScreen();

void RunMenuScreen() {
  ProcessMenuScreen();
  UpdateMenuScreen();
  OutputMenuScreen();
}

void ProcessMenuScreen(){};

void UpdateMenuScreen(){};

void OutputMenuScreen() {
  BeginDrawing();
  ClearBackground(global.getColorBackground());

  int rectButtonMenuWidth = global.guiButtonBaseWidth + MeasureText("Start Game", DEFAULT);

  if (GuiButton(Rectangle{float(AlignHorizontalCenter(screenMenu, rectButtonMenuWidth)), float(AlignVerticalTop(screenMenu, global.guiButtonBaseHeight)), float(rectButtonMenuWidth), float(global.guiButtonBaseHeight)}, TextFormat("Start Game")) || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
    currentScreen = GAME;
  }

  if (GuiButton(Rectangle{float(AlignHorizontalCenter(screenMenu, rectButtonMenuWidth)), float(AlignVerticalCenter(screenMenu, global.guiButtonBaseHeight)), float(rectButtonMenuWidth), float(global.guiButtonBaseHeight)}, TextFormat("Settings")) || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
    currentScreen = SETTINGS;
  }

  EndDrawing();
}
