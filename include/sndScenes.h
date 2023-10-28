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
    sndWrapper main;

    virtual void Initialize();
    void Update();

private:
    virtual void Input();
    virtual void Process();
    virtual void Output();
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
#endif
