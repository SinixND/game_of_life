#include "sndGlobals.h"
#include "sndLayout.h"
#include "sndScenes.h"
#include <iostream>

Menu::Menu()
{
    Initialize();
}

void Menu::Initialize()
{
    Scene::Initialize();

    // Wrappers
    //---------------------------------
    auto menubar = std::make_shared<sndWrapper>(
        "menubar",
        main->GetInnerLeft(),
        main->GetInnerTop(),
        main->GetInnerRight(),
        static_cast<int>(main->GetInnerTop() + 2 * global.guiButtonBaseHeight + 2 * main->GetFrameWeight()));

    main->AddWrapper(menubar);
    menubar->SetBorder(1);

    auto title = std::make_shared<sndWrapper>(
        "title",
        main->GetInnerLeft(),
        menubar->GetOuterBottom(),
        main->GetInnerRight(),
        (main->GetInnerBottom() - menubar->GetOuterBottom()) / 3);

    main->AddWrapper(title);
    title->SetBorder(1);

    auto content = std::make_shared<sndWrapper>(
        "content",
        main->GetInnerLeft(),
        title->GetOuterBottom(),
        main->GetInnerRight(),
        main->GetInnerBottom());

    main->AddWrapper(content);
    content->SetBorder(1);
    //---------------------------------

    // GUI-Elements
    //---------------------------------
    auto darkMode = std::make_shared<sndButton>(
        "Darkmode",
        []()
        {
            global.ToggleDarkMode();
        },
        menubar.get(),
        (sndAlign)(RIGHT | CENTER_VERTICAL),
        0);

    menubar->AddWrapper(darkMode);

    auto start = std::make_shared<sndButton>(
        "Start",
        []()
        {
            currentScene = GAME;
        },
        content.get(),
        (sndAlign)(CENTER_HORIZONTAL | CENTER_VERTICAL),
        0);

    content->AddWrapper(start);

    auto settings = std::make_shared<sndButton>(
        "Settings",
        []()
        {
            currentScene = SETTINGS;
        },
        content.get(),
        (sndAlign)(CENTER_HORIZONTAL | CENTER_VERTICAL),
        0);

    start->AddWrapper(settings);
    settings->AttachToBottom(start.get());

    auto exit = std::make_shared<sndButton>(
        "Exit",
        []()
        {
            global.exitApp = true;
        },
        content.get(),
        (sndAlign)(CENTER_HORIZONTAL | CENTER_VERTICAL),
        0);

    content->AddWrapper(exit);
    exit->AttachToBottom(settings.get());
    //---------------------------------
}

void Menu::Input() {}
void Menu::Process() {}
void Menu::Output() {}
