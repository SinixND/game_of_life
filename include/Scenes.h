#ifndef SCENE_H_202311201531
#define SCENE_H_202311201531

#include "raylib.h"
#include "sxdLayout.h"
#include <vector>

typedef enum
{
    MENU,
    GAME,
    SETTINGS,
} Scenes;

extern Scenes currentScene;

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

    void RenderStatusbar();
    void RenderBody();
    void RenderPauseOverlay();
};
//-------------------------------------
#endif