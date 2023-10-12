#include "sndScene.h"

#include "sndGlobals.h"

#include "sndLayout.h"

scenes currentScene = MENU;

Scene::Scene()
    : main(
          0,
          0,
          GetRenderWidth(),
          GetRenderHeight())
{}

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
