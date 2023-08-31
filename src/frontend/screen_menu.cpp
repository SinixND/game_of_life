#include "screens.h"

#include <raylib.h>
#include <raygui.h>

#include "configs.h" // provide object "config" for configurable parameters
#include "globals.h" // provide object "global" for not configurable application parameters
#include "panels.h"

// SET GUI ELEMENTS
//---------------------------------
Panel menubarScreenMenu(0, 0, config.windowWidth, (global.guiButtonBaseHeight + 20), 10);
Panel statusbarScreenMenu(0, (config.windowHeight - (global.textSizeDefault + 20)), config.windowWidth, (global.textSizeDefault + 20), 10);
Panel mainScreenMenu(0, menubarScreenMenu.height_, config.windowWidth, config.windowHeight - menubarScreenMenu.height_ - statusbarScreenMenu.height_, 10);

const char* txtButtonDarkModeScreenMenu;

void ProcessScreenMenu();
void UpdateScreenMenu();
void RenderScreenMenu();

void RunScreenMenu()
{
    ProcessScreenMenu();
    UpdateScreenMenu();
    RenderScreenMenu();
}

void ProcessScreenMenu(){};

void UpdateScreenMenu()
{
    // MENUBAR
    //---------------------------------
    if (global.GetDarkMode() == true)
    {
        txtButtonDarkModeScreenMenu = "Light";
    }
    else
    {
        txtButtonDarkModeScreenMenu = "Dark";
    }
};

void RenderScreenMenuMenubar();
void RenderScreenMenuMainPanel();

void RenderScreenMenu()
{
    BeginDrawing();
    ClearBackground(global.GetColorBackground());

    RenderScreenMenuMenubar();

    // STATUSBAR PANEL
    //---------------------------------

    RenderScreenMenuMainPanel();

    EndDrawing();
}

void RenderScreenMenuMenubar()
{
    int buttonDarkModeWidth = global.guiButtonBaseWidth + MeasureText("Light", global.textSizeDefault);
    if (GuiButton(
            (Rectangle){
                (float)AlignHorizontalRight(menubarScreenMenu, buttonDarkModeWidth, 0),
                (float)AlignVerticalCenter(menubarScreenMenu, global.guiButtonBaseHeight, 0),
                (float)buttonDarkModeWidth,
                (float)global.guiButtonBaseHeight},
            txtButtonDarkModeScreenMenu))
    {
        global.ToggleDarkMode();
    };
}

void RenderScreenMenuMainPanel()
{
    int buttonMenuWidth = global.guiButtonBaseWidth + MeasureText(" Start Game ", global.textSizeDefault);

    if (GuiButton(
            (Rectangle){
                (float)AlignHorizontalCenter(mainScreenMenu, buttonMenuWidth, 0),
                (float)AlignVerticalCenter(mainScreenMenu, global.guiButtonBaseHeight, -50),
                (float)buttonMenuWidth,
                (float)global.guiButtonBaseHeight},
            TextFormat("Start Game")) ||
        IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
    {
        currentScreen = GAME;
    }

    if (GuiButton(
            (Rectangle){
                (float)AlignHorizontalCenter(mainScreenMenu, buttonMenuWidth, 0),
                (float)AlignVerticalCenter(mainScreenMenu, global.guiButtonBaseHeight, 0),
                (float)buttonMenuWidth,
                (float)global.guiButtonBaseHeight},
            TextFormat("Settings")))
    {
        currentScreen = SETTINGS;
    }

    if (GuiButton(
            (Rectangle){
                (float)AlignHorizontalCenter(mainScreenMenu, buttonMenuWidth, 0),
                (float)AlignVerticalCenter(mainScreenMenu, global.guiButtonBaseHeight, 50),
                (float)buttonMenuWidth,
                (float)global.guiButtonBaseHeight},
            TextFormat("Exit")) ||
        IsKeyPressed(KEY_ESCAPE))
    {
        global.exitApp = true;
    }
}