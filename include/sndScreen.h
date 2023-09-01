#ifndef SCREEN_H
#define SCREEN_H

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
    void Run();
};
#endif