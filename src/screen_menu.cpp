#include "screens.h"

#include "raylib.h"
#include "raygui.h"

#include "globals.h" // provide object "global" for not configurable application parameters
#include "configs.h" // provide object "config" for configurable parameters
#include "panels.h"

// SET GUI ELEMENTS
//---------------------------------
cPanel panelMenubarScreenMenu(config.windowWidth, (global.guiButtonBaseHeight + 20), 0, 0, 10);
cPanel panelStatusbarScreenMenu(config.windowWidth, (global.txtSmall + 20), 0, (config.windowHeight - (global.txtSmall + 20)), 10);
cPanel panelMainScreenMenu(config.windowWidth, config.windowHeight - panelMenubarScreenMenu.mPanelHeight - panelStatusbarScreenMenu.mPanelHeight, 0, panelMenubarScreenMenu.mPanelHeight, 10);

const char *txtButtonDarkModeScreenMenu;


void ProcessScreenMenu();
void UpdateScreenMenu();
void OutputScreenMenu();

void RunScreenMenu() {
  ProcessScreenMenu();
  UpdateScreenMenu();
  OutputScreenMenu();
}

void ProcessScreenMenu(){};

void UpdateScreenMenu(){
  // MENUBAR
  //---------------------------------
  if (global.GetDarkMode() == true) {
    txtButtonDarkModeScreenMenu = "Light";
  } else {
    txtButtonDarkModeScreenMenu = "Dark";
  }

};

void OutputScreenMenu() {
  BeginDrawing();
  ClearBackground(global.GetColorBackground());

  // MENUBAR PANEL
  //---------------------------------
  int buttonDarkModeWidth = global.guiButtonBaseWidth + MeasureText("Light", global.txtSmall);
  if (GuiButton((Rectangle){float(AlignHorizontalRight(panelMenubarScreenMenu, buttonDarkModeWidth, 0)), float(AlignVerticalCenter(panelMenubarScreenMenu, global.guiButtonBaseHeight, 0)), float(buttonDarkModeWidth), float(global.guiButtonBaseHeight)}, txtButtonDarkModeScreenMenu)) {
    global.ToggleDarkMode();
  };

  // STATUSBAR PANEL
  //---------------------------------

  // MAIN PANEL
  //---------------------------------
  int buttonMenuWidth = global.guiButtonBaseWidth + MeasureText("Start Game", DEFAULT);

  if (GuiButton((Rectangle){float(AlignHorizontalCenter(panelMainScreenMenu, buttonMenuWidth, 0)), float(AlignVerticalTop(panelMainScreenMenu, global.guiButtonBaseHeight)), float(buttonMenuWidth), float(global.guiButtonBaseHeight)}, TextFormat("Start Game")) || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
    currentScreen = GAME;
  }

  if (GuiButton((Rectangle){float(AlignHorizontalCenter(panelMainScreenMenu, buttonMenuWidth, 0)), float(AlignVerticalCenter(panelMainScreenMenu, global.guiButtonBaseHeight, 0)), float(buttonMenuWidth), float(global.guiButtonBaseHeight)}, TextFormat("Settings")) || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
    currentScreen = SETTINGS;
  }

  EndDrawing();
}
