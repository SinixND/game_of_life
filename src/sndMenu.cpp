#include "sndMenu.h"

#include "sndLayout.h"
#include <raygui.h>
#include <raylib.h>

#include "sndConfigs.h" // provide object "config" for configurable parameters
#include "sndGlobals.h" // provide object "global" for not configurable application parameters

Menu::Menu()
    : mainframe(0.0f, 0.0f, static_cast<float>(GetRenderWidth()), static_cast<float>(GetRenderHeight()))
    , mainpanel(mainframe.GetContentX(), mainframe.GetContentY(), mainframe.GetContentWidth(), mainframe.GetContentHeight())
{
    mainframe.SetMargin(15);
    mainframe.SetBorder(10);
    mainframe.SetPadding(5);

    mainpanel.SetMargin(15);
    mainpanel.SetBorder(10);
    mainpanel.SetPadding(5);
};


void Menu::Process() {}
void Menu::Update() {}
void Menu::Render() {
    mainframe.Render();
    mainpanel.Render();
};
