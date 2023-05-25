#include "screens.h"

#include "raylib.h"
#define RAYBUI_IMPLEMENTATION
#include "globals.h"
#include "panels.h"
#include "raygui.h"

cPanel screenMenu(windowWidth, windowHeight, 0, 0, 10);

void processMenuScreen(){}

void updateMenuScreen(){}

void outputMenuScreen() {
  BeginDrawing();
  ClearBackground(BG);

  int rectButtonStartWidth = MeasureText("Start", txtNormal);
  int rectButtonStartHeight = txtNormal + 10;
  if (GuiButton(Rectangle{float(alignHorizontalCenter(screenMenu, rectButtonStartWidth)), float(alignVerticalCenter(screenMenu, rectButtonStartHeight)), float(rectButtonStartWidth), float(rectButtonStartHeight)}, TextFormat("Start"))) {
    currentScreen = GAME;
  }

  DrawFPS(GetScreenWidth() - 95, 10);
  EndDrawing();
}

void runMenuScreen() {
  processMenuScreen();
  updateMenuScreen();
  outputMenuScreen();
}