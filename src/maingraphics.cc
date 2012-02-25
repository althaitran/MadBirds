#include <string>
#include <sstream>
#include "maingraphics.h"

using namespace std;

//Method to draw a bird object.
void MainGraphics::DrawBird(int x, int y){
  XPoint *polyPoints;  //Used to store polygon points (any)

  //Draw outline
  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[Black]);
  XFillArc(xinfo->disp, xinfo->double_buffer, xinfo->gc, x - 1, y - 1, 32, 32, 0*64, 360*64);

  //Draw body
  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[Red]);
  XFillArc(xinfo->disp, xinfo->double_buffer, xinfo->gc, x, y, 30, 30, 0*64, 360*64);

  //Draw beak
  polyPoints = new XPoint[3];
  polyPoints[0].x = x + 19;
  polyPoints[0].y = y + 10;
  polyPoints[1].x = x + 32;
  polyPoints[1].y = y + 20;
  polyPoints[2].x = x + 16;
  polyPoints[2].y = y + 19;
  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[Yellow]);
  XFillPolygon(xinfo->disp, xinfo->double_buffer, xinfo->gc, polyPoints, 3, Complex, CoordModeOrigin);
  delete [] polyPoints;

  //Draw frown
  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[Black]);
  XSetLineAttributes(xinfo->disp, xinfo->gc, 1, LineSolid, CapRound, JoinRound);
  XDrawLine(xinfo->disp, xinfo->double_buffer, xinfo->gc, x + 32, y + 20, x+ 18, y + 17);
  XDrawLine(xinfo->disp, xinfo->double_buffer, xinfo->gc, x + 18, y + 17, x + 17, y + 21);
 
  //Draw eyes
  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[White]);
  XFillArc(xinfo->disp, xinfo->double_buffer, xinfo->gc, x + 12, y + 8, 6, 6, 0*64, 360*64);
  XFillArc(xinfo->disp, xinfo->double_buffer, xinfo->gc, x + 20, y + 7, 5, 5, 0*64, 360*64);
  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[Black]);
  XFillArc(xinfo->disp, xinfo->double_buffer, xinfo->gc, x + 14, y + 9, 3, 3, 0*64, 360*64);
  XFillArc(xinfo->disp, xinfo->double_buffer, xinfo->gc, x + 22, y + 8, 3, 3, 0*64, 360*64);

  //Draw eyebrows
  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[Black]);
  XSetLineAttributes(xinfo->disp, xinfo->gc, 2, LineSolid, CapRound, JoinRound);
  XDrawLine(xinfo->disp, xinfo->double_buffer, xinfo->gc, x + 13, y + 5, x+ 17, y + 10);
  XDrawLine(xinfo->disp, xinfo->double_buffer, xinfo->gc, x + 21, y + 4, x + 20, y + 10);

  //Draw the chest area (lighter than the red feathered parts of bird
  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[Bisque]);
  XFillArc(xinfo->disp, xinfo->double_buffer, xinfo->gc, x + 5, y + 20, 20, 10, 0*64, 360*64);

  //Draw feather on head
  polyPoints = new XPoint[4];
  polyPoints[0].x = x + 17;
  polyPoints[0].y = y + 5;
  polyPoints[1].x = x + 12;
  polyPoints[1].y = y - 8;
  polyPoints[2].x = x + 11;
  polyPoints[2].y = y - 0;
  polyPoints[3].x = x + 0;
  polyPoints[3].y = y - 15;
  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[Red]);
  XFillPolygon(xinfo->disp, xinfo->double_buffer, xinfo->gc, polyPoints, 4, Complex, CoordModeOrigin);
  delete [] polyPoints;
}

