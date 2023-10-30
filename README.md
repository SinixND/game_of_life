# REQUIREMENTS
- raylib
- raygui
- emscripten

# TODOs
# Current 
[1] Virtual destructor and value initialize variables

# Shortterm
[2] check dynamic behaviour

# Longterm
[0] Rework Gui (responsive)
[1] website containing program (include working emscripten into flask page?)
[1] Release as CS50 project
[2] Save settings (.ini)
[2] Mutlithreading
[2] setting: change resolution
[2] setting: change cell/agent size
[2] separate Game-End screen
[3] setting: start empty
[3] load (examples/patterns? from db)
[3] setting: start paused
[3] live settings (eg. speed)
[3] introduce symbols (eg. for stepping (fw, bw)or darkmode)
[3] Neighbors dont change!, save neighbor-references in agent
[3] Seeding (Lemma, yt: javidx9 - Procedural Generation: Programming The Universe, 15:20)
[3] Stepping FW/BW
[4] screen: about
[4] option: change keybindings
[4] if (IsSomething()) -> encapsulate instead of using a state-variable, eg. AreAgentsFading()
[4] Colors
[4] spontaneous/probability alive, percentage dependent on neighbors, like 3nbrs(50%) - 8nbrs(100%) maybe
    [5] strong/weak cells
[5] 3D
[5] different agent shape
[5] zoom/pan/live grid change

[x] LMB / RMB set alive/dead