#include "screens.h"

#include "raylib.h"
#include "raygui.h"

#include "globals.h"
#include "panels.h"

cPanel screenMenu(windowWidth, windowHeight, 0, 0, 10);

void processMenuScreen();
void updateMenuScreen();
void outputMenuScreen();

void runMenuScreen() {
  processMenuScreen();
  updateMenuScreen();
  outputMenuScreen();
}

void processMenuScreen(){};

void updateMenuScreen(){};

void outputMenuScreen() {
  BeginDrawing();
  ClearBackground(BG);

  int rectButtonMenuWidth = guiButtonBaseWidth + MeasureText("Start Game", DEFAULT);

  if (GuiButton(Rectangle{float(alignHorizontalCenter(screenMenu, rectButtonMenuWidth)), float(alignVerticalTop(screenMenu, guiButtonBaseHeight)), float(rectButtonMenuWidth), float(guiButtonBaseHeight)}, TextFormat("Start Game")) || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
    currentScreen = GAME;
  }

  if (GuiButton(Rectangle{float(alignHorizontalCenter(screenMenu, rectButtonMenuWidth)), float(alignVerticalCenter(screenMenu, guiButtonBaseHeight)), float(rectButtonMenuWidth), float(guiButtonBaseHeight)}, TextFormat("Settings")) || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
    currentScreen = SETTINGS;
  }

  EndDrawing();
}
