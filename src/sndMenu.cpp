#include "sndMenu.h"

#include "sndLayout.h"
#include <raylib.h>
#include <raygui.h>

#include "sndConfigs.h" // provide object "config" for configurable parameters
#include "sndGlobals.h" // provide object "global" for not configurable application parameters

const char* textDarkMode;

Menu::Menu()
    : main(
          0.0f,
          0.0f,
          static_cast<float>(GetRenderWidth()),
          static_cast<float>(GetRenderHeight()))
    , menubar(
          main.GetContentLeft(),
          main.GetContentTop(),
          main.GetContentRight(),
          main.GetContentTop() + global.guiButtonBaseHeight + 2 * main.GetFrameWeight())
    , statusbar(
          main.GetContentLeft(),
          main.GetContentBottom() - (global.guiButtonBaseHeight + 2 * main.GetFrameWeight()),
          main.GetContentRight(),
          main.GetContentBottom())
    , content(
          main.GetContentLeft(),
          menubar.GetMarginBottom(),
          main.GetContentRight(),
          statusbar.GetMarginTop())
{
    main.AddWrapper(menubar);
    main.AddWrapper(statusbar);
    main.AddWrapper(content);
    menubar.SetMargin(2);
    menubar.SetBorder(2);
    menubar.SetPadding(2);
    statusbar.SetMargin(2);
    statusbar.SetBorder(2);
    statusbar.SetPadding(2);
    content.SetMargin(2);
    content.SetBorder(2);
    content.SetPadding(2);
}

void Menu::Process() {}
void Menu::Update() {}
void Menu::Render()
{
    main.Render();
    menubar.AddButton("DarkMode", global.textSizeDefault, (AlignFlags)(LEFT | TOP), 0);
}
