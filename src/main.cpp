#include <iostream>
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION //only define once
#include <raygui.h>
#include "sndConfigs.h" // provide object "config" for configurable parameters
#include "sndGlobals.h" // provide object "global" for not configurable application parameters
#include "sndScenes.h"
#include "sndBenchmark.h"

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_WINDOW_TRANSPARENT);
    InitWindow(640, 480, "Conway's Game of Life");
    SetTargetFPS(config.targetFPS);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
    SetExitKey(0);

    Menu menu;
    Settings settings;

    // MAIN APP LOOP
    //---------------------------------
    while (!WindowShouldClose() && !global.exitApp) // Detect window close button or ESC key
    {
        if(IsWindowResized())
        {
            menu.Initialize();
            settings.Initialize();
        }
    
        switch (currentScene)
        {
        case MENU:
            StartBenchmark("menu.Update()");
            menu.Update();
            StopBenchmark("menu.Update()");
            break;

        case GAME:
            //RunGame();
            break;

        case SETTINGS:
            StartBenchmark("settings.Update()");
            settings.Update();
            StopBenchmark("settings.Update()");
            break;

        default:
            break;
        }
        ShowBenchmarks();
    }

    // SHUTDOWN APP
    //---------------------------------
    CloseWindow(); // Close window and OpenGL context

    return 0;
}
