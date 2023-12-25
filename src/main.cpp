#include "Configs.h" // provide object "config" for configurable parameters
#include "Globals.h" // provide object "global" for not configurable application parameters
#include "Scenes.h"
#include <cstddef>
#define RAYGUI_IMPLEMENTATION // only define once
#define RAYGUI_CUSTOM_ICONS   // Custom icons set required
#include "../resources/iconset.rgi.h"
#include "raygui.h"
#include "raylib.h"
#include <iostream>

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

Menu* pMenu{nullptr};
Settings* pSettings;
Game* pGame;

void updateGameLoop();
int main(/* int argc, char **argv */)
{
    // Initialization
    //---------------------------------
#ifndef __EMSCRIPTEN__
    constexpr int screenWidth{0};
    constexpr int screenHeight{0};
#else
    const int screenWidth{450};
    const int screenHeight{560};
#endif

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_WINDOW_TRANSPARENT);
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);

    InitWindow(screenWidth, screenHeight, "Conway's Game of Life");

#ifdef __EMSCRIPTEN__
    SetWindowSize(GetRenderWidth() - 50, GetRenderHeight() - 50);
#endif

    SetTargetFPS(config.targetFPS);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
    SetExitKey(0);
    GuiSetIconScale(2);
    //---------------------------------

    // Initialize scenes
    Menu menu;
    pMenu = &menu;
    Settings settings;
    pSettings = &settings;
    Game game;
    pGame = &game;

    // Main app loop
    //=================================
#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(updateGameLoop, 145, 1);
#else
    while (!WindowShouldClose() && !global.exitApp) // Detect window close button or ESC key
    {
        updateGameLoop();
    }
#endif
    //---------------------------------

    // De-Initialization
    //---------------------------------
    CloseWindow(); // Close window and OpenGL context
    //---------------------------------

    return 0;
}

void updateGameLoop()
{
    if (IsWindowResized())
    {
        pMenu->Initialize();
        pSettings->Initialize();
        pGame->Initialize();
    }

    switch (currentScene)
    {
    case MENU:
        pMenu->Update();
        break;

    case GAME:
        pGame->Update();
        break;

    case SETTINGS:
        pSettings->Update();
        break;

    default:
        break;
    }
}