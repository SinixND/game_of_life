#include "screens.h"

#include "raygui.h"
#include <raylib.h>

#include "configs.h" // provide object "config" for configurable parameters
#include "globals.h" // provide object "global" for not configurable application parameters
#include "panels.h"

// SET GUI ELEMENTS
//---------------------------------
cPanel panelMenubarScreenMenu(0, 0, config.windowWidth, (global.guiButtonBaseHeight + 20), 10);
cPanel panelStatusbarScreenMenu(0, (config.windowHeight - (global.textSizeDefault + 20)), config.windowWidth, (global.textSizeDefault + 20), 10);
cPanel panelMainScreenMenu(0, panelMenubarScreenMenu.panelHeight_, config.windowWidth, config.windowHeight - panelMenubarScreenMenu.panelHeight_ - panelStatusbarScreenMenu.panelHeight_, 10);

const char* txtButtonDarkModeScreenMenu;

void ProcessScreenMenu();
void UpdateScreenMenu();
void OutputScreenMenu();

void RunScreenMenu()
{
    ProcessScreenMenu();
    UpdateScreenMenu();
    OutputScreenMenu();
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

void OutputScreenMenu()
{
    BeginDrawing();
    ClearBackground(global.GetColorBackground());

    // MENUBAR PANEL
    //---------------------------------
    int buttonDarkModeWidth = global.guiButtonBaseWidth + MeasureText("Light", global.textSizeDefault);
    if (GuiButton((Rectangle){(float)AlignHorizontalRight(panelMenubarScreenMenu, buttonDarkModeWidth, 0), (float)AlignVerticalCenter(panelMenubarScreenMenu, global.guiButtonBaseHeight, 0), (float)buttonDarkModeWidth, (float)global.guiButtonBaseHeight}, txtButtonDarkModeScreenMenu))
    {
        global.ToggleDarkMode();
    };

    // STATUSBAR PANEL
    //---------------------------------

    // MAIN PANEL
    //---------------------------------
    int buttonMenuWidth = global.guiButtonBaseWidth + MeasureText(" Start Game ", global.textSizeDefault);

    if (GuiButton((Rectangle){(float)AlignHorizontalCenter(panelMainScreenMenu, buttonMenuWidth, 0), (float)AlignVerticalCenter(panelMainScreenMenu, global.guiButtonBaseHeight, -50), (float)buttonMenuWidth, (float)global.guiButtonBaseHeight}, TextFormat("Start Game")) || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
    {
        currentScreen = GAME;
    }

    if (GuiButton((Rectangle){(float)AlignHorizontalCenter(panelMainScreenMenu, buttonMenuWidth, 0), (float)AlignVerticalCenter(panelMainScreenMenu, global.guiButtonBaseHeight, 0), (float)buttonMenuWidth, (float)global.guiButtonBaseHeight}, TextFormat("Settings")) || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
    {
        currentScreen = SETTINGS;
    }

    if (GuiButton((Rectangle){(float)AlignHorizontalCenter(panelMainScreenMenu, buttonMenuWidth, 0), (float)AlignVerticalCenter(panelMainScreenMenu, global.guiButtonBaseHeight, 50), (float)buttonMenuWidth, (float)global.guiButtonBaseHeight}, TextFormat("Exit")) || IsKeyPressed(KEY_ESCAPE))
    {
        global.exitApp = true;
    }

    EndDrawing();
}
