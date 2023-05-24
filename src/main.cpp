#include <iostream>
#include <vector>
#include <time.h>

#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include "agents.h"

//============================
// Define globals
//============================
#include "globals.h"

//============================
// Define screens
//============================
#include "screens.h"

int main()
{
  InitWindow(windowWidth, windowHeight, "Conway's Game of Life");
  SetTargetFPS(targetFPS);

//============================
// MAIN APP LOOP
//============================
  while (!WindowShouldClose()) // Detect window close button or ESC keWHITEy
  {
    //============================
    // Define color mode
    //============================
    if (darkMode == true)
    {
      BG = BLACK;
      FG = WHITE;
      FG2 = LIGHTGRAY;
      FG3 = GRAY;
      FG4 = DARKGRAY;
    }
    else
    {
      BG = WHITE;
      FG = BLACK;
      FG2 = DARKGRAY;
      FG3 = GRAY;
      FG4 = LIGHTGRAY;
    }

    switch (currentScreen)
    {
    case MENU:
      runMenuScreen();
      break;

    case GAME:
      runGameScreen();
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