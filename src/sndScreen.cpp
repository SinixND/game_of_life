#include "sndScreen.h"

#include <raygui.h>

#include "sndGlobals.h"

screens currentScreen = MENU;

void Screen::Run(){
    Process();
    Update();

    BeginDrawing();
    ClearBackground(global.GetColorBackground());

    Render();

    EndDrawing();
}

void Screen::Process(){}
void Screen::Update(){}
void Screen::Render(){}
