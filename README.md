# REQUIREMENTS
- raylib
- raygui
- emscripten

# TODOs
# Current 
[0] add overlay slider for:

- init density
- birth threshold
- survive threshold
- drown threshold
- iterations

# Shortterm

# Longterm (probably wont develop further)
[1] website containing program (include working emscripten into flask page?)

[1] Release as CS50 project

[2] Save settings (.ini)

[2] separate Game-End screen

[3] setting: start empty

[3] load (examples/patterns? from db)

[3] setting: start paused

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

# Done

[x] Virtual destructor and value initialize variables

[x] check dynamic behaviour

[x] Rework Gui (responsive)

[x] implement custom symbols (darkmode) locally!

[x] LMB / RMB set alive/dead

[x] implement example (debug) grid

[x] Mutlithreading (address sanitizer states error: leak if window size is reduced); Setting disabled, logic kept

[x] refactor list initialization

[x] include github.com/google/benchmark
