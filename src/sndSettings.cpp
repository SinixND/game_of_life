#define RAYGUI_CUSTOM_ICONS     // Custom icons set required 
#include "../resources/sndIcons.rgi.h"  
#include <raygui.h>

#include "sndGlobals.h"
#include "sndLayout.h"
#include "sndScenes.h"

Settings::Settings()
{
    Initialize();
}

void Settings::Initialize()
{
    Scene::Initialize();

    // Wrappers
    //---------------------------------
    menubar = std::make_shared<sndWrapper>(
        "menubar",
        main->GetInnerLeft(),
        main->GetInnerTop(),
        main->GetInnerRight(),
        static_cast<int>(main->GetInnerTop() + 2 * GuiGetStyle(DEFAULT, TEXT_SIZE)));

    main->AddWrapper(menubar);

    body = std::make_shared<sndWrapper>(
        "body",
        main->GetInnerLeft(),
        menubar->GetOuterBottom(),
        main->GetInnerRight(),
        main->GetInnerBottom());

    main->AddWrapper(body);
    //---------------------------------

    // GUI-Elements
    //---------------------------------
    auto settings = std::make_shared<sndText>(
        "Settings",
        2 * GuiGetStyle(DEFAULT, TEXT_SIZE),
        menubar.get(),
        (sndAlign)(CENTER_HORIZONTAL | CENTER_VERTICAL),
        0);

    menubar->AddWrapper(settings);

    auto back = std::make_shared<sndButton>(
        "Back",
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        [](){return false;},
        []()
        {
            currentScene = MENU;
        },
        menubar.get(),
        (sndAlign)(LEFT | CENTER_VERTICAL),
        0);

    menubar->AddWrapper(back);

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

    auto category1 = std::make_shared<sndSeparator>(
        "Category",
        body->GetInnerLeft(),
        body->GetInnerRight(),
        body.get(),
        (sndAlign)(CENTER_HORIZONTAL | TOP),
        0);

    body->AddWrapper(category1);

    auto fadingAgents = std::make_shared<sndCheckBox>(
        "Fading agents",
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        body.get(),
        (sndAlign)(LEFT | TOP),
        2);

    fadingAgents->AttachToBottom(category1.get());
    body->AddWrapper(fadingAgents);
    //---------------------------------
}

void Settings::Update()
{
    Input();
    Process();

    BeginDrawing();
    ClearBackground(global.GetBackground());

    Output();

    EndDrawing();
}

void Settings::Input() {}
void Settings::Process() {}
void Settings::Output()
{
    main->Render();
}