//Method to draw a block object. Here, the block is depicted as a really rocky item,
//being a polygon with many points jutting out.
void MainGraphics::DrawBlock(int x, int y){
  XPoint *polyPoints;
  polyPoints = new XPoint[13];
  polyPoints[0].x = x + 0;
  polyPoints[0].y = y + 3;
  polyPoints[1].x = x + 2;
  polyPoints[1].y = y + 0;
  polyPoints[2].x = x + 15;
  polyPoints[2].y = y + 4;
  polyPoints[3].x = x + 28;
  polyPoints[3].y = y + 0;
  polyPoints[4].x = x + 30;
  polyPoints[4].y = y + 3;
  polyPoints[5].x = x + 27;
  polyPoints[5].y = y + 15;
  polyPoints[6].x = x + 30;
  polyPoints[6].y = y + 28;
  polyPoints[7].x = x + 24;
  polyPoints[7].y = y + 30;
  polyPoints[8].x = x + 14;
  polyPoints[8].y = y + 28;
  polyPoints[9].x = x + 5;
  polyPoints[9].y = y + 30;
  polyPoints[10].x = x + 0;
  polyPoints[10].y = y + 28;
  polyPoints[11].x = x + 3;
  polyPoints[11].y = y + 17;
  polyPoints[12].x = x + 0;
  polyPoints[12].y = y + 5;

  //Draw the main body.
  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[Grey]);
  XFillPolygon(xinfo->disp, xinfo->double_buffer, xinfo->gc, polyPoints, 12, Complex, CoordModeOrigin);

  //Draw the outline of the body
  XSetLineAttributes(xinfo->disp, xinfo->gc, 1, LineSolid, CapButt, JoinRound);
  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[Black]);
  XDrawLines(xinfo->disp, xinfo->double_buffer, xinfo->gc, polyPoints, 13, CoordModeOrigin);
  delete [] polyPoints;
} 

//Method to draw a terrain object
void MainGraphics::DrawTerrain(int x, int y, int width, int height){
  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[LightGreen]);
  XFillRectangle(xinfo->disp, xinfo->double_buffer, xinfo->gc, x, y, width, height);
}

//Method to draw a target object. Living targets are green, while dead targets are blue.
void MainGraphics::DrawTarget(int x, int y, bool alive) {
  //Draw outline
  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[Black]);
  XFillArc(xinfo->disp, xinfo->double_buffer, xinfo->gc, x - 1, y - 1, 32, 32, 0*64, 360*64);

  //Draw body
  if (alive) {
    XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[Green]);
  } else {
    XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[Blue]);
  } 
  XFillArc(xinfo->disp, xinfo->double_buffer, xinfo->gc, x, y, 30, 30, 0*64, 360*64);

  //Draw eyes
  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[White]);
  XFillArc(xinfo->disp, xinfo->double_buffer, xinfo->gc, x + 3, y + 7, 6, 6, 0*64, 360*64);
  XFillArc(xinfo->disp, xinfo->double_buffer, xinfo->gc, x + 15, y + 7, 5, 5, 0*64, 360*64);
  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[Black]);
  XFillArc(xinfo->disp, xinfo->double_buffer, xinfo->gc, x + 5, y + 9, 3, 3, 0*64, 360*64);
  XFillArc(xinfo->disp, xinfo->double_buffer, xinfo->gc, x + 17, y + 9, 3, 3, 0*64, 360*64);

  //Draw snout
  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[LimeGreen]);
  XFillArc(xinfo->disp, xinfo->double_buffer, xinfo->gc, x + 2, y + 13, 16, 10, 0*64, 360*64);
 
  //Draw nostrils
  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[DarkGreen]);
  XFillArc(xinfo->disp, xinfo->double_buffer, xinfo->gc, x + 4, y + 14, 4, 5, 0*64, 360*64);
  XFillArc(xinfo->disp, xinfo->double_buffer, xinfo->gc, x + 10, y + 14, 4, 5, 0*64, 360*64);

}

