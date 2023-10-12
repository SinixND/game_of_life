#ifndef SCENE_H
#define SCENE_H

#include <vector>

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

    sndWrapper main;

    void Update();

private:
    virtual void Input();
    virtual void Process();
    virtual void Output();
};
#endif
