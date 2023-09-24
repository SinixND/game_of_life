#include "sndScreen.h"
#include "sndLayout.h"

#include "sndConfigs.h"

class Menu : public Screen
{
public:
    Menu();

    Wrapper mainframe;
    Wrapper mainpanel;

private:
    void Process();
    void Update();
    void Render();
};