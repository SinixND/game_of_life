#include <iostream>
#include <raylib.h>

#define RAYGUI_IMPLEMENTATION // only define once
#define RAYGUI_CUSTOM_ICONS     // Custom icons set required 
#include "../resources/sndIcons.rgi.h"  
#include <raygui.h>

#include "sndConfigs.h" // provide object "config" for configurable parameters
#include "sndGlobals.h" // provide object "global" for not configurable application parameters
#include "sndScenes.h"
#define BENCHMARK_IMPLEMENTATION
#include "sndBenchmark.h"

int main()
{
    // Initialization
    //---------------------------------
    const int screenWidth = 800;
    const int screenHeight = 650;


    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_WINDOW_TRANSPARENT);

    InitWindow(screenWidth, screenHeight, "Conway's Game of Life");

    SetTargetFPS(config.targetFPS);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
    SetExitKey(0);

    Image icon = LoadImage("resources/favicon.ico");
    ImageFormat(&icon, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
    SetWindowIcon(icon);
    //---------------------------------

    Menu menu;
    Settings settings;
    Game game;

    // Main app loop
    //---------------------------------
    while (!WindowShouldClose() && !global.exitApp) // Detect window close button or ESC key
    {
        if(IsWindowResized())
        {
            menu.Initialize();
            settings.Initialize();
            game.Initialize();
        }
    
        switch (currentScene)
        {
        case MENU:
            menu.Update();
            break;

        case GAME:
            game.Update();
            break;

        case SETTINGS:
            settings.Update();
            break;

        default:
            break;
        }
        ShowBenchmarks();
    }
    //---------------------------------

    // De-Initialization
    //---------------------------------
    UnloadImage(icon);

    CloseWindow(); // Close window and OpenGL context
    //---------------------------------

    return 0;
}