//Method to draw a sling. Essentially, it draws two lines: one to the left
//of the sling's center, and one to the right of the center (creates illusion
//of a bendable sling).
void MainGraphics::DrawSling(int x, int y, int origin_x, int origin_y) {
  //Draw the slingshot
  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[Brown]);
  XSetLineAttributes(xinfo->disp, xinfo->gc, 4, LineSolid, CapRound, JoinRound);
  XDrawArc(xinfo->disp, xinfo->double_buffer, xinfo->gc, origin_x - 30, origin_y - 30, 60, 50, 0*64, -180*64);
  XDrawLine(xinfo->disp, xinfo->double_buffer, xinfo->gc, origin_x, origin_y + 20, origin_x, origin_y + 70);

  //Draw the sling
  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[White]);

  //Draw left line.
  XDrawLine(xinfo->disp, xinfo->double_buffer, xinfo->gc,
            origin_x - 30, origin_y, x, y);

  //Draw right line.
  XDrawLine(xinfo->disp, xinfo->double_buffer, xinfo->gc,
            x, y, origin_x + 30, origin_y); 
}

//Method to draw the trajectory of a bird object.
void MainGraphics::DrawTrajectory(int x, int y) {
  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[White]);
  XFillArc(xinfo->disp, xinfo->double_buffer, xinfo->gc, x + 12, y + 8, 6, 6, 0*64, 360*64);
  XFillArc(xinfo->disp, xinfo->double_buffer, xinfo->gc, x + 20, y + 7, 5, 5, 0*64, 360*64);
}

//Draw the foreground of the game, which simply involves colouring the
//top of the window white
void MainGraphics::DrawForeground() {
  stringstream nameStream;
  string nameString;
  nameStream << string("MAD BIRDS v1.0");
  nameString = nameStream.str();

   XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[White]);
   XFillRectangle(xinfo->disp, xinfo->double_buffer, xinfo->gc, 0, 0,
                  xinfo->windAttr.width, 40);

  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[Black]);
  XDrawImageString(xinfo->disp, xinfo->double_buffer, xinfo->gc,
                   xinfo->windAttr.width - 100, 30,
                   nameString.c_str(), nameString.length());
}

//Draw the background of the game, which simply involves colouring the
//entire window sky blue
void MainGraphics::DrawBackground() {
   XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[SkyBlue]);
   XFillRectangle(xinfo->disp, xinfo->double_buffer, xinfo->gc, 0, 0,
                  xinfo->windAttr.width, xinfo->windAttr.height);
}

//Method to draw the Game End screen
void MainGraphics::DrawGameEnd() {
  //put the words "Game Over. All Levels Completed." in a stringstream
  stringstream endStream;
  string endString;
  endStream << string("Game Over. All Levels Completed. Please press 'q' to quit the game.");
  endString = endStream.str();
  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[Black]);
  XFillRectangle(xinfo->disp, xinfo->double_buffer, xinfo->gc, 0, 0,
                 xinfo->windAttr.width, xinfo->windAttr.height);

  XSetBackground(xinfo->disp, xinfo->gc, xinfo->colours[Black]);
  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[White]);
  XDrawImageString(xinfo->disp, xinfo->double_buffer, xinfo->gc,
                  140, xinfo->windAttr.height / 2,
                  endString.c_str(), endString.length());

  //At the end, revert background colour
  XSetBackground(xinfo->disp, xinfo->gc, xinfo->colours[White]);
}

//Method to draw what level you're currently on
void MainGraphics::DrawLevel(int x, int y, int level) {
  stringstream lvlStream;
  string lvlString;
  lvlStream << string("Level: ") << level;
  lvlString = lvlStream.str();

  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[Black]);
  XDrawImageString(xinfo->disp, xinfo->double_buffer, xinfo->gc, x, y,
                   lvlString.c_str(), lvlString.length());

}

//Method to draw the score
void MainGraphics::DrawScore(int x, int y, int points) {
  //put the words "Score" and number of points in a stringstream so it can be printed.
  stringstream scrStream;
  string scrString;
  scrStream << string("Score: ") << points;
  scrString = scrStream.str();

  XSetForeground(xinfo->disp, xinfo->gc, xinfo->colours[Black]);
  XDrawImageString(xinfo->disp, xinfo->double_buffer, xinfo->gc, x, y,
                   scrString.c_str(), scrString.length());
}

//Constructor
MainGraphics::MainGraphics(XInfo *xinfo): xinfo(xinfo) {}

//Destructor
MainGraphics::~MainGraphics(){}

