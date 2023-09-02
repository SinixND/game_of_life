#include "sndScreen.h"
#include "sndLayout.h"

#include "sndConfigs.h"

class Menu : public Screen
{
public:
    Menu();

    Frame mainframe;

private:
    void Process();
    void Update();
    void Render();
};