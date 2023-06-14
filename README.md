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
0. Code
    - Fade(BLACK, 0.5f) for fadingAgents
    - if (IsSomething()) -> encapsulate instead of using a state-variable, eg. AreAgentsFading()
    - Neighbors dont change!, save neighbor-references in agent
    - introduce board to agents class, no higher-dimension info in agent class?
    - doA(), doB(), f(call doA() & doB()) for core gamesteps (eg. determine next agents[] state)
    - auto space after opening/before closing bracket in parameter list
    - Structure EVA 
0. Features
    - LMB / RMB set alive/dead
    - Seeding (seed[1-99999] * fieldSize; srand(seed*fieldSize)-fieldSize + fieldNumber)
    - Pausing [done]
    - Stepping FW/BW
    - Darkmode (switch) [done]
    - spontaneous/probability alive, percentage dependent on neighbors, like 3ngb(50%) - 8ngb(100%) maybe
    - Colors
    - 3D
    - different agent shape
    - agent age/fading [done]
    - strong/weak cells
    - zoom/pan/live grid change
