#include <iostream>
#include <raylib.h>
#include <raygui.h>

#include "configs.h" // provide object "config" for configurable parameters
#include "globals.h" // provide object "global" for not configurable application parameters

#include "screens.h"

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(config.windowWidth, config.windowHeight, "Conway's Game of Life");
    SetTargetFPS(config.targetFPS);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
    SetExitKey(0);

    // MAIN APP LOOP
    //---------------------------------
    while (!WindowShouldClose() && !global.exitApp) // Detect window close button or ESC key
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
