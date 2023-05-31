# TODO
- Github pages? (emscripten)
0. Screens
    - Main [done]
      - Start [done]
      - Settings
      - About
      - Exit
0. Settings
    - Keybindings
    - Gamesettings
        0. start empty
        0. start paused
    - Save settings (.ini)
0. Menubar
    - Reset
    - Pause [done]
    - live settings (eg. speed)
0. Overlay
    - Quit
0. Performance
    - Mutlithreading
    - Speedup Output?
0. Code
    - change to: for(auto it = v.cbegin(), end = v.cend(); it != end; ++it) OR (auto& i : v)? (iterator needed? check neighbor for-loop first)
    - Neighbors == vector of references/pointers, agent-constructor with reference to board? But is it better than current anyway?
    - introduce board class?
    - auto space after opening/before closing bracket in parameter list
    - Structure EVA 
    - doA(), doB(), f(call doA() & doB()) for core gamesteps (eg. determine next agents[] state)
    - constants? CAPITAL_LETTERS
0. Features
    - LMB / RMB set alive/dead
    - Seeding (seed[1-99999] * fieldSize; srand(seed*fieldSize)-fieldSize + fieldNumber)
    - Pausing [done]
    - Stepping FW/BW
    - Darkmode (switch) [done]
    - Colors
    - 3D
    - different agent shape
    - agent age/fading [done]
    - strong/weak cells
    - zoom/pan/live grid change
