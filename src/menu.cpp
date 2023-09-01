#include "menu.h"

#include <raylib.h>
#include <raygui.h>
#include "sndlayout.h"

#include "configs.h" // provide object "config" for configurable parameters
#include "globals.h" // provide object "global" for not configurable application parameters

void Menu::Process(){}
void Menu::Update(){}
void Menu::Render(){}

void Menu::Run()
{
    Process();
    Update();
    Render();
}