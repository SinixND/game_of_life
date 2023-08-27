#include "screens.h"
#include <iostream>

#include "raygui.h"
#include <raylib.h>

#include "configs.h" // provide object "config" for configurable parameters
#include "globals.h" // provide object "global" for not configurable application parameters
#include "panels.h"

// SET GUI ELEMENTS
//---------------------------------
Panel panelMenubarScreenSettings(0, 0, config.windowWidth, (global.guiButtonBaseHeight + 20), 10);
Panel panelStatusbarScreenSettings(0, (config.windowHeight - (global.guiButtonBaseHeight + 20)), config.windowWidth, (global.guiButtonBaseHeight + 20), 10);
Panel panelMainScreenSettings(0, panelMenubarScreenSettings.height_, config.windowWidth, config.windowHeight - panelMenubarScreenSettings.height_ - panelStatusbarScreenSettings.height_, 10);

const char* txtButtonBackScreenSettings = "Back";
const char* txtButtonDarkModeScreenSettings;

void ProcessScreenSettings();
void UpdateScreenSettings();
void RenderScreenSettings();

void RunScreenSettings()
{
    ProcessScreenSettings();
    UpdateScreenSettings();
    RenderScreenSettings();
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

void RenderScreenSettingsMenubar();
void RenderScreenSettingsMainPanel();

void RenderScreenSettings()
{
    BeginDrawing();
    ClearBackground(global.GetColorBackground());

    RenderScreenSettingsMenubar();

    // STATUSBAR PANEL
    //---------------------------------

    RenderScreenSettingsMainPanel();

    EndDrawing();
}

void RenderScreenSettingsMenubar()
{
    int buttonBackWidth = global.guiButtonBaseWidth + MeasureText(txtButtonBackScreenSettings, global.textSizeDefault);
    Rectangle backButtonRec{
            (float)AlignHorizontalLeft(panelMenubarScreenSettings, 0),
            (float)AlignVerticalCenter(panelMenubarScreenSettings, global.guiButtonBaseHeight, 0),
            (float)buttonBackWidth,
            (float)global.guiButtonBaseHeight};

    if (GuiButton(backButtonRec, txtButtonBackScreenSettings))
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

void RenderScreenSettingsMainPanel()
{
    // Helpers for positioning gui elements
    float guiCursor = panelMainScreenSettings.GetContentTopY();
    auto UpdateGuiCursor = [](float& refGuiCursor, float inputY)
    { refGuiCursor += inputY + 10.0f; };

    // CATEGORY: APPLICATION SETTINGS
    // window resolution (width, height)

    // target fps

    // CATEGORY: AGENTS AND ENVIRONMENT
    DrawLine(panelMainScreenSettings.GetContentLeftX(), guiCursor, panelMainScreenSettings.GetContentRightX(), guiCursor, global.GetColorForeground());

    UpdateGuiCursor(guiCursor, 5);

    const char* txtLabelGrid = "GAME OF LIFE";

    GuiLabel(
        (Rectangle){
            AlignHorizontalCenter(panelMainScreenSettings, (float)MeasureText(txtLabelGrid, global.textSizeDefault), 0),
            guiCursor,
            (float)MeasureText(txtLabelGrid, global.textSizeDefault),
            global.textSizeDefault},
        txtLabelGrid);

    UpdateGuiCursor(guiCursor, global.textSizeDefault);

    DrawLine(panelMainScreenSettings.GetContentLeftX(), guiCursor, panelMainScreenSettings.GetContentRightX(), guiCursor, global.GetColorForeground());

    UpdateGuiCursor(guiCursor, global.textSizeDefault / 2);

    // SETTING: FADING AGENTS
    const char* txtCheckBoxFadingAgents = "Fading agents:";

    GuiLabel(
        (Rectangle){
            panelMainScreenSettings.GetContentLeftX(),
            guiCursor,
            (float)MeasureText(txtCheckBoxFadingAgents, global.textSizeDefault),
            global.textSizeDefault},
        txtCheckBoxFadingAgents);

    config.fadingAgents = GuiCheckBox(
        (Rectangle){
            panelMainScreenSettings.GetCenterX(),
            guiCursor,
            global.textSizeDefault,
            global.textSizeDefault},
        NULL, config.fadingAgents);

    UpdateGuiCursor(guiCursor, global.textSizeDefault);

    // INITIAL LIFE DENSITY
    const char* txtSpinnerInitialLifeDensity = "Initial life density:";

    GuiLabel(
        (Rectangle){
            panelMainScreenSettings.GetContentLeftX(),
            guiCursor,
            (float)MeasureText(txtSpinnerInitialLifeDensity, global.textSizeDefault),
            global.textSizeDefault},
        txtSpinnerInitialLifeDensity);

    GuiSpinner(
        (Rectangle){
            panelMainScreenSettings.GetCenterX(),
            guiCursor,
            100,
            global.textSizeDefault},
        NULL, &config.initialLifeDensity, 0, 100, false);

    UpdateGuiCursor(guiCursor, global.textSizeDefault * 1.5);

    // CATEGORY: DISPLAY
    DrawLine(panelMainScreenSettings.GetContentLeftX(), guiCursor, panelMainScreenSettings.GetContentRightX(), guiCursor, global.GetColorForeground());

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

    DrawLine(panelMainScreenSettings.GetContentLeftX(), guiCursor, panelMainScreenSettings.GetContentRightX(), guiCursor, global.GetColorForeground());

    UpdateGuiCursor(guiCursor, global.textSizeDefault / 2);

    // SETTING: GAP BETWEEN AGENTS
    const char* txtLabelAgentGap = "Gap between agents:";

    GuiLabel(
        (Rectangle){
            panelMainScreenSettings.GetContentLeftX(),
            guiCursor,
            (float)MeasureText(txtLabelAgentGap, global.textSizeDefault),
            global.textSizeDefault},
        txtLabelAgentGap);

    GuiSpinner(
        (Rectangle){
            panelMainScreenSettings.GetCenterX(),
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
