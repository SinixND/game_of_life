#include "sndMenu.h"

#include "sndLayout.h"
#include <raylib.h>
#include <raygui.h>

#include "sndConfigs.h" // provide object "config" for configurable parameters
#include "sndGlobals.h" // provide object "global" for not configurable application parameters

const char* textDarkMode;

Menu::Menu()
    : main(
          0,
          0,
          static_cast<float>(GetRenderWidth()),
          static_cast<float>(GetRenderHeight()))
    , menubar(
          main.GetInnerLeft(),
          main.GetInnerTop(),
          main.GetInnerRight(),
          main.GetInnerTop() + global.guiButtonBaseHeight + 2 * main.GetFrameWeight())
    , statusbar(
          main.GetInnerLeft(),
          main.GetInnerBottom() - (global.guiButtonBaseHeight + 2 * main.GetFrameWeight()),
          main.GetInnerRight(),
          main.GetInnerBottom())
    , title(
          main.GetInnerLeft(),
          menubar.GetOuterBottom(),
          main.GetInnerRight(),
          0.5 * statusbar.GetOuterTop())
    , menu(
          main.GetInnerLeft(),
          title.GetOuterBottom(),
          main.GetInnerRight(),
          statusbar.GetOuterTop())
{
    main.AddWrapper(menubar);
    main.AddWrapper(statusbar);
    main.AddWrapper(title);
    main.AddWrapper(menu);
    menubar.SetMargin(2);
    menubar.SetBorder(2);
    menubar.SetPadding(2);
    statusbar.SetMargin(2);
    statusbar.SetBorder(2);
    statusbar.SetPadding(2);
    title.SetMargin(2);
    title.SetBorder(2);
    title.SetPadding(2);
}

void Menu::Process() {}
void Menu::Update() {}
void Menu::Render()
{
    main.Render();
    sndButton darkMode("DarkMode", global.textSizeDefault);
    menubar.Append(darkMode, (sndAlign)(CENTER_HORIZONTAL | CENTER_VERTICAL), 0);
}
