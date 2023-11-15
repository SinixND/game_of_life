#include <cmath>
#define RAYGUI_CUSTOM_ICONS     // Custom icons set required 
#include "../resources/sndIcons.rgi.h"  
#include <raygui.h>
#include <iostream>

#include "sndConfigs.h"
#include "sndGlobals.h"
#include "sndGrid.h"
#include "sndLayout.h"
#include "sndScenes.h"

// GAME OF LIFE / GRID
//---------------------------------
bool pauseState = false;
bool singleIteration = false;

bool gameScreenInitialized = false;
float timePassed = 0;

int rowsY;
int colsX;
Grid grid;

Game::Game()
{
    Initialize();
}

void Game::Initialize()
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

    statusbar = std::make_shared<sndWrapper>(
        "statusbar",
        main->GetInnerLeft(),
        static_cast<int>(main->GetInnerBottom() - 3 * GuiGetStyle(DEFAULT, TEXT_SIZE)),
        main->GetInnerRight(),
        main->GetInnerBottom());

    main->AddWrapper(statusbar);

    body = std::make_shared<sndWrapper>(
        "body",
        main->GetInnerLeft(),
        menubar->GetOuterBottom(),
        main->GetInnerRight(),
        statusbar->GetOuterTop());

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

    auto back = std::make_shared<sndButton>(
        "Back",
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        [](){return IsKeyPressed(KEY_BACK) || IsKeyPressed(KEY_BACKSPACE);},
        []()
        {
            gameScreenInitialized = false;
            currentScene = MENU;
        },
        menubar.get(),
        (sndAlign)(LEFT | CENTER_VERTICAL),
        0);

    menubar->AddWrapper(back);

    auto reset = std::make_shared<sndButton>(
        "Reset",
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        [](){return false;},
        []()
        {
            grid.Reset();
        },
        menubar.get(),
        (sndAlign)(LEFT | CENTER_VERTICAL),
        0);

    reset->AttachToRight(back.get());
    menubar->AddWrapper(reset);

    auto clear = std::make_shared<sndButton>(
        "Clear",
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        [](){return false;},
        []()
        {
            grid.Clear();
        },
        menubar.get(),
        (sndAlign)(LEFT | CENTER_VERTICAL),
        0);

    clear->AttachToRight(reset.get());
    menubar->AddWrapper(clear);

    auto pause = std::make_shared<sndButton>(
        "Pause",
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        [](){return IsKeyPressed(KEY_P);},
        []()
        {
            pauseState = !pauseState;
        },
        menubar.get(),
        (sndAlign)(CENTER_HORIZONTAL | CENTER_VERTICAL),
        0);

    menubar->AddWrapper(pause);

    auto increaseTicks = std::make_shared<sndButton>(
        GuiIconText(ICON_ARROW_UP_FILL, ""),
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        [](){return IsKeyPressed(KEY_UP);},
        []()
        {
            config.tickTime /= 2;
            if (config.tickTime < (static_cast<float>(1) / 128)) // max FPS supported as per tick time
            {
                config.tickTime = (static_cast<float>(1) / 128); // = 1s / 2^7
            }
        },
        statusbar.get(),
        (sndAlign)(RIGHT | CENTER_VERTICAL),
        0);

    statusbar->AddWrapper(increaseTicks);

    auto decreaseTicks = std::make_shared<sndButton>(
        GuiIconText(ICON_ARROW_DOWN_FILL, ""),
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        [](){return IsKeyPressed(KEY_DOWN);},
        []()
        {
            config.tickTime *= 2;
            if (config.tickTime > 8)
            {
                config.tickTime = 8;
            }
        },
        statusbar.get(),
        (sndAlign)(RIGHT | CENTER_VERTICAL),
        0);

    decreaseTicks->AttachToLeft(increaseTicks.get());
    statusbar->AddWrapper(decreaseTicks);

    auto undo = std::make_shared<sndButton>(
        GuiIconText(ICON_UNDO_FILL, ""),
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        [](){return ((IsKeyPressed(KEY_LEFT_CONTROL) || IsKeyPressed(KEY_RIGHT_CONTROL)) && IsKeyPressed(KEY_Z));},
        []()
        {
            std::cout << "Implement undo!\n";
        },
        statusbar.get(),
        (sndAlign)(CENTER_HORIZONTAL | CENTER_VERTICAL),
        0);

    statusbar->AddWrapper(undo);

    auto step = std::make_shared<sndButton>(
        GuiIconText(ICON_PLAYER_NEXT, ""),
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        [](){return IsKeyPressed(KEY_RIGHT);},
        []()
        {
            singleIteration = true;
        },
        statusbar.get(),
        (sndAlign)(CENTER_HORIZONTAL | CENTER_VERTICAL),
        0);

    step->AttachToRight(undo.get());
    statusbar->AddWrapper(step);
    //---------------------------------

    // Variables
    //---------------------------------
    rowsY = body->GetInnerHeight() / (config.agentHeight + config.agentGap);
    colsX = body->GetInnerWidth() / (config.agentWidth + config.agentGap);
    grid.SetGridSize(colsX, rowsY);
    grid.Reset();
    //---------------------------------
}

