#include "sndMenu.h"

#include "sndLayout.h"
#include <raygui.h>
#include <raylib.h>

#include "sndConfigs.h" // provide object "config" for configurable parameters
#include "sndGlobals.h" // provide object "global" for not configurable application parameters

Menu::Menu()
    : mainframe(0, 0, (float)config.windowWidth, (float)config.windowHeight)
{
    mainframe.SetMargin(10);
    mainframe.SetBorder(10);
};


void Menu::Process() {}
void Menu::Update() {}
void Menu::Render() {
    mainframe.RenderFrame();
}