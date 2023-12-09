#define TRACY_ENABLE
#include "Configs.h" // provide object "config" for configurable parameters
#include "Globals.h" // provide object "global" for not configurable application parameters
#include "Scenes.h"
#define RAYGUI_IMPLEMENTATION // only define once
#define RAYGUI_CUSTOM_ICONS   // Custom icons set required
#include "../resources/iconset.rgi.h"
#include "external/raygui.h"
#include <iostream>
#include <raylib.h>

int main(/* int argc, char **argv */)
{
    // Initialization
    //---------------------------------
    const int screenWidth = 0;  // 450;
    const int screenHeight = 0; // 550;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_WINDOW_TRANSPARENT);
    SetConfigFlags(FLAG_WINDOW_MAXIMIZED);
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);

    InitWindow(screenWidth, screenHeight, "Conway's Game of Life");

    SetTargetFPS(config.targetFPS);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
    SetExitKey(0);
    GuiSetIconScale(2);
    //---------------------------------

    Menu menu;
    Settings settings;
    Game game;

    // Main app loop
    //---------------------------------
    while (!WindowShouldClose() && !global.exitApp) // Detect window close button or ESC key
    {
        if (IsWindowResized())
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
    }
    //---------------------------------

    // De-Initialization
    //---------------------------------
    CloseWindow(); // Close window and OpenGL context
    //---------------------------------

    return 0;
}
