#include "sndScene.h"

#include "sndGlobals.h"

scenes currentScene = MENU;

void Scene::Run(){
    Process();
    Update();

    BeginDrawing();
    ClearBackground(global.Getbackground());

    Render();

    EndDrawing();
}

void Scene::Process(){}
void Scene::Update(){}
void Scene::Render(){}
