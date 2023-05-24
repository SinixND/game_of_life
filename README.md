# TODO
## Title Screeen
## Main Menu
### Run
### Rules
#### changeable?
### Settings (initial settings), saveable? (settings.ini)
#### Submenus?
#### window resolution
#### board size
#### life density
#### seed
#### fps (native/vsync, fixed) and/or update interval
#### run/pause/stop/step forward/step backward
#### Color settings
#### 2D/3D
#### cell shape
#### cell age
#### fading cells
#### strong/weak cells
#### additional ideas?
### Credits/About?
### Quit
## (live settings)
### Overlay to adjust variables (what in toolbar, what in overlay?)
### update interval
## Color schemes?
## LMB set alive, RMB set dead
## zoom
## pan

process-loop:

setup/initialise environment
loop: if (alive) {increment adjacents/count adjacents?}
loop: dpendent on adjacentActive -> setStatusNext and setStatusChanging
loop: update status and statusChanging=false