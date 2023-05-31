#include "screens.h"

#include "raylib.h"
#include "raygui.h"

#include "globals.h"
#include "panels.h"

cPanel screenMenu(windowWidth, windowHeight, 0, 0, 10);

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
  ClearBackground(BG);

  int rectButtonMenuWidth = guiButtonBaseWidth + MeasureText("Start Game", DEFAULT);

  if (GuiButton(Rectangle{float(AlignHorizontalCenter(screenMenu, rectButtonMenuWidth)), float(AlignVerticalTop(screenMenu, guiButtonBaseHeight)), float(rectButtonMenuWidth), float(guiButtonBaseHeight)}, TextFormat("Start Game")) || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
    currentScreen = GAME;
  }

  if (GuiButton(Rectangle{float(AlignHorizontalCenter(screenMenu, rectButtonMenuWidth)), float(AlignVerticalCenter(screenMenu, guiButtonBaseHeight)), float(rectButtonMenuWidth), float(guiButtonBaseHeight)}, TextFormat("Settings")) || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
    currentScreen = SETTINGS;
  }

  EndDrawing();
}
