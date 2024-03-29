#include "Scenes.h"

#include "Configs.h"
#include "Globals.h"
#include "raygui.h"
#include "sxdLayout.h"

Scenes currentScene = MENU;

Scene::Scene()
    : main(std::make_shared<sxd::Wrapper>("main", 0, 0, GetRenderWidth(), GetRenderHeight()))
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

void Scene::ProcessInput() {}
void Scene::UpdateState() {}
void Scene::RenderOutput()
{
    if (config.drawFPS == true)
    {
        DrawFPS(main->GetInnerLeft() + 10, main->GetInnerTop() + 10);
    }
}
