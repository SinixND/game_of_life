#include "sndScreen.h"
#include "sndLayout.h"

#include "sndConfigs.h"

class Menu : public Screen
{
public:
    Menu();

    Box mainframe;
    Box mainpanel;

private:
    void Process();
    void Update();
    void Render();
};