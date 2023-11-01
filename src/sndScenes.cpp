#include "sndScenes.h"
#include "sndGlobals.h"
#include "sndLayout.h"

scenes currentScene = MENU;

Scene::Scene()
    : main(std::make_shared<sndWrapper>("main", 0, 0, GetRenderWidth(), GetRenderHeight()))
{
}

void Scene::Initialize()
{
    main->ClearWrappers();

    main->ResizeOuterLeft(0);
    main->ResizeOuterTop(0);
    main->ResizeOuterRight(GetRenderWidth());
    main->ResizeOuterBottom(GetRenderHeight());
}

void Scene::Update() {}

void Scene::Input() {}
void Scene::Process() {}
void Scene::Output() {}