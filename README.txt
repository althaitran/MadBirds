Gameplay
--------
For my implementation of Mad Birds, the user can use as many birds as
necessary to get all the targets. 10 points are subtracted for every
bird slung, while 100 points are awarded for every target hit. Note that
the user can choose to sling a bird at any moment, even in the middle of
another bird's flight. However, as only one bird is ever used in this game,
that bird in flight will leave flight when the user attempts to sling another
bird. Also, the bird will not disappear after staying on the ground for a
period of time; it is up to the user when the next shot will take place.

To end gameplay at any time, press the 'q' key.


Compilation
-----------
To compile, use the following:

"make"

The output file will be called "madbirds".

Also, to clean the .o files and output file from the directory, call the
following:

"make clean"


Command Line Arguments
----------------------
The MadBirds program can be called as such:

./madbirds [-fps mmm][-frameskip nnn][-level xxx][-gravity yyy][-sling zzz]

where mmm, nnn, xxx, yyy, and zzz are integers that you can pass into
each option above.

-fps mmm:             Sets the frames per seconds that the game will run at.
                       Increasing this value makes the game animate more
                       smoothly, but it may come at a cost of gameplay speed.

-frameskip nnn:        Sets the number of frames to skip when rendering the
                       game. This has the effect of speeding up the game, but
                       at a slight loss in the number of frames displayed. Note
                       that adjusting this should not affect the framerate.

-level xxx:            Sets the game to start at level xxx. If the level
                       specified by xxx does not have an associating .lvl file,
                       the level won't load, and the game will be in a game
                       over state.

-gravity yyy:          Sets the gravity that will work upon objects in the
                       game. The higher it is, the faster it will be for
                       objects to fall. The lower it is, the more objects seem
                       to "float".

-sling zzz:            Sets the spring constant for the sling used in the game.
                       It's essentially a multiplier for how fast the bird will
                       launch upon release at a certain distance. The higher
                       it is, the faster the bird's initial velocity becomes.


Moving Between Levels
---------------------
In order to move between levels easily, you have to pass in the
command line argument, "-level x", to reach level x, which can
be of your choosing. If you go to a level that doesn't exist, then
the game will assume that all levels have been reached, and will
show a game over screen.


Enhancements
------------
One of the enhancements I've made was the creation of a level generator,
which reads off of .lvl files to determine how to create the level. With
this, the user can create his own levels to test out. To take advantage of
this, simply create a .lvl file under the "level" folder. Examples of the
syntax used to create the levels can be found in the levels 1 to 3 files,
and there is an instruction file called "instructions.txt" that indicate
the syntax used. This all required the creation of a simple parser, which
I devised under the LvlTextGen (Level Text Generator) class. This was
beyond what was asked for in this assignment.

Another enhancement is that the bird can bounce off of terrain and blocks.
essentially obeying the laws of physics. In particular, I've had to create
a physics class to take care of the different types of collisions in the
game (bird vs. wall, bird vs. terrain, bird vs. target, etc) and store the
value of gravitational force, which is applied to all game components like
birds, blocks and targets, but not terrain.

Presence of gravity and mass also allows for the presence of friction in this
game, and this can be seen when the bird bounces off the ground. You'll notice
that the bird will slowly reduce its horizontal velocity every time it hits the
ground instead of keeping the same velocity. The same can be said for vertical
velocity, as the bird doesn't bounce as high up as it was dropped (unless it was
slung to the ground), mainly due to the presence of friction applied in this game.
This is, yet, another work of the physics engine which dictates the contact
between objects (here, bird vs. terrain). Different objects see different effects,
as a result, as blocks barely bounce off the ground because they're heavier than 
birds or targets.

