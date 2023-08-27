#include "screens.h"

#include <cmath>
#include <vector>

#include "raygui.h"
#include <raylib.h>

#include "configs.h" // provide object "config" for configurable parameters
#include "globals.h" // provide object "global" for not configurable application parameters
#include "grid.h"
#include "panels.h"

// SET GUI ELEMENTS
//---------------------------------
Panel panelMenubarScreenGame(0, 0, config.windowWidth, (global.guiButtonBaseHeight + 20), 10);
Panel panelStatusbarScreenGame(0, (config.windowHeight - (global.textSizeDefault + 20)), config.windowWidth, (global.textSizeDefault + 20), 10);
Panel panelMainScreenGame(0, panelMenubarScreenGame.height_, config.windowWidth, config.windowHeight - panelMenubarScreenGame.height_ - panelStatusbarScreenGame.height_, 10);

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

int rowsY = panelMainScreenGame.GetContentHeight() / (config.agentHeight + config.agentGap);
int colsX = panelMainScreenGame.GetContentWidth() / (config.agentWidth + config.agentGap);
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
        int targetRowY = floor((mousePosition.y - AlignVerticalCenter(panelMainScreenGame, (rowsY * (config.agentHeight + config.agentGap) - config.agentGap), 0)) / (config.agentHeight + config.agentGap));
        int targetColX = floor((mousePosition.x - AlignHorizontalCenter(panelMainScreenGame, (colsX * (config.agentWidth + config.agentGap) - config.agentGap), 0)) / (config.agentWidth + config.agentGap));

        if ((targetRowY < 0 || targetRowY >= rowsY) || (targetColX < 0 || targetColX >= colsX))
        {
            // do nothing
        }
        else if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            Agent& agent = grid.GetGrid()[targetRowY][targetColX];
            agent.SetStatusCurrent(true);
            agent.RefreshVitality();
        }
        else if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            Agent& agent = grid.GetGrid()[targetRowY][targetColX];
            agent.SetStatusCurrent(false);
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
                (float)AlignHorizontalLeft(panelMenubarScreenGame, 0),
                (float)AlignVerticalTop(panelMenubarScreenGame, 0),
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
                (float)AlignHorizontalLeft(panelMenubarScreenGame, buttonBackWidth + 10),
                (float)AlignVerticalTop(panelMenubarScreenGame, 0),
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
                (float)AlignHorizontalLeft(panelMenubarScreenGame, buttonBackWidth + 10 + buttonResetWidth + 10),
                (float)AlignVerticalTop(panelMenubarScreenGame, 0),
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
                (float)AlignHorizontalCenter(panelMenubarScreenGame, buttonPauseWidth, 0),
                (float)AlignVerticalTop(panelMenubarScreenGame, 0),
                (float)buttonPauseWidth,
                (float)global.guiButtonBaseHeight},
            txtButtonPause))
    {
        pauseState = !pauseState;
    }

    int buttonDarkModeWidth = global.guiButtonBaseWidth + MeasureText("Light", global.textSizeDefault);
    if (GuiButton(
            (Rectangle){
                (float)AlignHorizontalRight(panelMenubarScreenGame, buttonDarkModeWidth, 0),
                (float)AlignVerticalTop(panelMenubarScreenGame, 0),
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

    DrawText(TextFormat("TickTime: %.0f ms; Day: %i", config.tickTime * 1000, grid.GetDay()), AlignHorizontalLeft(panelStatusbarScreenGame, 0), AlignVerticalCenter(panelStatusbarScreenGame, global.textSizeDefault, 0), global.textSizeDefault, global.GetColorForeground());
}

Color GetAgentColor(Agent agent);

void RenderScreenGameMainPanel()
{
    // draw agents
    for (auto& row : grid.GetGrid())
    {
        for (auto& agent : row)
        {
            Rectangle rectAgent{
                (float)AlignHorizontalCenter(panelMainScreenGame, (colsX * (config.agentWidth + config.agentGap) - config.agentGap), 0) + (agent.GetColX() * (config.agentWidth + config.agentGap)),
                (float)AlignVerticalCenter(panelMainScreenGame, (rowsY * (config.agentHeight + config.agentGap) - config.agentGap), 0) + (agent.GetRowY() * (config.agentHeight + config.agentGap)),
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
        }
    }
}

Color GetAgentColor(Agent agent)
{
    if (config.agentColorDebug == true)
    {
        if (agent.GetStatusNext() == true && agent.GetStatusCurrent() == false)
        {
            return GREEN;
        }

        if (agent.GetStatusNext() == false && agent.GetStatusCurrent() == true)
        {
            return RED;
        }

        Color AgentColor = Fade(global.GetColorForeground(), (agent.GetVitality() * (1.0f / agent.GetMaxVitality())));
        return AgentColor;
    }

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
    /*
    // Draw a transparent overlay
    DrawRectangleRec(
        (Rectangle){
            (float)panelMainScreenGame.leftX_,
            (float)panelMainScreenGame.topY_,
            (float)panelMainScreenGame.width_,
            (float)panelMainScreenGame.height_},
        CLITERAL(Color){130, 130, 130, 175});
    */

    // Draw overlay Frame
    Rectangle rectpanelMainScreenGame{
        (float)panelMainScreenGame.leftX_,
        (float)panelMainScreenGame.topY_,
        (float)panelMainScreenGame.width_,
        (float)panelMainScreenGame.height_};
    DrawRectangleLinesEx(rectpanelMainScreenGame, 10, Fade(global.GetColorForeground(), 0.75f));
    const char* txtPaused = TextFormat("[P]aused...");
    DrawText(txtPaused, AlignHorizontalRight(panelStatusbarScreenGame, MeasureText(txtPaused, global.textSizeDefault), 0), AlignVerticalCenter(panelStatusbarScreenGame, global.textSizeDefault, 0), global.textSizeDefault, global.GetColorForeground());
}
