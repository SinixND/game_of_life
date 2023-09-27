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
    void Run();

private:
    virtual void Process();
    virtual void Update();
    virtual void Render();
};
#endif
