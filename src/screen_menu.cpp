#include "screens.h"

#include "raylib.h"
#include "raygui.h"

#include "globals.h"
#include "panels.h"

cPanel screenMenu(windowWidth, windowHeight, 0, 0, 10);

void processMenuScreen(){}

void updateMenuScreen(){}

void outputMenuScreen() {
  BeginDrawing();
  ClearBackground(BG);

  int rectButtonWidth = MeasureText("Start Game", txtNormal);
//int rectButtonWidth = MeasureText("Settings", txtNormal);
int rectButtonHeight = txtNormal + 10;


  if (GuiButton(Rectangle{float(alignHorizontalCenter(screenMenu, rectButtonWidth)), float(alignVerticalTop(screenMenu, rectButtonHeight)), float(rectButtonWidth), float(rectButtonHeight)}, TextFormat("Start Game")) || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
    currentScreen = GAME;
  }

  if (GuiButton(Rectangle{float(alignHorizontalCenter(screenMenu, rectButtonWidth)), float(alignVerticalCenter(screenMenu, rectButtonHeight)), float(rectButtonWidth), float(rectButtonHeight)}, TextFormat("Settings")) || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
    currentScreen = SETTINGS;
  }

  EndDrawing();
}

void runMenuScreen() {
  processMenuScreen();
  updateMenuScreen();
  outputMenuScreen();
}