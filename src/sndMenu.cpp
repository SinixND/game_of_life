#include <iostream>
#define RAYGUI_CUSTOM_ICONS     // Custom icons set required 
#include "../resources/sndIcons.rgi.h"  
#include <raygui.h>

#include "sndGlobals.h"
#include "sndLayout.h"
#include "sndScenes.h"

Menu::Menu()
{
    Initialize();
}

void Menu::Initialize()
{
    Scene::Initialize();

    // Wrappers
    //---------------------------------
    menubar = std::make_shared<sndWrapper>(
        "menubar",
        main->GetInnerLeft(),
        main->GetInnerTop(),
        main->GetInnerRight(),
        static_cast<int>(main->GetInnerTop() + 3 * GuiGetStyle(DEFAULT, TEXT_SIZE)));

    main->AddWrapper(menubar);

    head = std::make_shared<sndWrapper>(
        "head",
        main->GetInnerLeft(),
        menubar->GetOuterBottom(),
        main->GetInnerRight(),
        (main->GetInnerBottom() - menubar->GetOuterBottom()) / 2);

    main->AddWrapper(head);

    body = std::make_shared<sndWrapper>(
        "body",
        main->GetInnerLeft(),
        head->GetOuterBottom(),
        main->GetInnerRight(),
        main->GetInnerBottom());

    main->AddWrapper(body);
    //---------------------------------

    // GUI-Elements
    //---------------------------------
    auto darkMode = std::make_shared<sndButton>(
        GuiIconText(ICON_DARK_MODE, ""),
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        [](){return false;},
        []()
        {
            global.ToggleDarkMode();
        },
        menubar.get(),
        (sndAlign)(RIGHT | CENTER_VERTICAL),
        0);

    menubar->AddWrapper(darkMode);

    auto jhconway = std::make_shared<sndText>(
        "J. H. Conway",
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        head.get(),
        (sndAlign)(CENTER_HORIZONTAL | CENTER_VERTICAL),
        0);

    head->AddWrapper(jhconway);

    auto gameoflife = std::make_shared<sndText>(
        "Game Of Life",
        2 * GuiGetStyle(DEFAULT, TEXT_SIZE),
        head.get(),
        (sndAlign)(CENTER_HORIZONTAL | CENTER_VERTICAL),
        0);

    gameoflife->AttachToBottom(jhconway.get());
    head->AddWrapper(gameoflife);

    auto start = std::make_shared<sndButton>(
        "Start",
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        [](){return IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_KP_ENTER);},
        []()
        {
            currentScene = GAME;
        },
        body.get(),
        (sndAlign)(CENTER_HORIZONTAL | CENTER_VERTICAL),
        0);

    body->AddWrapper(start);

    auto settings = std::make_shared<sndButton>(
        "Settings",
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        [](){return false;},
        []()
        {
            currentScene = SETTINGS;
        },
        body.get(),
        (sndAlign)(CENTER_HORIZONTAL | CENTER_VERTICAL),
        0);

    start->AddWrapper(settings);
    settings->AttachToBottomAndAlign(start.get());

    auto exit = std::make_shared<sndButton>(
        "Exit",
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        [](){return IsKeyPressed(KEY_ESCAPE);},
        []()
        {
            global.exitApp = true;
        },
        body.get(),
        (sndAlign)(CENTER_HORIZONTAL | CENTER_VERTICAL),
        0);

    body->AddWrapper(exit);
    exit->AttachToBottomAndAlign(settings.get());
    //---------------------------------
}

void Menu::Update()
{
    ProcessInput();
    UpdateState();

    BeginDrawing();
    ClearBackground(global.GetBackground());

    RenderOutput();

    EndDrawing();
}

void Menu::ProcessInput() {}
void Menu::UpdateState() {}
void Menu::RenderOutput()
{
    main->Render();
    Scene::RenderOutput();
}
