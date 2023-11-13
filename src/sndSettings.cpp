#define RAYGUI_CUSTOM_ICONS // Custom icons set required
#include "../resources/sndIcons.rgi.h"
#include <raygui.h>

#include "sndConfigs.h"
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
        static_cast<int>(main->GetInnerTop() + 4 * GuiGetStyle(DEFAULT, TEXT_SIZE)));

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
        []()
        { return false; },
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
        []()
        { return false; },
        []()
        {
            global.ToggleDarkMode();
        },
        menubar.get(),
        (sndAlign)(RIGHT | CENTER_VERTICAL),
        0);

    menubar->AddWrapper(darkMode);

    auto displaySettings = std::make_shared<sndSeparator>(
        "Display",
        body->GetInnerLeft(),
        body->GetInnerRight(),
        body.get(),
        (sndAlign)(CENTER_HORIZONTAL | TOP),
        0);

    body->AddWrapper(displaySettings);

    auto windowSize = std::make_shared<sndDropdownBox>(
        "Dropdown",
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        "one;two;three",
        &config.windowSize,
        false,
        body.get(),
        (sndAlign)(BOTTOM | RIGHT),
        0);

    body->AddWrapper(windowSize);

        auto drawFPS = std::make_shared<sndCheckBox>(
            "Draw FPS",
            GuiGetStyle(DEFAULT, TEXT_SIZE),
            &config.drawFPS,
            body.get(),
            (sndAlign)(LEFT | TOP),
            0);

    drawFPS->AttachToBottom(displaySettings.get());
    body->AddWrapper(drawFPS);

    auto gridSettings = std::make_shared<sndSeparator>(
        "Grid",
        body->GetInnerLeft(),
        body->GetInnerRight(),
        body.get(),
        (sndAlign)(CENTER_HORIZONTAL | TOP),
        0);

    gridSettings->AttachToBottom(drawFPS.get());
    body->AddWrapper(gridSettings);

    auto initialLifeDensity = std::make_shared<sndSpinner>(
        "Life density",
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        &config.initialLifeDensity,
        0,
        100,
        false,
        body.get(),
        (sndAlign)(LEFT | TOP),
        0);

    initialLifeDensity->AttachToBottom(gridSettings.get());
    body->AddWrapper(initialLifeDensity);

    auto agentSettings = std::make_shared<sndSeparator>(
        "Cells",
        body->GetInnerLeft(),
        body->GetInnerRight(),
        body.get(),
        (sndAlign)(CENTER_HORIZONTAL | TOP),
        0);

    agentSettings->AttachToBottom(initialLifeDensity.get());
    body->AddWrapper(agentSettings);

    auto fadingAgents = std::make_shared<sndCheckBox>(
        "Fading cells",
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        &config.fadingAgents,
        body.get(),
        (sndAlign)(LEFT | TOP),
        0);

    fadingAgents->AttachToBottom(agentSettings.get());
    body->AddWrapper(fadingAgents);

    auto agentWidth = std::make_shared<sndSpinner>(
        "Cell width",
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        &config.agentWidth,
        2 * config.agentInnerBorderWeight + 1,
        100,
        false,
        body.get(),
        (sndAlign)(LEFT | TOP),
        0);

    agentWidth->AttachToBottom(fadingAgents.get());
    body->AddWrapper(agentWidth);

    auto agentHeight = std::make_shared<sndSpinner>(
        "Cell height",
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        &config.agentHeight,
        2 * config.agentInnerBorderWeight + 1,
        100,
        false,
        body.get(),
        (sndAlign)(LEFT | TOP),
        0);

    agentHeight->AttachToBottom(agentWidth.get());
    body->AddWrapper(agentHeight);

    auto agentGap = std::make_shared<sndSpinner>(
        "Cell gap",
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        &config.agentGap,
        0,
        1000,
        false,
        body.get(),
        (sndAlign)(LEFT | TOP),
        0);

    agentGap->AttachToBottom(agentHeight.get());
    body->AddWrapper(agentGap);
    //---------------------------------
}

void Settings::Update()
{
    ProcessInput();
    UpdateState();

    BeginDrawing();
    ClearBackground(global.GetBackground());

    RenderOutput();

    EndDrawing();
}

void Settings::ProcessInput() {}
void Settings::UpdateState()
{
}
void Settings::RenderOutput()
{
    main->Render();
    Scene::RenderOutput();
}