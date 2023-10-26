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
    main.ClearWrappers();

    main.ResizeOuterLeft(0);
    main.ResizeOuterTop(0);
    main.ResizeOuterRight(GetRenderWidth());
    main.ResizeOuterBottom(GetRenderHeight());

    std::shared_ptr<sndWrapper> menubar(new sndWrapper(
        "menubar",
        main.GetInnerLeft(),
        main.GetInnerTop(),
        main.GetInnerRight(),
        static_cast<int>(main.GetInnerTop() + 2 * global.guiButtonBaseHeight + 2 * main.GetFrameWeight())));

    std::shared_ptr<sndWrapper> statusbar(new sndWrapper(
        "statusbar",
        main.GetInnerLeft(),
        static_cast<int>(main.GetInnerBottom() - (2 * global.guiButtonBaseHeight + 2 * main.GetFrameWeight())),
        main.GetInnerRight(),
        main.GetInnerBottom()));

    std::shared_ptr<sndWrapper> title(new sndWrapper(
        "title",
        main.GetInnerLeft(),
        menubar->GetOuterBottom(),
        main.GetInnerRight(),
        statusbar->GetOuterTop() / 3));

    std::shared_ptr<sndWrapper> content(new sndWrapper(
        "content",
        main.GetInnerLeft(),
        title->GetOuterBottom(),
        main.GetInnerRight(),
        statusbar->GetOuterTop()));

    menubar->SetMargin(2);
    menubar->SetBorder(6);
    menubar->SetPadding(2);
    statusbar->SetMargin(2);
    statusbar->SetBorder(6);
    statusbar->SetPadding(2);
    title->SetMargin(2);
    title->SetBorder(6);
    title->SetPadding(2);
    //---------------------------------

    // GUI-Elements
    //---------------------------------
    menubar->AddButton(
        "Darkmode",
        []()
        {
            global.ToggleDarkMode();
        },
        (sndAlign)(RIGHT | CENTER_VERTICAL),
        0);
    //---------------------------------

    // LAST STEP: ADD WRAPPERS
    //---------------------------------
    main.AddWrapper(menubar);
    main.AddWrapper(statusbar);
    main.AddWrapper(title);
    main.AddWrapper(content);
    //---------------------------------

}

void Menu::Input() {}
void Menu::Process() {}
void Menu::Output()
{
    main.Render();
}
