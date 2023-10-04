#ifndef SCENE_H
#define SCENE_H

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
    void Update();

private:
    virtual void Input();
    virtual void Process();
    virtual void Output();
};
#endif
