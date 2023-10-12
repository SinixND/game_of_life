#include "sndScene.h"

#include "sndConfigs.h"
#include "sndLayout.h"

class Menu : public Scene
{
public:
    Menu();

    sndWrapper menubar;
    sndWrapper statusbar;
    sndWrapper title;
    sndWrapper menu;

    //sndButton darkMode;

private:
    void Input();
    void Process();
    void Output();
};