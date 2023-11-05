#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <raylib.h>
#include "sndLayout.h"

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
    std::shared_ptr<sndWrapper> main;

    void Input();
    void Process();
    void Output();
};

// SCENES
//-------------------------------------
class Menu : public Scene
{
public:
    Menu();

    std::shared_ptr<sndWrapper> menubar;
    std::shared_ptr<sndWrapper> head;
    std::shared_ptr<sndWrapper> body;

    void Initialize();
    void Update() override;

private:
    void Input();
    void Process();
    void Output();
};

class Settings : public Scene
{
public:
    Settings();

    std::shared_ptr<sndWrapper> menubar;
    std::shared_ptr<sndWrapper> body;

    void Initialize();
    void Update() override;

private:
    void Input();
    void Process();
    void Output();
};

class Game : public Scene
{
public:
    Game();

    std::shared_ptr<sndWrapper> menubar;
    std::shared_ptr<sndWrapper> statusbar;
    std::shared_ptr<sndWrapper> body;

    void Initialize();
    void Update() override;

private:
    void Input();
    void Process();
    void Output();

    void RenderPauseOverlay();
};
//-------------------------------------
#endif