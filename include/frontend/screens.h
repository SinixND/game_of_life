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
    void Initialize();
    void Run();
};

#endif