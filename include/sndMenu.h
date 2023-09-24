#include "sndScreen.h"
#include "sndLayout.h"

#include "sndConfigs.h"

class Menu : public Screen
{
public:
    Menu();

    Wrapper main;
    Wrapper menubar;

private:
    void Process();
    void Update();
    void Render();
};