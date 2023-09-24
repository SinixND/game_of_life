#include "sndMenu.h"

#include "sndLayout.h"
#include <raygui.h>
#include <raylib.h>

#include "sndConfigs.h" // provide object "config" for configurable parameters
#include "sndGlobals.h" // provide object "global" for not configurable application parameters

Menu::Menu()
    : main(0.0f, 0.0f, static_cast<float>(GetRenderWidth()), static_cast<float>(GetRenderHeight()))
    , menubar(main.GetContentLeft(), main.GetContentTop(), main.GetContentRight(), global.guiButtonBaseHeight + main.GetFrameWeight())
{
};


void Menu::Process() {}
void Menu::Update() {}
void Menu::Render() {
    main.Render();
    menubar.Render();
};
