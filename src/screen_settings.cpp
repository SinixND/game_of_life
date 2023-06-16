#include "screens.h"
#include <iostream>

#include "raygui.h"
#include <raylib.h>

#include "configs.h" // provide object "config" for configurable parameters
#include "globals.h" // provide object "global" for not configurable application parameters
#include "panels.h"

// SET GUI ELEMENTS
//---------------------------------
cPanel panelMenubarScreenSettings(0, 0, config.windowWidth, (global.guiButtonBaseHeight + 20), 10);
cPanel panelStatusbarScreenSettings(0, (config.windowHeight - (global.guiButtonBaseHeight + 20)), config.windowWidth, (global.guiButtonBaseHeight + 20), 10);
cPanel panelMainScreenSettings(0, panelMenubarScreenSettings.panelHeight_, config.windowWidth, config.windowHeight - panelMenubarScreenSettings.panelHeight_ - panelStatusbarScreenSettings.panelHeight_, 10);

const char *txtButtonBackScreenSettings = "Back";
const char *txtButtonDarkModeScreenSettings;

void ProcessScreenSettings();
void UpdateScreenSettings();
void OutputScreenSettings();

void RunScreenSettings()
{
  ProcessScreenSettings();
  UpdateScreenSettings();
  OutputScreenSettings();
}

void ProcessScreenSettings(){};

void UpdateScreenSettings()
{
  // MENUBAR
  //---------------------------------
  if (global.GetDarkMode() == true)
  {
    txtButtonDarkModeScreenSettings = "Light";
  }
  else
  {
    txtButtonDarkModeScreenSettings = "Dark";
  }
};

void OutputScreenSettings()
{
  BeginDrawing();
  ClearBackground(global.GetColorBackground());

  // MENUBAR PANEL
  //---------------------------------
  int buttonBackWidth = global.guiButtonBaseWidth + MeasureText(txtButtonBackScreenSettings, DEFAULT);
  if (GuiButton((Rectangle){float(AlignHorizontalLeft(panelMenubarScreenSettings, 0)), float(AlignVerticalCenter(panelMenubarScreenSettings, global.guiButtonBaseHeight, 0)), float(buttonBackWidth), float(global.guiButtonBaseHeight)}, txtButtonBackScreenSettings))
  {
    currentScreen = MENU;
  };

  int buttonDarkModeWidth = global.guiButtonBaseWidth + MeasureText("Light", global.txtSmall);
  if (GuiButton((Rectangle){float(AlignHorizontalRight(panelMenubarScreenSettings, buttonDarkModeWidth, 0)), float(AlignVerticalCenter(panelMenubarScreenSettings, global.guiButtonBaseHeight, 0)), float(buttonDarkModeWidth), float(global.guiButtonBaseHeight)}, txtButtonDarkModeScreenSettings))
  {
    global.ToggleDarkMode();
  };

  // STATUSBAR PANEL
  //---------------------------------
  GuiPanel(panelMainScreenSettings, "Settings");

  // MAIN PANEL
  //---------------------------------
  //config.fadingAgents = GuiCheckBox((Rectangle){float(panelMainScreenSettings.GetPanelContentLeftX()), float(panelMainScreenSettings.GetPanelContentTopY()), global.txtSmall, global.txtSmall}, "Fading Agents", config.fadingAgents);

  // Rectangle rectScrollPanelBounds = Rectangle{10, 10, 100, 100};
  // Rectangle rectScrollPanelContent = Rectangle{10, 10, 100, 500};
  // Vector2 panelScroll = { 99, -20 };
  // GuiScrollPanel(rectScrollPanelBounds, "Text", rectScrollPanelContent, &panelScroll);

  EndDrawing();
}
