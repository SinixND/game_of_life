#include "screens.h"

#include <raylib.h>
#include <raygui.h>
#include "sndlayout.h"

#include "configs.h" // provide object "config" for configurable parameters
#include "globals.h" // provide object "global" for not configurable application parameters


Screen menu;

menu.Initialize()
{
    snd::Frame main;
};

void ProcessMenu();
void UpdateMenu();
void RenderMenu();

void Screen::Run()
{
    ProcessMenu();
    UpdateMenu();
    RenderMenu();
}

void ProcessMenu(){};

void UpdateMenu()
{
};

void RenderMenu()
{
    BeginDrawing();
    ClearBackground(global.GetColorBackground());

    EndDrawing();
}
