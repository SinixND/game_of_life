#include <iostream>
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION //only define once
//#define RAYGUI_CUSTOM_ICONS     // Custom icons set required 
//#include "../resources/sndSinixND.rgi.h"  
#include <raygui.h>
#include "sndConfigs.h" // provide object "config" for configurable parameters
#include "sndGlobals.h" // provide object "global" for not configurable application parameters
#include "sndScenes.h"
#include "sndBenchmark.h"

int main()
{
    // Initialization
    //---------------------------------
    const int screenWidth = 640;
    const int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "Conway's Game of Life");

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_WINDOW_TRANSPARENT);
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
            StartBenchmark("menu.Update()");
            menu.Update();
            StopBenchmark("menu.Update()");
            break;

        case GAME:
            StartBenchmark("game.Update()");
            game.Update();
            StopBenchmark("game.Update()");
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
    //---------------------------------

    // De-Initialization
    //---------------------------------
    UnloadImage(icon);

    CloseWindow(); // Close window and OpenGL context
    //---------------------------------

    return 0;
}
