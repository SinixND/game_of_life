#include "sndScreen.h"

#include "sndGlobals.h"

screens currentScreen = MENU;

void Screen::Run(){
    Process();
    Update();

    BeginDrawing();
    ClearBackground(global.Getbackground());

    Render();

    EndDrawing();
}

void Screen::Process(){}
void Screen::Update(){}
void Screen::Render(){}
