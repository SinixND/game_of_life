#include "sndScenes.h"
#include "sndGlobals.h"
#include "sndLayout.h"

scenes currentScene = MENU;

void Scene::Initialize(){}
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

// SCENES
//-------------------------------------

Menu::Menu()
{
    Initialize();
}

void Menu::Initialize()
{
    main.SetOuterLeft(0);
    main.SetOuterTop(0);
    main.SetOuterRight(GetRenderWidth());
    main.SetOuterBottom(GetRenderHeight());

    sndWrapper menubar(
        main.GetInnerLeft(),
        main.GetInnerTop(),
        main.GetInnerRight(),
        static_cast<int>(main.GetInnerTop() + global.guiButtonBaseHeight + 2 * main.GetFrameWeight()));

    sndWrapper statusbar(
        main.GetInnerLeft(),
        static_cast<int>(main.GetInnerBottom() - (global.guiButtonBaseHeight + 2 * main.GetFrameWeight())),
        main.GetInnerRight(),
        main.GetInnerBottom());

    sndWrapper title(
        main.GetInnerLeft(),
        menubar.GetOuterBottom(),
        main.GetInnerRight(),
        statusbar.GetOuterTop() / 3);

    sndWrapper content(
        main.GetInnerLeft(),
        title.GetOuterBottom(),
        main.GetInnerRight(),
        statusbar.GetOuterTop());

    menubar.SetMargin(1);
    menubar.SetBorder(3);
    menubar.SetPadding(1);
    statusbar.SetMargin(1);
    statusbar.SetBorder(3);
    statusbar.SetPadding(1);
    title.SetMargin(1);
    title.SetBorder(3);
    title.SetPadding(1);

    main.ClearWrappers();
    main.AddWrapper(menubar);
    main.AddWrapper(statusbar);
    main.AddWrapper(title);
    main.AddWrapper(content);
}

void Menu::Input() {}
void Menu::Process() {}
void Menu::Output()
{
    main.Render();
    // sndButton darkMode("DarkMode", global.textSizeDefault);
    // menubar.Append(darkMode, (sndAlign)(CENTER_HORIZONTAL | CENTER_VERTICAL), 0);
}
