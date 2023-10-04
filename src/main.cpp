#include <iostream>
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION //only define once
#include <raygui.h>

#include "sndConfigs.h" // provide object "config" for configurable parameters
#include "sndGlobals.h" // provide object "global" for not configurable application parameters

#include "sndScene.h"
#include "sndMenu.h"

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_WINDOW_TRANSPARENT);
    InitWindow(620, 480, "Conway's Game of Life");
    SetTargetFPS(config.targetFPS);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
    SetExitKey(0);

    // MAIN APP LOOP
    //---------------------------------
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        Menu menu;
    
        switch (currentScene)
        {
        case MENU:
            menu.Update();
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
