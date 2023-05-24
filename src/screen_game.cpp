#include "screens.h"

#include <iostream>
#include <vector>

#include "raylib.h"
#define RAYBUI_IMPLEMENTATION
#include "raygui.h"
#include "globals.h"
#include "panels.h"
#include "agents.h"

// game screen
bool pauseState = true;

// menubar
cPanel menubar(windowWidth, 75, 0, 0, 10);
const char *txtButtonPause = "[P]ause";
const char *txtButtonDarkMode;

// statusbar
cPanel statusbar(windowWidth, (txtSmall + 20), 0, (windowHeight - (txtSmall + 20)), 10);

// display
cPanel display(windowWidth, windowHeight - menubar.getPanelHeight() - statusbar.getPanelHeight(), 0, menubar.getPanelHeight(), 10);

// agent
int agentWidth = 10;
int agentHeight = agentWidth; // independent height and width possible
int agentInnerBorderWeight = 1;
bool decayingAgents = true;

// environment
int agentGap = 1;
int colsX = display.getPanelContentWidth() / (agentWidth + agentGap);
int rowsY = display.getPanelContentHeight() / (agentHeight + agentGap);
int environmentSize = colsX * rowsY;
bool evolutionState = true;
bool environmentInitialized = false;

// logic
float lifeDensity = 2.0f / 8.0f; // in %, eg. 25
int evolutionTime = 100;         // in ms
float timePassed = 0;
int day = 0;
std::vector<int> environmentState0;
std::vector<int> environmentState1;
std::vector<int> environmentState2;
std::vector<std::vector<cAgent>> environment;

// game end overlay
bool gameEndOverlayVisible = true;

Rectangle rectGameEndBackground{
    0,
    0,
    float(windowWidth),
    float(windowHeight)};

void initialiseGameScreen()
{
  // initialise environment
  for (int rowY = 0; rowY < rowsY; ++rowY)
  {
    std::vector<cAgent> v;
    environment.push_back(v);

    for (int colX = 0; colX < colsX; ++colX)
    {
      environment[rowY].push_back(cAgent());

      cAgent &agent = environment[rowY][colX];

      if (((rand() % 100) * 0.01) <= lifeDensity)
      {
        agent.setStatusIs(true); // make alive
      }
    }
  }
};

void processGameScreen()
{
  if (pauseState == false)
  {
    // display
    // determine next day environment state
    for (int rowY = 0; rowY < rowsY; ++rowY)
    {
      for (int colX = 0; colX < colsX; ++colX)
      {
        cAgent &agent = environment[rowY][colX];
        // Adjacent count = 2 -> remain.
        // Adjacent count = 3 -> alive.
        // All other die.

        if (countAdjacents(environment, colX, rowY) == 2)
        {
          agent.setStatusNext(agent.getStatusIs());
        }
        else if (countAdjacents(environment, colX, rowY) == 3)
        {
          agent.setStatusNext(true);
        }
        else
        {
          agent.setStatusNext(false);
        }

        if (agent.getStatusIs() != agent.getStatusNext())
        {
          agent.setStatusChanging(true);
        }
      }
    }

    if ((evolutionState == false) && (gameEndOverlayVisible == true))
    {
      if ((IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), rectGameEndBackground)) || IsKeyPressed(KEY_ENTER))
      {
        gameEndOverlayVisible = false;
      }
    }
  }

  if (IsKeyPressed(KEY_P))
  {
    pauseState = !pauseState;
  }
};

void updateGameScreen()
{
  // menubar
  if (pauseState == true)
  {
    txtButtonPause = "Resume";
  }
  else
  {
    txtButtonPause = "Pause";
  }

  if (darkMode == true)
  {
    txtButtonDarkMode = "Light";
  }
  else
  {
    txtButtonDarkMode = "Dark";
  }

  if (pauseState == false)
  {
    // display
    if (evolutionState == true)
    {
      if (timePassed <= evolutionTime)
      {
        // wait till day time is passed
        timePassed += GetFrameTime() * 1000; // in ms
      }
      else
      {
        // reset day time; increment day
        timePassed = 0;
        day += 1;

        // remember last 3 environment states for game end condition
        environmentState2 = environmentState1;
        environmentState1 = environmentState0;
        environmentState0.clear();

        // update environment
        for (int rowY = 0; rowY < rowsY; ++rowY)
        {
          for (int colX = 0; colX < colsX; ++colX)
          {
            cAgent &agent = environment[rowY][colX];
            if (agent.getStatusChanging() == true)
            {
              if (agent.getStatusNext() == true)
              {
                agent.setStatusIs(true);
                if (decayingAgents == true)
                {
                  agent.setVitality(4);
                }
              }
              else
              {
                agent.setStatusIs(false);
              }
            }

            if (agent.getStatusIs() == true)
            {
              environmentState0.push_back(1);
            }
            else
            {
              environmentState0.push_back(0);
              agent.decreaseVitality();
            }
          }
        }

        if (environmentState0 == environmentState2)
        {
          evolutionState = false;
        }
      }
    }
  }
};

