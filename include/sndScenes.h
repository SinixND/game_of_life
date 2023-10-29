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
    virtual void Initialize();
    void Update();

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

    void Initialize();

private:
    void Input();
    void Process();
    void Output();
};

class Settings : public Scene
{
public:
    Settings();

    void Initialize();

private:
    void Input();
    void Process();
    void Output();
};
//-------------------------------------
#endif