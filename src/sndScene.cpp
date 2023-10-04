#include "sndScene.h"

#include "sndGlobals.h"

scenes currentScene = MENU;

void Scene::Update(){
    Input();
    Process();

    BeginDrawing();
    ClearBackground(global.Getbackground());

    Output();

    EndDrawing();
}

void Scene::Input(){}
void Scene::Process(){}
void Scene::Output(){}
