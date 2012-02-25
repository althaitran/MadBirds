#ifndef __MAINGRAPHICS_H__
#define __MAINGRAPHICS_H__

#include "graphics.h"
#include "xinfo.h"

//Using MainGraphics implements XWindows to display the game.
class MainGraphics: public Graphics {
  XInfo *xinfo;  //Holds info on the XWindow to draw on. Does not
                 //get deleted when the graphics object is deleted.
public:
  void DrawBird(int, int);
  void DrawBlock(int, int);
  void DrawTarget(int, int, bool);
  void DrawTerrain(int, int, int, int);
  void DrawSling(int, int, int, int);
  void DrawTrajectory(int, int);
  void DrawForeground();
  void DrawBackground();
  void DrawGameEnd();
  void DrawLevel(int, int, int);
  void DrawScore(int, int, int);
  MainGraphics(XInfo *);
  ~MainGraphics();
};

#endif
