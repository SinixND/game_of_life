#include "sndScreen.h"

#include "sndConfigs.h"
#include "sndLayout.h"

class Menu : public Screen
{
public:
    Menu();

    Wrapper main;
    Wrapper menubar;
    Wrapper statusbar;
    Wrapper content;

private:
    void Process();
    void Update();
    void Render();
};