void outputGameScreen()
{
  BeginDrawing();
  ClearBackground(BG);

  // menubar
  int rectButtonPauseWidth = MeasureText("Resume", txtSmall);
  if (GuiButton(Rectangle{
                    float(alignHorizontalCenter(menubar, rectButtonPauseWidth)),
                    float(alignVerticalTop(menubar, 0)),
                    float(rectButtonPauseWidth),
                    float(txtSmall + 10)},
                txtButtonPause))
  {
    pauseState = !pauseState;
  };

  int rectButtonDarkModeWidth = MeasureText("Light", txtSmall);
  if (GuiButton(Rectangle{
                    float(alignHorizontalRight(menubar, rectButtonDarkModeWidth, 0)),
                    float(alignVerticalTop(menubar, 0)),
                    float(rectButtonDarkModeWidth),
                    float(txtSmall + 10)},
                txtButtonDarkMode))
  {
    darkMode = !darkMode;
  };

  // statusbar
  DrawText(TextFormat("Time: %i ms; Day: %i", evolutionTime, day), alignHorizontalLeft(statusbar, 0), alignVerticalTop(statusbar, 0), txtSmall, FG);

  // display
  // draw environment
  for (int rowY = 0; rowY < rowsY; ++rowY)
  {
    for (int colX = 0; colX < colsX; ++colX)
    {
      cAgent &agent = environment[rowY][colX];
      Rectangle rectAgent{
          float(alignHorizontalCenter(display, (colsX * (agentWidth + agentGap) - agentGap)) + (colX * (agentWidth + agentGap))),
          float(alignVerticalCenter(display, (rowsY * (agentHeight + agentGap) - agentGap)) + (rowY * (agentHeight + agentGap))),
          float(agentWidth),
          float(agentHeight)};

      if (agent.getStatusIs() == true)
      {
        DrawRectangleRec(rectAgent, FG);
      }
      else
      {
        Color agentVitalityColor;
        switch (agent.getVitality())
        {
        case 4:
          agentVitalityColor = FG;
          DrawRectangleRec(rectAgent, agentVitalityColor);
          break;

        case 3:
          agentVitalityColor = FG2;
          DrawRectangleRec(rectAgent, agentVitalityColor);
          break;

        case 2:
          agentVitalityColor = FG3;
          DrawRectangleRec(rectAgent, agentVitalityColor);
          break;

        case 1:
          agentVitalityColor = FG4;
          DrawRectangleRec(rectAgent, agentVitalityColor);
          break;

        default:
          DrawRectangleLinesEx(rectAgent, agentInnerBorderWeight, GRAY);
          break;
        }
      }
    }
  }

  // draw game end screen
  if ((evolutionState == false) && (gameEndOverlayVisible == true))
  {
    DrawRectangleRec(rectGameEndBackground, CLITERAL(Color){130, 130, 130, 175});
    DrawRectangleLinesEx(rectGameEndBackground, 10, DARKGRAY);
    DrawText(TextFormat("Game over!\nUniverse survived for %d days. \nPress Enter or click to \ngo back to environment. \nPress ESC to leave.", day), 50, 50, txtNormal, RED);
  }

  // draw pause state
  else if (pauseState == true)
  {
    Rectangle rectDisplay{
        float(display.getPanelLeftX()),
        float(display.getPanelTopY()),
        float(display.getPanelWidth()),
        float(display.getPanelHeight())};

    DrawRectangleRec(Rectangle{
                         float(display.getPanelLeftX()),
                         float(display.getPanelTopY()),
                         float(display.getPanelWidth()),
                         float(display.getPanelHeight())},
                     CLITERAL(Color){130, 130, 130, 175});

    DrawRectangleLinesEx(rectDisplay, 10, DARKGRAY);

    const char *txtPaused = TextFormat("[P]aused...");
    DrawText(txtPaused, alignHorizontalRight(statusbar, MeasureText(txtPaused, txtNormal), 0), alignVerticalCenter(statusbar, txtNormal), txtNormal, FG);
  }

  DrawFPS(GetScreenWidth() - 95, 10);
  EndDrawing();
};

void runGameScreen()
{
  if (environmentInitialized == false)
  {
    initialiseGameScreen();
    outputGameScreen();
    environmentInitialized = true;
  }

  processGameScreen();
  updateGameScreen();

  outputGameScreen();
};