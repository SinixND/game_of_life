#include "sndScenes.h"

#include "sndConfigs.h"
#include "sndGlobals.h"
#include "sndGrid.h"
#include "sndLayout.h"
#define RAYGUI_CUSTOM_ICONS     // Custom icons set required 
#include "../resources/iconset.rgi.h"  
#include <raygui.h>
#include <cmath>
#include <iostream>


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
    menubar = std::make_shared<sxd::Wrapper>(
        "menubar",
        main->GetInnerLeft(),
        main->GetInnerTop(),
        main->GetInnerRight(),
        static_cast<int>(main->GetInnerTop() + 4 * GuiGetStyle(DEFAULT, TEXT_SIZE)));

    main->AddWrapper(menubar);

    controlbar = std::make_shared<sxd::Wrapper>(
        "controlbar",
        main->GetInnerLeft(),
        static_cast<int>(main->GetInnerBottom() - 4 * GuiGetStyle(DEFAULT, TEXT_SIZE)),
        main->GetInnerRight(),
        main->GetInnerBottom());

    main->AddWrapper(controlbar);

    statusbar = std::make_shared<sxd::Wrapper>(
        "statusbar",
        main->GetInnerLeft(),
        static_cast<int>(controlbar->GetOuterTop() - 3 * GuiGetStyle(DEFAULT, TEXT_SIZE)),
        main->GetInnerRight(),
        controlbar->GetOuterTop());

    main->AddWrapper(statusbar);

    body = std::make_shared<sxd::Wrapper>(
        "body",
        main->GetInnerLeft(),
        menubar->GetOuterBottom(),
        main->GetInnerRight(),
        statusbar->GetOuterTop());

    main->AddWrapper(body);
    //---------------------------------

    // GUI-Elements
    //---------------------------------
    auto darkMode = std::make_shared<sxd::Button>(
        GuiIconText(ICON_DARK_MODE, ""),
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        [](){return false;},
        []()
        {
            global.ToggleDarkMode();
        },
        menubar.get(),
        (sxd::Align)(sxd::RIGHT | sxd::CENTER_VERTICAL),
        0);

    menubar->AddWrapper(darkMode);

    auto back = std::make_shared<sxd::Button>(
        GuiIconText(ICON_RETURN, NULL),
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        [](){return IsKeyPressed(KEY_BACK) || IsKeyPressed(KEY_BACKSPACE);},
        []()
        {
            gameScreenInitialized = false;
            currentScene = MENU;
        },
        menubar.get(),
        (sxd::Align)(sxd::LEFT | sxd::CENTER_VERTICAL),
        0);

    menubar->AddWrapper(back);

    auto reset = std::make_shared<sxd::Button>(
        GuiIconText(ICON_RESTART, NULL),
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        [](){return false;},
        []()
        {
            grid.Reset();
        },
        menubar.get(),
        (sxd::Align)(sxd::LEFT | sxd::CENTER_VERTICAL),
        0);

    reset->AttachToRight(back.get());
    menubar->AddWrapper(reset);

    auto clear = std::make_shared<sxd::Button>(
        GuiIconText(ICON_ZOOM_CENTER, NULL),
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        [](){return false;},
        []()
        {
            grid.Clear();
        },
        menubar.get(),
        (sxd::Align)(sxd::LEFT | sxd::CENTER_VERTICAL),
        0);

    clear->AttachToRight(reset.get());
    menubar->AddWrapper(clear);

    auto pause = std::make_shared<sxd::Button>(
        GuiIconText(ICON_TOGGLE_PAUSE, NULL),
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        [](){return IsKeyPressed(KEY_P);},
        []()
        {
            pauseState = !pauseState;
        },
        menubar.get(),
        (sxd::Align)(sxd::CENTER_HORIZONTAL | sxd::CENTER_VERTICAL),
        0);

    menubar->AddWrapper(pause);

    auto increaseTicks = std::make_shared<sxd::Button>(
        GuiIconText(ICON_ARROW_UP_FILL, ""),
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        [](){return IsKeyPressed(KEY_UP);},
        []()
        {
            config.tickTime /= 2;
            if (config.tickTime < (static_cast<float>(1) / 1024))
            {
                config.tickTime = (static_cast<float>(1) / 1024);
            }
        },
        controlbar.get(),
        (sxd::Align)(sxd::RIGHT | sxd::CENTER_VERTICAL),
        0);

    controlbar->AddWrapper(increaseTicks);

    auto decreaseTicks = std::make_shared<sxd::Button>(
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
        controlbar.get(),
        (sxd::Align)(sxd::RIGHT | sxd::CENTER_VERTICAL),
        0);

    decreaseTicks->AttachToLeft(increaseTicks.get());
    controlbar->AddWrapper(decreaseTicks);

    auto undo = std::make_shared<sxd::Button>(
        GuiIconText(ICON_UNDO_FILL, ""),
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        [](){return ((IsKeyPressed(KEY_LEFT_CONTROL) || IsKeyPressed(KEY_RIGHT_CONTROL)) && IsKeyPressed(KEY_Z));},
        []()
        {
            if (pauseState == true)
            {
                auto temp = grid.GetGrid();
                grid.SetGrid(grid.GetPreviousGrid());
                grid.SetPreviousGrid(temp);
            }
        },
        controlbar.get(),
        (sxd::Align)(sxd::LEFT | sxd::CENTER_VERTICAL),
        0);

    controlbar->AddWrapper(undo);

    auto step = std::make_shared<sxd::Button>(
        GuiIconText(ICON_PLAYER_NEXT, ""),
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        [](){return IsKeyPressed(KEY_RIGHT);},
        []()
        {
            singleIteration = true;
        },
        controlbar.get(),
        (sxd::Align)(sxd::LEFT | sxd::CENTER_VERTICAL),
        0);

    step->AttachToRight(undo.get());
    controlbar->AddWrapper(step);
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

        int targetRowY = floor((mousePosition.y - sxd::AlignVerticalCenter(body.get(), (rowsY * (config.agentHeight + config.agentGap) - config.agentGap), 0)) / (config.agentHeight + config.agentGap));
        int targetColX = floor((mousePosition.x - sxd::AlignHorizontalCenter(body.get(), (colsX * (config.agentWidth + config.agentGap) - config.agentGap), 0)) / (config.agentWidth + config.agentGap));

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
    singleIteration = false;
}

