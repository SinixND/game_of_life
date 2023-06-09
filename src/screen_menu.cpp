#include "screens.h"

#include "raylib.h"
#include "raygui.h"

#include "globals.h" // provide object "global" for not configurable application parameters
#include "configs.h" // provide object "config" for configurable parameters
#include "panels.h"

// SET GUI ELEMENTS
//---------------------------------
cPanel panelMenubarScreenMenu(config.windowWidth, (global.guiButtonBaseHeight + 20), 0, 0, 10);

const char *txtButtonDarkModeScreenMenu;

cPanel panelMainScreenMenu(config.windowWidth, config.windowHeight - panelMenubarScreenMenu.mPanelHeight, 0, panelMenubarScreenMenu.mPanelHeight, 10);

void ProcessMenuScreen();
void UpdateMenuScreen();
void OutputMenuScreen();

void RunMenuScreen() {
  ProcessMenuScreen();
  UpdateMenuScreen();
  OutputMenuScreen();
}

void ProcessMenuScreen(){};

void UpdateMenuScreen(){
  // MENUBAR
  //---------------------------------
  if (global.GetDarkMode() == true) {
    txtButtonDarkModeScreenMenu = "Light";
  } else {
    txtButtonDarkModeScreenMenu = "Dark";
  }

};

void OutputMenuScreen() {
  BeginDrawing();
  ClearBackground(global.GetColorBackground());

  int rectButtonMenuWidth = global.guiButtonBaseWidth + MeasureText("Start Game", DEFAULT);

  if (GuiButton(Rectangle{float(AlignHorizontalCenter(panelMainScreenMenu, rectButtonMenuWidth)), float(AlignVerticalTop(panelMainScreenMenu, global.guiButtonBaseHeight)), float(rectButtonMenuWidth), float(global.guiButtonBaseHeight)}, TextFormat("Start Game")) || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
    currentScreen = GAME;
  }

  if (GuiButton(Rectangle{float(AlignHorizontalCenter(panelMainScreenMenu, rectButtonMenuWidth)), float(AlignVerticalCenter(panelMainScreenMenu, global.guiButtonBaseHeight)), float(rectButtonMenuWidth), float(global.guiButtonBaseHeight)}, TextFormat("Settings")) || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
    currentScreen = SETTINGS;
  }

  int rectButtonDarkModeWidth = global.guiButtonBaseWidth + MeasureText("Light", global.txtSmall);
  if (GuiButton(Rectangle{float(AlignHorizontalRight(panelMenubarScreenMenu, rectButtonDarkModeWidth, 0)), float(AlignVerticalTop(panelMenubarScreenMenu, 0)), float(rectButtonDarkModeWidth), float(global.guiButtonBaseHeight)}, txtButtonDarkModeScreenMenu)) {
    global.SetDarkMode(!global.GetDarkMode());
  };

  EndDrawing();
}
