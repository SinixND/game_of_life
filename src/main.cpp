#include <iostream>
#include <time.h>
#include <vector>

#include "raylib.h"

#include "agents.h"
#include "globals.h"
#include "screens.h"

int main() {
  //============================
  // Adjust window if greater than screen
  //============================
  //int monitorWidth = GetMonitorWidth(GetCurrentMonitor());
  //int monitorHeight = GetMonitorHeight(GetCurrentMonitor());
  //if (monitorWidth < windowWidth) {
    //windowWidth = monitorWidth;
  //}
  //if (monitorHeight < windowHeight) {
    //windowHeight = monitorHeight;
  //}
  //SetWindowSize(windowWidth, windowHeight);
  //SetWindowPosition(0, 0);

  InitWindow(windowWidth, windowHeight, "Conway's Game of Life");
  SetTargetFPS(targetFPS);

  //============================
  // MAIN APP LOOP
  //============================
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    //============================
    // Define color mode
    //============================
    if (darkMode == true) {
      BG = BLACK;
      FG = WHITE;
      FG2 = LIGHTGRAY;
      FG3 = GRAY;
      FG4 = DARKGRAY;
    } else {
      BG = WHITE;
      FG = BLACK;
      FG2 = DARKGRAY;
      FG3 = GRAY;
      FG4 = LIGHTGRAY;
    }

    switch (currentScreen) {
    case MENU:
      RunMenuScreen();
      break;

    case GAME:
      RunGameScreen();
      break;

    default:
      break;
    }
  }

  //============================
  // SHUTDOWN APP
  //============================
  CloseWindow(); // Close window and OpenGL context

  return 0;
}