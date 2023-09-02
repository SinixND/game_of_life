#include <iostream>
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION //only define once
#include <raygui.h>

#include "sndConfigs.h" // provide object "config" for configurable parameters
#include "sndGlobals.h" // provide object "global" for not configurable application parameters

#include "sndScreen.h"
#include "sndMenu.h"

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(config.windowWidth, config.windowHeight, "Conway's Game of Life");
    SetTargetFPS(config.targetFPS);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
    SetExitKey(0);

    // Initialize screens
    Menu menu;
    
    // MAIN APP LOOP
    //---------------------------------
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        switch (currentScreen)
        {
        case MENU:
            menu.Run();
            break;

        case GAME:
            //RunGame();
            break;

        case SETTINGS:
            //RunSettings();
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
