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

    //menubar->SetMargin(2);
    //menubar->SetBorder(6);
    //menubar->SetPadding(2);

    std::shared_ptr<sndWrapper> statusbar(new sndWrapper(
        "statusbar",
        main.GetInnerLeft(),
        static_cast<int>(main.GetInnerBottom() - (2 * global.guiButtonBaseHeight + 2 * main.GetFrameWeight())),
        main.GetInnerRight(),
        main.GetInnerBottom()));

    //statusbar->SetMargin(2);
    //statusbar->SetBorder(6);
    //statusbar->SetPadding(2);

    std::shared_ptr<sndWrapper> title(new sndWrapper(
        "title",
        main.GetInnerLeft(),
        menubar->GetOuterBottom(),
        main.GetInnerRight(),
        statusbar->GetOuterTop() / 3));

    //title->SetMargin(2);
    //title->SetBorder(6);
    //title->SetPadding(2);

    std::shared_ptr<sndWrapper> content(new sndWrapper(
        "content",
        main.GetInnerLeft(),
        title->GetOuterBottom(),
        main.GetInnerRight(),
        statusbar->GetOuterTop()));

    content->SetBorder(3);
    //---------------------------------

    // GUI-Elements
    //---------------------------------
    std::shared_ptr<sndButton> darkMode(new sndButton(
        "Darkmode",
        []()
        {
            global.ToggleDarkMode();
        },
        menubar,
        (sndAlign)(RIGHT | CENTER_VERTICAL),
        0));
    menubar->AddWrapper(darkMode);

    std::shared_ptr<sndButton> start(new sndButton(
        "Start",
        []()
        {
            currentScene = GAME;
        },
        content,
        (sndAlign)(CENTER_HORIZONTAL | CENTER_VERTICAL),
        0));
    content->AddWrapper(start);

    std::shared_ptr<sndButton> settings(new sndButton(
        "Settings",
        []()
        {
            currentScene = SETTINGS;
        },
        content,
        (sndAlign)(CENTER_HORIZONTAL | CENTER_VERTICAL),
        0));
    settings->AttachToBottom(start);
    start->AddWrapper(settings);

    std::shared_ptr<sndButton> exit(new sndButton(
        "Exit",
        []()
        {
            global.exitApp = true;
        },
        content,
        (sndAlign)(CENTER_HORIZONTAL | CENTER_VERTICAL),
        0));
    exit->AttachToBottom(settings);
    content->AddWrapper(exit);
    //---------------------------------

    // LAST STEP: ADD ELEMENTS AND WRAPPERS (REVERSED!)
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
