#include "screens.h"

#include <vector>

#include "raygui.h"
#include <raylib.h>

#include "configs.h" // provide object "config" for configurable parameters
#include "gameoflife.h"
#include "globals.h" // provide object "global" for not configurable application parameters
#include "panels.h"

// SET GUI ELEMENTS
//---------------------------------
cPanel panelMenubarScreenGame(0, 0, config.windowWidth, (global.guiButtonBaseHeight + 20), 10);
cPanel panelStatusbarScreenGame(0, (config.windowHeight - (global.textSizeDefault + 20)), config.windowWidth, (global.textSizeDefault + 20), 10);
cPanel panelMainScreenGame(0, panelMenubarScreenGame.panelHeight_, config.windowWidth, config.windowHeight - panelMenubarScreenGame.panelHeight_ - panelStatusbarScreenGame.panelHeight_, 10);

const char* txtButtonPause = "[P]ause";
const char* txtButtonDarkModeScreenGame;

// GAME OF LIFE / GRID
//---------------------------------
bool pauseState = false;
bool evolutionState = true;
bool gameScreenInitialized = false;
float timePassed = 0;

int rowsY = panelMainScreenGame.GetPanelContentHeight() / (config.agentHeight + config.agentGap);
int colsX = panelMainScreenGame.GetPanelContentWidth() / (config.agentWidth + config.agentGap);
cGameOfLife GameOfLife(rowsY, colsX);

// GAME END OVERLAY
//---------------------------------
bool gameEndOverlayVisible = true;
Rectangle rectGameEndBackground{0, 0, (float)config.windowWidth, (float)config.windowHeight};

// FUNCTION DECLARATION
//---------------------------------
void InitializeScreenGame();
void ProcessScreenGame();
void UpdateScreenGame();
void OutputScreenGame();

void RunScreenGame()
{
    ProcessScreenGame();
    UpdateScreenGame();
    OutputScreenGame();
}

// FUNCTION DEFINITION
//---------------------------------
void InitializeScreenGame()
{
    if (gameScreenInitialized == false)
    {
        cGameOfLife GameOfLife(rowsY, colsX);
        gameScreenInitialized = true;
    }
};

void ProcessScreenGame()
{
    if (IsKeyPressed(KEY_P))
    {
        pauseState = !pauseState;
    }

    if (pauseState == true)
    {
        return;
    }

    if ((evolutionState == false) && (gameEndOverlayVisible == true))
    {
        if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), rectGameEndBackground)) || IsKeyPressed(KEY_ENTER))
        {
            gameEndOverlayVisible = false;
        }
        return;
    }

    if (timePassed <= config.tickTime)
    {
        timePassed += GetFrameTime();
        return;
    }

    timePassed = 0;
    GameOfLife.EvolveGrid();
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
    if (evolutionState == false)
    {
        return;
    }

    int currentState = GameOfLife.gridStates_.size() - 1;
    if (GameOfLife.gridStates_[currentState] == GameOfLife.gridStates_[currentState - 2])
    {
        evolutionState = false;
    }
}