void Game::Update()
{
    ProcessInput();
    UpdateState();

    BeginDrawing();
    ClearBackground(global.GetBackground());

    RenderOutput();

    EndDrawing();
}

void Game::ProcessInput()
{
    // Draw agents manually
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
    {
        Vector2 mousePosition = GetMousePosition();

        int targetRowY = floor((mousePosition.y - AlignVerticalCenter(body.get(), (rowsY * (config.agentHeight + config.agentGap) - config.agentGap), 0)) / (config.agentHeight + config.agentGap));
        int targetColX = floor((mousePosition.x - AlignHorizontalCenter(body.get(), (colsX * (config.agentWidth + config.agentGap) - config.agentGap), 0)) / (config.agentWidth + config.agentGap));

        if ((targetRowY < 0 || targetRowY >= rowsY) || (targetColX < 0 || targetColX >= colsX))
        {
            // do nothing
        }
        else if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            Agent& agent = grid.GetGrid()[targetRowY][targetColX];
            agent.SetStatusCurrent(true);
            agent.SetStatusNext(true);
            grid.NotifyAdjacentAgents(agent);
            if (config.fadingAgents == true)
            {
                agent.RefreshVitality();
            }
        }
        else if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            Agent& agent = grid.GetGrid()[targetRowY][targetColX];
            agent.SetStatusCurrent(false);
            agent.SetStatusNext(false);
            grid.NotifyAdjacentAgents(agent);
            agent.EreaseVitality();
        }
    }
}

void Game::UpdateState()
{
    if (gameScreenInitialized == false)
    {
        Initialize();
        gameScreenInitialized = true;
    }

    if (pauseState == true && singleIteration == false)
    {
        return;
    }

    if (timePassed <= config.tickTime)
    {
        timePassed += GetFrameTime();
        return;
    }

    timePassed = 0;
    grid.Evolve();
    int currentState = grid.gridStates_.size() - 1;
    singleIteration = false;
}

void Game::RenderOutput()
{
    main->Render();

    RenderScreenGameStatusbar();
    RenderScreenGameMainPanel();

    if (pauseState == true && singleIteration == false)
    {
        RenderPauseOverlay();
    }

    Scene::RenderOutput();
}

void Game::RenderScreenGameStatusbar()
{
    auto status = std::make_shared<sndText>(
        TextFormat("%.0f(%0.f)ms; Day: %i",(static_cast<float>(1000)/GetFPS()), config.tickTime * 1000,  grid.GetDay()),
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        statusbar.get(),
        (sndAlign)(LEFT | CENTER_VERTICAL),
        0);
    status->Render();
}

Color GetAgentColor(Agent agent);

void Game::RenderScreenGameMainPanel()
{
    // draw agents
    for (auto& row : grid.GetGrid())
    {
        for (auto& agent : row)
        {
            int anchorX = AlignHorizontalCenter(body.get(), (colsX * (config.agentWidth + config.agentGap) - config.agentGap), 0) + (agent.GetColX() * (config.agentWidth + config.agentGap));
            int anchorY = AlignVerticalCenter(body.get(), (rowsY * (config.agentHeight + config.agentGap) - config.agentGap), 0) + (agent.GetRowY() * (config.agentHeight + config.agentGap));

            Rectangle rectAgent{
                (float)anchorX,
                (float)anchorY,
                (float)config.agentWidth,
                (float)config.agentHeight};

            if (agent.GetStatusCurrent() == true)
            {
                DrawRectangleRec(rectAgent, global.GetForeground());
            }
            else if (agent.GetVitality() > 0)
            {
                DrawRectangleRec(rectAgent, GetAgentColor(agent));
            }
            else
            {
                DrawRectangleLinesEx(rectAgent, config.agentInnerBorderWeight, Fade(global.GetForeground(), 0.50f));
            }

            if (config.debugMode == true && CheckCollisionPointRec(GetMousePosition(), rectAgent))
            {
                DrawText(TextFormat("%i/%i\nC:%i N:%i O:%i\nV:%i",
                    agent.GetColX(),
                    agent.GetRowY(),
                    agent.GetStatusCurrent(),
                    agent.GetStatusNext(),
                    agent.GetStatusOutdated(),
                    agent.GetVitality()
                ), anchorX + 5, anchorY, 10, RED);
            }
        }
    }
}

Color GetAgentColor(Agent agent)
{
    Color AgentColor = Fade(global.GetForeground(), (agent.GetVitality() * (1.0f / agent.GetMaxVitality())));
    return AgentColor;
}

void Game::RenderPauseOverlay()
{
    // Draw overlay Frame
    Rectangle rectpanelMainScreenGame{
        static_cast<float>(body->GetOuterLeft()),
        static_cast<float>(body->GetOuterTop()),
        static_cast<float>(body->GetOuterWidth()),
        static_cast<float>(body->GetOuterHeight())};

    DrawRectangleLinesEx(rectpanelMainScreenGame, 10, Fade(global.GetForeground(), 0.75f));

    auto paused = std::make_shared<sndText>(
        "[P]aused...",
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        statusbar.get(),
        (sndAlign)(RIGHT | CENTER_VERTICAL),
        0);

    paused->Render();
}
