#ifndef SCREENS_H
#define SCREENS_H

typedef enum screens
{
    MENU,
    GAME,
    SETTINGS,
} screens;

extern screens currentScreen;

class Screen
{
public:
    virtual void Initialize();
    virtual void Run();
};

#endif
