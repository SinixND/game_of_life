#include "sndGlobals.h"
#include "sndLayout.h"
#include "sndScenes.h"

Menu::Menu()
{
    Initialize();
}

void Menu::Initialize()
{
    // Wrappers
    //---------------------------------
    main.SetOuterLeft(0);
    main.SetOuterTop(0);
    main.SetOuterRight(GetRenderWidth());
    main.SetOuterBottom(GetRenderHeight());

    sndWrapper menubar(
        main.GetInnerLeft(),
        main.GetInnerTop(),
        main.GetInnerRight(),
        static_cast<int>(main.GetInnerTop() + global.guiButtonBaseHeight + 2 * main.GetFrameWeight()));

    sndWrapper statusbar(
        main.GetInnerLeft(),
        static_cast<int>(main.GetInnerBottom() - (global.guiButtonBaseHeight + 2 * main.GetFrameWeight())),
        main.GetInnerRight(),
        main.GetInnerBottom());

    sndWrapper title(
        main.GetInnerLeft(),
        menubar.GetOuterBottom(),
        main.GetInnerRight(),
        statusbar.GetOuterTop() / 3);

    sndWrapper content(
        main.GetInnerLeft(),
        title.GetOuterBottom(),
        main.GetInnerRight(),
        statusbar.GetOuterTop());

    menubar.SetMargin(2);
    menubar.SetBorder(6);
    menubar.SetPadding(2);
    statusbar.SetMargin(2);
    statusbar.SetBorder(6);
    statusbar.SetPadding(2);
    title.SetMargin(2);
    title.SetBorder(6);
    title.SetPadding(2);

    main.ClearWrappers();
    main.AddWrapper(menubar);
    main.AddWrapper(statusbar);
    main.AddWrapper(title);
    main.AddWrapper(content);
    //---------------------------------

    // GUI-Elements
    //---------------------------------
    menubar.AddButton(menubar.GetInnerLeft(), menubar.GetInnerTop(), "Darkmode", []()->void{global.ToggleDarkMode();});
    //if (GuiButton(
            //(Rectangle){
                //(float)AlignHorizontalRight(menubar, buttonDarkModeWidth, 0),
                //(float)AlignVerticalCenter(menubarScreenMenu, global.guiButtonBaseHeight, 0),
                //(float)buttonDarkModeWidth,
                //(float)global.guiButtonBaseHeight},
            //txtButtonDarkModeScreenMenu))
    //{
        //global.ToggleDarkMode();
    //};
    //---------------------------------
}

void Menu::Input() {}
void Menu::Process() {}
void Menu::Output()
{
    main.Render();
    // sndButton darkMode("DarkMode", global.textSizeDefault);
    // menubar.Append(darkMode, (sndAlign)(CENTER_HORIZONTAL | CENTER_VERTICAL), 0);
}