void Game::RenderOutput()
{
    main->Render();

    RenderScreenGameStatusbar();
    RenderScreenGameMainPanel();

    if (pauseState == true)
    {
        RenderPauseOverlay();
    }

    Scene::RenderOutput();
}

void Game::RenderScreenGameStatusbar()
{
    float FPS = (static_cast<float>(1) / config.tickTime);
    const char* statusText;
    if (FPS < 1)
    {
        statusText = TextFormat("FPS: %0.2f; Day: %i", FPS,  grid.GetDay());
    }
    else
    {
        statusText = TextFormat("FPS: %0.f; Day: %i", FPS,  grid.GetDay());
    }

    auto status = std::make_shared<sxd::Text>(
        statusText,
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        statusbar.get(),
        (sxd::Align)(sxd::LEFT | sxd::CENTER_VERTICAL),
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
            int anchorX = sxd::AlignHorizontalCenter(body.get(), (colsX * (config.agentWidth + config.agentGap) - config.agentGap), 0) + (agent.GetColX() * (config.agentWidth + config.agentGap));
            int anchorY = sxd::AlignVerticalCenter(body.get(), (rowsY * (config.agentHeight + config.agentGap) - config.agentGap), 0) + (agent.GetRowY() * (config.agentHeight + config.agentGap));

            Rectangle rectAgent{
                (float)anchorX,
                (float)anchorY,
                (float)config.agentWidth,
                (float)config.agentHeight};

            if (agent.GetStatusCurrent() == true) // alive cell
            {
                DrawRectangleRec(rectAgent, global.GetForeground());
            }
            else if (agent.GetVitality() > 0) // decaying cell
            {
                DrawRectangleRec(rectAgent, GetAgentColor(agent));
            }
            else // dead cell
            {
                DrawRectangleLinesEx(rectAgent, config.agentInnerBorderWeight, Fade(global.GetForeground(), 0.50f));
            }

            if (config.debugMode == true && CheckCollisionPointRec(GetMousePosition(), rectAgent))
            {
                DrawText(TextFormat("X:%i Y:%i\nCurrent:%i\nNext:%i\nOutdated:%i\nVitality:%i",
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

    auto paused = std::make_shared<sxd::Text>(
        "[P]aused...",
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        statusbar.get(),
        (sxd::Align)(sxd::RIGHT | sxd::CENTER_VERTICAL),
        0);

    paused->Render();
}
