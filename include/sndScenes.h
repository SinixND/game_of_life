#ifndef SCENE_H
#define SCENE_H

// project independent
#include "sndLayout.h"

// external
#include <raylib.h>

// std
#include <vector>

typedef enum scenes
{
    MENU,
    GAME,
    SETTINGS,
} scenes;

extern scenes currentScene;

class Scene
{
public:
    Scene();
    void Initialize();
    virtual void Update();

protected:
    std::shared_ptr<sxd::Wrapper> main;
    sxd::Wrapper* currentWrapper;

    void ProcessInput();
    void UpdateState();
    void RenderOutput();
};

// SCENES
//-------------------------------------
class Menu : public Scene
{
public:
    Menu();

    std::shared_ptr<sxd::Wrapper> menubar;
    std::shared_ptr<sxd::Wrapper> head;
    std::shared_ptr<sxd::Wrapper> body;

    void Initialize();
    void Update() override;

private:
    void ProcessInput();
    void UpdateState();
    void RenderOutput();
};

class Settings : public Scene
{
public:
    Settings();

    std::shared_ptr<sxd::Wrapper> menubar;
    std::shared_ptr<sxd::Wrapper> body;

    void Initialize();
    void Update() override;

private:
    void ProcessInput();
    void UpdateState();
    void RenderOutput();
};

class Game : public Scene
{
public:
    Game();

    std::shared_ptr<sxd::Wrapper> menubar;
    std::shared_ptr<sxd::Wrapper> controlbar;
    std::shared_ptr<sxd::Wrapper> statusbar;
    std::shared_ptr<sxd::Wrapper> body;

    void Initialize();
    void Update() override;

private:
    void ProcessInput();
    void UpdateState();
    void RenderOutput();

    void RenderScreenGameStatusbar();
    void RenderScreenGameMainPanel();
    void RenderPauseOverlay();
};
//-------------------------------------
#endif