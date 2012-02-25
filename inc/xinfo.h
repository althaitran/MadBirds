#ifndef __XINFO_H__
#define __XINFO_H__

#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

using namespace std;

#define BMP_FILE "images/madbirds.bmp"

//Colours available to draw on the XWindow
enum Colours{
  White,     //0
  Black,     //1
  Grey,      //2
  Red,       //3
  Green,     //4
  LightGreen,//5
  LimeGreen, //6
  DarkGreen, //7
  Blue,      //8
  SkyBlue,   //9
  Yellow,    //10
  Orange,    //11
  Brown,     //12
  Bisque     //13
};


//Structure to store all the info for an XWindow
struct XInfo {
  Display *disp;
  Window wind;
  GC gc;
  XWindowAttributes windAttr;
  Pixmap double_buffer;  //Stores image on window before copying it to window
  ulong colours[14];  //Array of the colours to use while drawing on the  
                      //XWindow. Should be set before any drawing is to occur.
};

void initXWindow(XInfo &, int, int);  //Method to initialize the XWindow by
                                      //setting up the XInfo object.

void freeXWindow(XInfo &);  //Method to free the memory used by an XInfo object.

#endif
