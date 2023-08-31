#include "screens.h"

#include <cmath>
#include <vector>

#include <raylib.h>
#include <raygui.h>

#include "configs.h" // provide object "config" for configurable parameters
#include "globals.h" // provide object "global" for not configurable application parameters
#include "grid.h"
#include "panels.h"

// SET GUI ELEMENTS
//---------------------------------
Panel menubarScreenGame(0, 0, config.windowWidth, (global.guiButtonBaseHeight + 20), 10);
Panel statusbarScreenGame(0, (config.windowHeight - (global.textSizeDefault + 20)), config.windowWidth, (global.textSizeDefault + 20), 10);
Panel mainScreenGame(0, menubarScreenGame.height_, config.windowWidth, config.windowHeight - menubarScreenGame.height_ - statusbarScreenGame.height_, 10);

const char* txtButtonPause = "[P]ause";
const char* txtButtonDarkModeScreenGame;

// GAME OF LIFE / GRID
//---------------------------------
bool pauseState = false;
bool gridEvolving = true;
// no check for game end
bool sandboxMode = false;
bool gameScreenInitialized = false;
float timePassed = 0;

int rowsY = mainScreenGame.GetContentHeight() / (config.agentHeight + config.agentGap);
int colsX = mainScreenGame.GetContentWidth() / (config.agentWidth + config.agentGap);
Grid grid(rowsY, colsX);

// GAME END OVERLAY
//---------------------------------
bool gameEndOverlayVisible = false;
Rectangle rectGameEndBackground{0, 0, (float)config.windowWidth, (float)config.windowHeight};

// FUNCTIONS
//---------------------------------
void ProcessScreenGame();
void UpdateScreenGame();
void RenderScreenGame();

void RunScreenGame()
{
    ProcessScreenGame();
    UpdateScreenGame();
    RenderScreenGame();
}

