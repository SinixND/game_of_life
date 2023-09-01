#include "sndMenu.h"

#include "sndLayout.h"
#include <raygui.h>
#include <raylib.h>

#include "sndConfigs.h" // provide object "config" for configurable parameters
#include "sndGlobals.h" // provide object "global" for not configurable application parameters

void Menu::Process() {}
void Menu::Update() {}
void Menu::Render()
{
    Frame mainFrame;
    global.exitApp(true);
}

void Menu::Run()
{
    Process();
    Update();
    Render();
}