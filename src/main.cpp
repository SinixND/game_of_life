#include <iostream>
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION //only define once
#include <raygui.h>
#include "sndConfigs.h" // provide object "config" for configurable parameters
#include "sndGlobals.h" // provide object "global" for not configurable application parameters
#include "sndScenes.h"

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_WINDOW_TRANSPARENT);
    InitWindow(640, 480, "Conway's Game of Life");
    SetTargetFPS(config.targetFPS);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
    SetExitKey(0);

    Menu menu;

    // MAIN APP LOOP
    //---------------------------------
    while (!WindowShouldClose() && !global.exitApp) // Detect window close button or ESC key
    {
        switch (currentScene)
        {
        case MENU:
            if(IsWindowResized())
            {
                menu.Initialize();
            }
    
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