// FUNCTION DEFINITION
//---------------------------------
void ProcessScreenGame()
{
    if (gameEndOverlayVisible == true)
    {
        if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), rectGameEndBackground)) || IsKeyPressed(KEY_ENTER))
        {
            gameEndOverlayVisible = false;
            sandboxMode = true;
        }
    }

    if (IsKeyPressed(KEY_P))
    {
        pauseState = !pauseState;
    }

    // Draw agents manually
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
    {
        Vector2 mousePosition = GetMousePosition();

        int targetRowY = floor((mousePosition.y - AlignVerticalCenter(mainScreenGame, (rowsY * (config.agentHeight + config.agentGap) - config.agentGap), 0)) / (config.agentHeight + config.agentGap));
        int targetColX = floor((mousePosition.x - AlignHorizontalCenter(mainScreenGame, (colsX * (config.agentWidth + config.agentGap) - config.agentGap), 0)) / (config.agentWidth + config.agentGap));

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

    if ((pauseState == true) || (gridEvolving == false))
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

void UpdateScreenGame()
{
    // MENUBAR PANEL
    //---------------------------------
    if (global.GetDarkMode() == true)
    {
        txtButtonDarkModeScreenGame = "Light";
    }
    else
    {
        txtButtonDarkModeScreenGame = "Dark";
    }

    if (pauseState == true)
    {
        txtButtonPause = "Resume";
        return;
    }
    else
    {
        txtButtonPause = "Pause";
    }

    // GAME END CONDITION
    //---------------------------------
    if (gridEvolving == false)
    {
        return;
    }

    if (sandboxMode == true)
    {
        return;
    }

    int currentState = grid.gridStates_.size() - 1;
    if (grid.gridStates_[currentState] == grid.gridStates_[currentState - 2])
    {
        gridEvolving = false;
        gameEndOverlayVisible = true;
    }
}

void RenderScreenGameMenubar();
void RenderScreenGameStatusbar();
void RenderScreenGameMainPanel();
void RenderGameEndOverlay();
void RenderPauseOverlay();

void RenderScreenGame()
{
    BeginDrawing();
    ClearBackground(global.GetColorBackground());

    RenderScreenGameMenubar();
    RenderScreenGameStatusbar();
    RenderScreenGameMainPanel();

    if (gameEndOverlayVisible == true)
    {
        RenderGameEndOverlay();
    }
    else if (pauseState == true)
    {
        RenderPauseOverlay();
    }

    // DrawFPS(GetScreenWidth() - 95, 10);
    EndDrawing();
}

void RenderScreenGameMenubar()
{
    const char* txtButtonBackScreenGame = "Back";
    int buttonBackWidth = global.guiButtonBaseWidth + MeasureText(txtButtonBackScreenGame, global.textSizeDefault);
    if (GuiButton(
            (Rectangle){
                (float)AlignHorizontalLeft(menubarScreenGame, 0),
                (float)AlignVerticalTop(menubarScreenGame, 0),
                (float)buttonBackWidth,
                (float)global.guiButtonBaseHeight},
            txtButtonBackScreenGame))
    {
        gameScreenInitialized = false;
        currentScreen = MENU;
    }

    const char* txtButtonResetScreenGame = "Reset";
    int buttonResetWidth = global.guiButtonBaseWidth + MeasureText(txtButtonResetScreenGame, global.textSizeDefault);
    if (GuiButton(
            (Rectangle){
                (float)AlignHorizontalLeft(menubarScreenGame, buttonBackWidth + 10),
                (float)AlignVerticalTop(menubarScreenGame, 0),
                (float)buttonResetWidth,
                (float)global.guiButtonBaseHeight},
            txtButtonResetScreenGame))
    {
        grid.Reset();
        gridEvolving = true;
    }

    const char* txtButtonClearScreenGame = "Clear";
    int buttonClearWidth = global.guiButtonBaseWidth + MeasureText(txtButtonClearScreenGame, global.textSizeDefault);
    if (GuiButton(
            (Rectangle){
                (float)AlignHorizontalLeft(menubarScreenGame, buttonBackWidth + 10 + buttonResetWidth + 10),
                (float)AlignVerticalTop(menubarScreenGame, 0),
                (float)buttonClearWidth,
                (float)global.guiButtonBaseHeight},
            txtButtonClearScreenGame))
    {
        grid.Clear();
        gridEvolving = true;
        sandboxMode = true;
    }

    int buttonPauseWidth = global.guiButtonBaseWidth + MeasureText("Resume", global.textSizeDefault);
    if (GuiButton(
            (Rectangle){
                (float)AlignHorizontalCenter(menubarScreenGame, buttonPauseWidth, 0),
                (float)AlignVerticalTop(menubarScreenGame, 0),
                (float)buttonPauseWidth,
                (float)global.guiButtonBaseHeight},
            txtButtonPause))
    {
        pauseState = !pauseState;
    }

    int buttonDarkModeWidth = global.guiButtonBaseWidth + MeasureText("Light", global.textSizeDefault);
    if (GuiButton(
            (Rectangle){
                (float)AlignHorizontalRight(menubarScreenGame, buttonDarkModeWidth, 0),
                (float)AlignVerticalTop(menubarScreenGame, 0),
                (float)buttonDarkModeWidth,
                (float)global.guiButtonBaseHeight},
            txtButtonDarkModeScreenGame))
    {
        global.ToggleDarkMode();
    }
}

void RenderScreenGameStatusbar()
{
    // STATUSBAR PANEL
    //---------------------------------
    if (sandboxMode == true)
    {
        grid.SetDay(0);
    }

    DrawText(TextFormat("TickTime: %.0f ms; Day: %i", config.tickTime * 1000, grid.GetDay()), AlignHorizontalLeft(statusbarScreenGame, 0), AlignVerticalCenter(statusbarScreenGame, global.textSizeDefault, 0), global.textSizeDefault, global.GetColorForeground());
}

Color GetAgentColor(Agent agent);

void RenderScreenGameMainPanel()
{
    // draw agents
    for (auto& row : grid.GetGrid())
    {
        for (auto& agent : row)
        {
            int anchorX = AlignHorizontalCenter(mainScreenGame, (colsX * (config.agentWidth + config.agentGap) - config.agentGap), 0) + (agent.GetColX() * (config.agentWidth + config.agentGap));
            int anchorY = AlignVerticalCenter(mainScreenGame, (rowsY * (config.agentHeight + config.agentGap) - config.agentGap), 0) + (agent.GetRowY() * (config.agentHeight + config.agentGap));

            Rectangle rectAgent{
                (float)anchorX,
                (float)anchorY,
                (float)config.agentWidth,
                (float)config.agentHeight};

            if (agent.GetStatusCurrent() == true)
            {
                DrawRectangleRec(rectAgent, global.GetColorForeground());
            }
            else if (agent.GetVitality() > 0)
            {
                DrawRectangleRec(rectAgent, GetAgentColor(agent));
            }
            else
            {
                DrawRectangleLinesEx(rectAgent, config.agentInnerBorderWeight, Fade(global.GetColorForeground(), 0.50f));
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
    Color AgentColor = Fade(global.GetColorForeground(), (agent.GetVitality() * (1.0f / agent.GetMaxVitality())));
    return AgentColor;
}

void RenderGameEndOverlay()
{
    DrawRectangleRec(rectGameEndBackground, CLITERAL(Color){130, 130, 130, 175});
    DrawRectangleLinesEx(rectGameEndBackground, 10, Fade(global.GetColorForeground(), 0.75f));
    DrawText(TextFormat("Game over! \nUniverse survived for %d days. \nPress Enter or click to\n go back to game screen. \nPress ESC to leave.", grid.GetDay()), 50, 50, (global.textSizeDefault * 1.5), RED);
}

void RenderPauseOverlay()
{
    // Draw overlay Frame
    Rectangle rectpanelMainScreenGame{
        (float)mainScreenGame.leftX_,
        (float)mainScreenGame.topY_,
        (float)mainScreenGame.width_,
        (float)mainScreenGame.height_};
    DrawRectangleLinesEx(rectpanelMainScreenGame, 10, Fade(global.GetColorForeground(), 0.75f));
    const char* txtPaused = TextFormat("[P]aused...");
    DrawText(txtPaused, AlignHorizontalRight(statusbarScreenGame, MeasureText(txtPaused, global.textSizeDefault), 0), AlignVerticalCenter(statusbarScreenGame, global.textSizeDefault, 0), global.textSizeDefault, global.GetColorForeground());
}
