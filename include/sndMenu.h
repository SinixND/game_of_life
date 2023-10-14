#include "sndScene.h"

#include "sndLayout.h"

class Menu : public Scene
{
public:
    Menu();

    sndWrapper menubar;
    sndWrapper statusbar;
    sndWrapper title;
    sndWrapper content;

    //sndButton darkMode;
    void Initialize();

private:
    void Input();
    void Process();
    void Output();
};