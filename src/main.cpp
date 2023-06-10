#include <iostream>
#include <time.h>
#include <vector>

#include "raylib.h"

#include "agents.h"
#include "globals.h" // provide object "global" for not configurable application parameters
#include "configs.h" // provide object "config" for configurable parameters
#include "screens.h"

int main() {
  InitWindow(config.windowWidth, config.windowHeight, "Conway's Game of Life");
  SetTargetFPS(config.targetFPS);

  // MAIN APP LOOP
  //---------------------------------
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    switch (currentScreen) {
    case MENU:
      RunScreenMenu();
      break;

    case GAME:
      RunScreenGame();
      break;

    case SETTINGS:
      RunScreenSettings();
      break;

    default:
      break;
    }
  }

  // SHUTDOWN APP
  //---------------------------------
  CloseWindow(); // Close window and OpenGL context

  return 0;
}