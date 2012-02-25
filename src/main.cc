#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include "application.h"

using namespace std;

int main (int argc, char *argv[]) {
  //The following are parameters to pass into Application that
  //can be altered by the command line arguments of this program.
  int fps = 30;
  int frameSkip = 100;
  int level = 1;
  int gravity = 15;
  int spring_c = 2;

  //Check the parameters and set fps, frameSkip, level, gravity, and spring_c
  if (argc > 0) {
    for (int i = 0; i < argc; i++) {
      if (strcmp(argv[i], "-fps") == 0) {
        //-fps suggests another argument is to be passed after it.
        if (i + 1 < argc) {
          istringstream numStream(argv[i + 1]);
          numStream >> fps;

          //Only accept valid numbers; other values will cause the program to exit.
          if (numStream.fail()) {
            cerr << "fps given is not a valid number." << endl;
            return 1;
          }

          i ++;
        } else {
          //If not, show an error message and leave program.
          cerr << "-fps called, but no value is given." << endl;
          return 1;
        }
      } else if (strcmp(argv[i], "-frameskip") == 0) {
        //-frameskip suggests another argument is to be passed after it.
        if (i + 1 < argc) {
          istringstream numStream(argv[i + 1]);
          numStream >> frameSkip;

          //Only accept valid numbers; other values will cause the program to exit.
          if (numStream.fail()) {
            cerr << "frameskip given is not a valid number." << endl;
            return 1;
          }

          i ++;
        } else {
          //If not, show an error message and leave program.
          cerr << "-frameskip called, but no value is given." << endl;
          return 1;
        }
      } else if (strcmp(argv[i], "-level") == 0) {
        //-level suggests another argument is to be passed after it.
        if (i + 1 < argc) {
          istringstream numStream(argv[i + 1]);
          numStream >> level;

          //Only accept valid numbers; other values will cause the program to exit.
          if (numStream.fail()) {
            cerr << "level given is not a valid number." << endl;
            return 1;
          }

          i ++;
        } else {
          //If not, show an error message and leave program.
          cerr << "-level called, but no value is given." << endl;
          return 1;
        }
      } else if (strcmp(argv[i], "-gravity") == 0) {
        //-gravity suggests another argument is to be passed after it.
        if (i + 1 < argc) {
          istringstream numStream(argv[i + 1]);
          numStream >> gravity;

          //Only accept valid numbers; other values will cause the program to exit.
          if (numStream.fail()) {
            cerr << "gravity given is not a valid number." << endl;
            return 1;
          }

          i ++;
        } else {
          //If not, show an error message and leave program.
          cerr << "-gravity called, but no value is given." << endl;
          return 1;
        }
      } else if (strcmp(argv[i], "-spring") == 0) {
        //-spring suggests another argument is to be passed after it.
        if (i + 1 < argc) {
          istringstream numStream(argv[i + 1]);
          numStream >> spring_c;

          //Only accept valid numbers; other values will cause the program to exit.
          if (numStream.fail()) {
            cerr << "spring given is not a valid number." << endl;
            return 1;
          }

          i ++;
        } else {
          //If not, show an error message and leave program.
          cerr << "-spring called, but no value is given." << endl;
          return 1;
        }
      } else if (strcmp(argv[i], "-help") == 0) {
        //-help just prints out all the command line arguments possible
        //for "madbirds"
        cout << "usage:" << endl
             << "    ./madbirds [-fps mmm][-frameskip nnn][-level xxx][-gravity yyy][-sling zzz]" << endl
             << endl
             <<"where mmm, nnn, xxx, yyy, and zzz are integers that you can pass into" << endl
             <<"each option above." << endl
             << endl
             << "-fps mmm:              Sets the frames per seconds that the game will run at." << endl
             << "                       Increasing this value makes the game animate more " << endl
             << "                       smoothly, but it may come at a cost of gameplay speed." << endl
             << endl
             << "-frameskip nnn:        Sets the number of frames to skip when rendering the" << endl
             << "                       game. This has the effect of speeding up the game, but" << endl
             << "                       at a slight loss in the number of frames displayed. Note" << endl
             << "                       that adjusting this should not affect the framerate." << endl
             << endl
             << "-level xxx:            Sets the game to start at level xxx. If the level" << endl
             << "                       specified by xxx does not have an associating .lvl file," << endl
             << "                       the level won't load, and the game will be in a game" << endl
             << "                       over state." << endl
             << endl
             << "-gravity yyy:          Sets the gravity that will work upon objects in the" << endl
             << "                       game. The higher it is, the faster it will be for" << endl
             << "                       objects to fall. The lower it is, the more objects seem" << endl
             << "                       to 'float'." << endl
             << endl
             << "-sling zzz:            Sets the spring constant for the sling used in the game." << endl
             << "                       It's essentially a multiplier for how fast the bird will" << endl
             << "                       launch upon release at a certain distance. The higher" << endl
             << "                       it is, the faster the bird's initial velocity becomes." << endl;

        return 0;
      }
    }
  }


  Application app(fps, frameSkip, spring_c, gravity, level);
  app.run();

  return 0;
}
