#include "sndMenu.h"

#include "sndLayout.h"
#include <raylib.h>
#include <raygui.h>

#include "sndConfigs.h" // provide object "config" for configurable parameters
#include "sndGlobals.h" // provide object "global" for not configurable application parameters

Menu::Menu()
    : menubar(
          main.GetInnerLeft(),
          main.GetInnerTop(),
          main.GetInnerRight(),
          static_cast<int>(main.GetInnerTop() + global.guiButtonBaseHeight + 2 * main.GetFrameWeight()))
    , statusbar(
          main.GetInnerLeft(),
          static_cast<int>(main.GetInnerBottom() - (global.guiButtonBaseHeight + 2 * main.GetFrameWeight())),
          main.GetInnerRight(),
          main.GetInnerBottom())
    , title(
          main.GetInnerLeft(),
          menubar.GetOuterBottom(),
          main.GetInnerRight(),
          statusbar.GetOuterTop() / 2)
    , menu(
          main.GetInnerLeft(),
          title.GetOuterBottom(),
          main.GetInnerRight(),
          statusbar.GetOuterTop())
{
    menubar.SetMargin(1);
    menubar.SetBorder(3);
    menubar.SetPadding(1);
    statusbar.SetMargin(1);
    statusbar.SetBorder(3);
    statusbar.SetPadding(1);
    title.SetMargin(1);
    title.SetBorder(3);
    title.SetPadding(1);

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
