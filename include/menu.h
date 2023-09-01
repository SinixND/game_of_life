#include "screen.h"

#include "sndlayout.h"
#include <raygui.h>
#include <raylib.h>

#include "configs.h" // provide object "config" for configurable parameters
#include "globals.h" // provide object "global" for not configurable application parameters

class Menu : public Screen
{
public:
    Frame main_;

    void Run();

private:
    void Process();
    void Update();
    void Render();
};