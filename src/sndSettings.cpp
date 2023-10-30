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
    auto menubar = std::make_shared<sndWrapper>(
        "menubar",
        main->GetInnerLeft(),
        main->GetInnerTop(),
        main->GetInnerRight(),
        static_cast<int>(main->GetInnerTop() + 2 * global.guiButtonBaseHeight + 2 * main->GetFrameWeight()));

    main->AddWrapper(menubar);

    auto content = std::make_shared<sndWrapper>(
        "content",
        main->GetInnerLeft(),
        menubar->GetOuterBottom(),
        main->GetInnerRight(),
        main->GetInnerBottom());

    main->AddWrapper(content);
    //---------------------------------

    // GUI-Elements
    //---------------------------------
    auto settings = std::make_shared<sndLabel>(
        "Settings",
        menubar.get(),
        (sndAlign)(CENTER_HORIZONTAL | CENTER_VERTICAL),
        0);

    menubar->AddWrapper(settings);

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

    auto back = std::make_shared<sndButton>(
        "Back",
        []()
        {
            currentScene = MENU;
        },
        menubar.get(),
        (sndAlign)(LEFT | CENTER_VERTICAL),
        0);

    menubar->AddWrapper(back);

    auto category1ST = std::make_shared<sndSeparator>(
        "Separator",
        content->GetInnerLeft(),
        content->GetInnerRight(),
        content.get(),
        (sndAlign)(TOP | CENTER_VERTICAL),
        0);

    content->AddWrapper(category1ST);

    auto category1 = std::make_shared<sndLabel>(
        "Category 1",
        content.get(),
        (sndAlign)(CENTER_HORIZONTAL | CENTER_VERTICAL),
        0);

    category1->AttachToBottom(category1ST.get());
    content->AddWrapper(category1);

    auto category1SB = std::make_shared<sndSeparator>(
        "Separator",
        content->GetInnerLeft(),
        content->GetInnerRight(),
        content.get(),
        (sndAlign)(TOP | CENTER_VERTICAL),
        0);

    category1SB->AttachToBottom(category1.get());
    content->AddWrapper(category1SB);
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