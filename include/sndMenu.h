#include "sndScreen.h"
#include "sndLayout.h"

#include "sndConfigs.h"

class Menu : public Screen
{
public:
    Menu();

    WrapperStatic mainframe;
    WrapperDynamic mainpanel;

private:
    void Process();
    void Update();
    void Render();
};