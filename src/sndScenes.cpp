// paired
#include "sndScenes.h"

// project specific
#include "sndGlobals.h"
#include "sndConfigs.h"

// project independent
#include "sndLayout.h"

// external
#include <raygui.h>

scenes currentScene = MENU;

Scene::Scene()
    : main {std::make_shared<sxd::Wrapper>("main", 0, 0, GetRenderWidth(), GetRenderHeight())}
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
