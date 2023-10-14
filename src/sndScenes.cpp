#include "sndScenes.h"
#include "sndGlobals.h"
#include "sndLayout.h"

scenes currentScene = MENU;

void Scene::Initialize()
{
    main.SetOuterLeft(0);
    main.SetOuterTop(0);
    main.SetOuterRight(GetRenderWidth());
    main.SetOuterBottom(GetRenderHeight());
}

void Scene::Update()
{
    Input();
    Process();

    BeginDrawing();
    ClearBackground(global.Getbackground());

    Output();

    EndDrawing();
}

void Scene::Input() {}
void Scene::Process() {}
void Scene::Output() {}