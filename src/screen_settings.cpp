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

const char* txtButtonBackScreenSettings = "Back";
const char* txtButtonDarkModeScreenSettings;

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

void OutputScreenSettingsMenubar();
void OutputScreenSettingsMainPanel();

void OutputScreenSettings()
{
    BeginDrawing();
    ClearBackground(global.GetColorBackground());

    OutputScreenSettingsMenubar();

    // STATUSBAR PANEL
    //---------------------------------

    OutputScreenSettingsMainPanel();

    EndDrawing();
}

void OutputScreenSettingsMenubar()
{
    int buttonBackWidth = global.guiButtonBaseWidth + MeasureText(txtButtonBackScreenSettings, global.textSizeDefault);
    if (GuiButton(
            (Rectangle){
                (float)AlignHorizontalLeft(panelMenubarScreenSettings, 0),
                (float)AlignVerticalCenter(panelMenubarScreenSettings, global.guiButtonBaseHeight, 0),
                (float)buttonBackWidth,
                (float)global.guiButtonBaseHeight},
            txtButtonBackScreenSettings))
    {
        currentScreen = MENU;
    };

    int buttonDarkModeWidth = global.guiButtonBaseWidth + MeasureText("Light", global.textSizeDefault);
    if (GuiButton(
            (Rectangle){
                (float)AlignHorizontalRight(panelMenubarScreenSettings, buttonDarkModeWidth, 0),
                (float)AlignVerticalCenter(panelMenubarScreenSettings, global.guiButtonBaseHeight, 0),
                (float)buttonDarkModeWidth,
                (float)global.guiButtonBaseHeight},
            txtButtonDarkModeScreenSettings))
    {
        global.ToggleDarkMode();
    };
}

void OutputScreenSettingsMainPanel()
{
    // Helpers for positioning gui elements
    float guiCursor = panelMainScreenSettings.GetPanelContentTopY();
    auto UpdateGuiCursor = [](float& refGuiCursor, float inputY)
    { refGuiCursor += inputY + 10.0f; };

    // CATEGORY: APPLICATION SETTINGS
    // window resolution (width, height)

    // target fps

    // CATEGORY: AGENTS AND ENVIRONMENT
    DrawLine(panelMainScreenSettings.GetPanelContentLeftX(), guiCursor, panelMainScreenSettings.GetPanelContentRightX(), guiCursor, global.GetColorForeground());

    UpdateGuiCursor(guiCursor, 5);

    const char* txtLabelGameOfLife = "GAME OF LIFE";

    GuiLabel(
        (Rectangle){
            AlignHorizontalCenter(panelMainScreenSettings, (float)MeasureText(txtLabelGameOfLife, global.textSizeDefault), 0),
            guiCursor,
            (float)MeasureText(txtLabelGameOfLife, global.textSizeDefault),
            global.textSizeDefault},
        txtLabelGameOfLife);

    UpdateGuiCursor(guiCursor, global.textSizeDefault);

    DrawLine(panelMainScreenSettings.GetPanelContentLeftX(), guiCursor, panelMainScreenSettings.GetPanelContentRightX(), guiCursor, global.GetColorForeground());

    UpdateGuiCursor(guiCursor, global.textSizeDefault / 2);

    // SETTING: FADING AGENTS
    const char* txtCheckBoxFadingAgents = "Fading agents:";

    GuiLabel(
        (Rectangle){
            panelMainScreenSettings.GetPanelContentLeftX(),
            guiCursor,
            (float)MeasureText(txtCheckBoxFadingAgents, global.textSizeDefault),
            global.textSizeDefault},
        txtCheckBoxFadingAgents);

    config.fadingAgents = GuiCheckBox(
        (Rectangle){
            panelMainScreenSettings.GetPanelCenterX(),
            guiCursor,
            global.textSizeDefault,
            global.textSizeDefault},
        NULL, config.fadingAgents);

    UpdateGuiCursor(guiCursor, global.textSizeDefault);

    // INITIAL LIFE DENSITY
    const char* txtSpinnerInitialLifeDensity = "Initial life density:";

    GuiLabel(
        (Rectangle){
            panelMainScreenSettings.GetPanelContentLeftX(),
            guiCursor,
            (float)MeasureText(txtSpinnerInitialLifeDensity, global.textSizeDefault),
            global.textSizeDefault},
        txtSpinnerInitialLifeDensity);

    GuiSpinner(
        (Rectangle){
            panelMainScreenSettings.GetPanelCenterX(),
            guiCursor,
            100,
            global.textSizeDefault},
        NULL, &config.initialLifeDensity, 0, 100, false);

    UpdateGuiCursor(guiCursor, global.textSizeDefault * 1.5);

    // CATEGORY: DISPLAY
    DrawLine(panelMainScreenSettings.GetPanelContentLeftX(), guiCursor, panelMainScreenSettings.GetPanelContentRightX(), guiCursor, global.GetColorForeground());

    UpdateGuiCursor(guiCursor, 5);

    const char* txtLabelDisplay = "DISPLAY";

    GuiLabel(
        (Rectangle){
            AlignHorizontalCenter(panelMainScreenSettings, (float)MeasureText(txtLabelDisplay, global.textSizeDefault), 0),
            guiCursor,
            (float)MeasureText(txtLabelDisplay, global.textSizeDefault),
            global.textSizeDefault},
        txtLabelDisplay);

    UpdateGuiCursor(guiCursor, global.textSizeDefault);

    DrawLine(panelMainScreenSettings.GetPanelContentLeftX(), guiCursor, panelMainScreenSettings.GetPanelContentRightX(), guiCursor, global.GetColorForeground());

    UpdateGuiCursor(guiCursor, global.textSizeDefault / 2);

    // SETTING: GAP BETWEEN AGENTS
    const char* txtLabelAgentGap = "Gap between agents:";

    GuiLabel(
        (Rectangle){
            panelMainScreenSettings.GetPanelContentLeftX(),
            guiCursor,
            (float)MeasureText(txtLabelAgentGap, global.textSizeDefault),
            global.textSizeDefault},
        txtLabelAgentGap);

    GuiSpinner(
        (Rectangle){
            panelMainScreenSettings.GetPanelCenterX(),
            guiCursor,
            100,
            global.textSizeDefault},
        NULL, &config.agentGap, 0, 1000, false);

    // dimension (width, height, borderwidth, gap)

    // agent gap

    // initial life density

    // CONTROLS
    // tick time

    // Rectangle rectScrollPanelBounds = Rectangle{10, 10, 100, 100};
    // Rectangle rectScrollPanelContent = Rectangle{10, 10, 100, 500};
    // Vector2 panelScroll = { 99, -20 };
    // GuiScrollPanel(rectScrollPanelBounds, "Text", rectScrollPanelContent, &panelScroll);
}