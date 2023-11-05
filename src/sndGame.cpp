#include <raygui.h>
#include <cmath>
#include "sndConfigs.h"
#include "sndGlobals.h"
#include "sndGrid.h"
#include "sndLayout.h"
#include "sndScenes.h"

// GAME OF LIFE / GRID
//---------------------------------
bool pauseState = false;

// no check for game end
bool sandboxMode = false;
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
        static_cast<int>(main->GetInnerTop() + 4 * GuiGetStyle(DEFAULT, TEXT_SIZE)));

    main->AddWrapper(menubar);

    statusbar = std::make_shared<sndWrapper>(
        "statusbar",
        main->GetInnerLeft(),
        static_cast<int>(main->GetInnerBottom() - 4 * GuiGetStyle(DEFAULT, TEXT_SIZE)),
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
        []()
        {
            grid.Clear();
            sandboxMode = true;
        },
        menubar.get(),
        (sndAlign)(LEFT | CENTER_VERTICAL),
        0);

    clear->AttachToRight(reset.get());
    menubar->AddWrapper(clear);

    auto pause = std::make_shared<sndButton>(
        "Pause",
        GuiGetStyle(DEFAULT, TEXT_SIZE),
        []()
        {
            pauseState = !pauseState;
        },
        menubar.get(),
        (sndAlign)(CENTER_HORIZONTAL | CENTER_VERTICAL),
        0);

    menubar->AddWrapper(pause);
    //---------------------------------

    // Variables
    //---------------------------------
    rowsY = body->GetInnerHeight() / (config.agentHeight + config.agentGap);
    colsX = body->GetInnerWidth() / (config.agentWidth + config.agentGap);
    grid.SetRowsY(rowsY);
    grid.SetColsX(colsX);
    //---------------------------------
}

void Game::Update()
{
    Input();
    Process();

    BeginDrawing();
    ClearBackground(global.GetBackground());

    Output();

    EndDrawing();
}

void Game::Input()
{
    if (IsKeyPressed(KEY_P))
    {
        pauseState = !pauseState;
    }

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

    if (pauseState == true)
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
}

void Game::Process()
{
    if (sandboxMode == true)
    {
        return;
    }

    int currentState = grid.gridStates_.size() - 1;
}

void Game::Output()
{
    main->Render();

    //RenderScreenGameStatusbar();
    //RenderScreenGameMainPanel();

    if (pauseState == true)
    {
        //RenderPauseOverlay();
    }
}