void OutputScreenGame()
{
    BeginDrawing();
    ClearBackground(global.GetColorBackground());

    // MENUBAR PANEL
    //---------------------------------
    const char* txtButtonBackScreenGame = "Back";
    int buttonBackWidth = global.guiButtonBaseWidth + MeasureText(txtButtonBackScreenGame, global.textSizeDefault);
    if (GuiButton((Rectangle){(float)AlignHorizontalLeft(panelMenubarScreenGame, 0), (float)AlignVerticalTop(panelMenubarScreenGame, 0), (float)buttonBackWidth, (float)global.guiButtonBaseHeight}, txtButtonBackScreenGame))
    {
        gameScreenInitialized = false;
        currentScreen = MENU;
    };

    const char* txtButtonResetScreenGame = "Reset";
    int buttonResetWidth = global.guiButtonBaseWidth + MeasureText(txtButtonResetScreenGame, global.textSizeDefault);
    if (GuiButton((Rectangle){(float)AlignHorizontalLeft(panelMenubarScreenGame, buttonBackWidth + 10), (float)AlignVerticalTop(panelMenubarScreenGame, 0), (float)buttonResetWidth, (float)global.guiButtonBaseHeight}, txtButtonResetScreenGame))
    {
        GameOfLife.ResetGameOfLife();
    };

    int buttonPauseWidth = global.guiButtonBaseWidth + MeasureText("Resume", global.textSizeDefault);
    if (GuiButton((Rectangle){(float)AlignHorizontalCenter(panelMenubarScreenGame, buttonPauseWidth, 0), (float)AlignVerticalTop(panelMenubarScreenGame, 0), (float)buttonPauseWidth, (float)global.guiButtonBaseHeight}, txtButtonPause))
    {
        pauseState = !pauseState;
    };

    int buttonDarkModeWidth = global.guiButtonBaseWidth + MeasureText("Light", global.textSizeDefault);
    if (GuiButton((Rectangle){(float)AlignHorizontalRight(panelMenubarScreenGame, buttonDarkModeWidth, 0), (float)AlignVerticalTop(panelMenubarScreenGame, 0), (float)buttonDarkModeWidth, (float)global.guiButtonBaseHeight}, txtButtonDarkModeScreenGame))
    {
        global.ToggleDarkMode();
    };

    // STATUSBAR PANEL
    //---------------------------------
    DrawText(TextFormat("TickTime: %.0f ms; Day: %i", config.tickTime * 1000, GameOfLife.GetDay()), AlignHorizontalLeft(panelStatusbarScreenGame, 0), AlignVerticalCenter(panelStatusbarScreenGame, global.textSizeDefault, 0), global.textSizeDefault, global.GetColorForeground());

    // MAIN PANEL
    //---------------------------------
    // draw agents
    for (auto& row : GameOfLife.GetGrid())
    {
        for (auto& agent : row)
        {
            Rectangle rectAgent{
                (float)AlignHorizontalCenter(panelMainScreenGame, (colsX * (config.agentWidth + config.agentGap) - config.agentGap), 0) + (agent.posX_ * (config.agentWidth + config.agentGap)),
                (float)AlignVerticalCenter(panelMainScreenGame, (rowsY * (config.agentHeight + config.agentGap) - config.agentGap), 0) + (agent.posY_ * (config.agentHeight + config.agentGap)),
                (float)config.agentWidth,
                (float)config.agentHeight};

            if (agent.statusIs_ == true)
            {
                DrawRectangleRec(rectAgent, global.GetColorForeground());
            }
            else
            {
                Color colorAgentVitality;
                switch (agent.vitality_)
                {
                case 4:
                    colorAgentVitality = global.GetColorForeground();
                    DrawRectangleRec(rectAgent, colorAgentVitality);
                    break;

                case 3:
                    colorAgentVitality = Fade(global.GetColorForeground(), 0.75f);
                    DrawRectangleRec(rectAgent, colorAgentVitality);
                    break;

                case 2:
                    colorAgentVitality = Fade(global.GetColorForeground(), 0.50f);
                    DrawRectangleRec(rectAgent, colorAgentVitality);
                    break;

                case 1:
                    colorAgentVitality = Fade(global.GetColorForeground(), 0.25f);
                    DrawRectangleRec(rectAgent, colorAgentVitality);
                    break;

                default:
                    DrawRectangleLinesEx(rectAgent, config.agentInnerBorderWeight, Fade(global.GetColorForeground(), 0.50f));
                    break;
                }
            }
        }
    }

    // DRAW GAME END OVERLAY
    //---------------------------------
    if ((evolutionState == false) && (gameEndOverlayVisible == true))
    {
        DrawRectangleRec(rectGameEndBackground, CLITERAL(Color){130, 130, 130, 175});
        DrawRectangleLinesEx(rectGameEndBackground, 10, Fade(global.GetColorForeground(), 0.75f));
        DrawText(TextFormat("Game over! \nUniverse survived for %d days. \nPress Enter or click to\n go back to game screen. \nPress ESC to leave.", GameOfLife.GetDay()), 50, 50, (global.textSizeDefault * 1.5), RED);
    }

    // DRAW PAUSE OVERLAY
    //---------------------------------
    else if (pauseState == true)
    {
        Rectangle rectpanelMainScreenGame{(float)panelMainScreenGame.panelLeftX_, (float)panelMainScreenGame.panelTopY_, (float)panelMainScreenGame.panelWidth_, (float)panelMainScreenGame.panelHeight_};

        DrawRectangleRec((Rectangle){(float)panelMainScreenGame.panelLeftX_, (float)panelMainScreenGame.panelTopY_, (float)panelMainScreenGame.panelWidth_, (float)panelMainScreenGame.panelHeight_}, CLITERAL(Color){130, 130, 130, 175});

        DrawRectangleLinesEx(rectpanelMainScreenGame, 10, Fade(global.GetColorForeground(), 0.75f));

        const char* txtPaused = TextFormat("[P]aused...");
        DrawText(txtPaused, AlignHorizontalRight(panelStatusbarScreenGame, MeasureText(txtPaused, global.textSizeDefault), 0), AlignVerticalCenter(panelStatusbarScreenGame, global.textSizeDefault, 0), global.textSizeDefault, global.GetColorForeground());
    }

    // DrawFPS(GetScreenWidth() - 95, 10);
    EndDrawing();
}
