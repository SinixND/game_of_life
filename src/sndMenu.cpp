#include "sndMenu.h"

#include "sndLayout.h"
#include <raygui.h>
#include <raylib.h>

#include "sndConfigs.h" // provide object "config" for configurable parameters
#include "sndGlobals.h" // provide object "global" for not configurable application parameters

Menu::Menu()
    : mainframe(0.0f, 0.0f, static_cast<float>(GetRenderWidth()), static_cast<float>(GetRenderHeight()))
    , mainpanel(mainframe.x_, mainframe.y_, mainframe.width_, mainframe.height_)
{
    mainframe.SetMargin(10);
    mainframe.SetBorder(10);

    mainpanel.SetMargin(5);
    mainpanel.SetBorder(5);
};


void Menu::Process() {}
void Menu::Update() {}
void Menu::Render() {
    mainframe.RenderBox();
    mainpanel.RenderBox();
};
