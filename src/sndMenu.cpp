#include "sndMenu.h"

#include "sndLayout.h"
#include <raylib.h>
#include <raygui.h>

#include "sndConfigs.h" // provide object "config" for configurable parameters
#include "sndGlobals.h" // provide object "global" for not configurable application parameters

const char* textDarkMode;

Menu::Menu()
    : main(
      "main",
          0,
          0,
          GetRenderWidth(),
          GetRenderHeight())
    , menubar(
      "menubar",
          main.GetInnerLeft(),
          main.GetInnerTop(),
          main.GetInnerRight(),
          static_cast<int>(main.GetInnerTop() + global.guiButtonBaseHeight + 2 * main.GetFrameWeight()))
    , statusbar(
      "statusbar",
          main.GetInnerLeft(),
          static_cast<int>(main.GetInnerBottom() - (global.guiButtonBaseHeight + 2 * main.GetFrameWeight())),
          main.GetInnerRight(),
          main.GetInnerBottom())
    , title(
      "title",
          main.GetInnerLeft(),
          menubar.GetOuterBottom(),
          main.GetInnerRight(),
          statusbar.GetOuterTop() / 2)
    , menu(
      "menu",
          main.GetInnerLeft(),
          title.GetOuterBottom(),
          main.GetInnerRight(),
          statusbar.GetOuterTop())
{
    menubar.SetMargin(2);
    menubar.SetBorder(2);
    menubar.SetPadding(2);
    statusbar.SetMargin(2);
    statusbar.SetBorder(2);
    statusbar.SetPadding(2);
    title.SetMargin(2);
    title.SetBorder(2);
    title.SetPadding(2);

    main.AddWrapper(menubar);
    main.AddWrapper(statusbar);
    main.AddWrapper(title);
    main.AddWrapper(menu);
}

void Menu::Input() {}
void Menu::Process() {}
void Menu::Output()
{
    main.Render();
    //sndButton darkMode("DarkMode", global.textSizeDefault);
    //menubar.Append(darkMode, (sndAlign)(CENTER_HORIZONTAL | CENTER_VERTICAL), 0);
}
