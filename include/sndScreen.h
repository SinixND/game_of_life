#ifndef SCREEN_H
#define SCREEN_H

#include <vector>

//typedef enum screens
//{
    //MENU,
    //GAME,
    //SETTINGS,
//} screens;

//extern screens currentScreen;

class Screen
{
public:
    void Run();

private:
    virtual void Process();
    virtual void Update();
    virtual void Render();
};
#endif