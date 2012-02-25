#include "xinfo.h"

const int Border = 5;

//Method to initialize the XWindow (which includes setting up the XInfo object).
void initXWindow(XInfo &xinfo, int width, int height) {
  XSizeHints hints;  //Holds data about the screen size, for the most part.
  int screen;        //Indicates which screen to use (will be the default one                        //from the display).

  xinfo.disp = XOpenDisplay("");

  screen = DefaultScreen( xinfo.disp );

  //Set the colours
  XColor xcol;  //Current colour being looked at.
  Colormap map;    //The colour map used to get the colours from.
  char col_names[14][15]={ "White",
                           "Black",
                           "Grey",
                           "Red",
                           "Green",
                           "Light Green",
                           "Lime Green",
                           "Dark Green",
                           "Blue",
                           "Sky Blue",
                           "Yellow",
                           "Orange",
                           "Brown",
                           "Bisque"};

  map=DefaultColormap(xinfo.disp, screen);  //Will use the default colour map
                                            //for this program.

  //Idenfity a colour in the map based on its name, then store that colour in
  //xinfo's colour list.
  for(int i=0; i < 14; ++i) {
      //First, get the colour value.
      if (!XParseColor(xinfo.disp,map,col_names[i],&xcol)) {
         cerr << "Invalid colour name \"" << col_names[i] << "\"." << endl;
      }
      //Next, get the pixel value of that colour.
      if (!XAllocColor(xinfo.disp,map,&xcol)) {
         cerr << "Invalid colour name \"" << col_names[i] << "\"." << endl;
      }
      xinfo.colours[i]=xcol.pixel;  //Once the appropriate info is found,
                                    //store the colour.
  }

  //Set Window size (as well as the height and width values for xinfo for use
  //outside of initialization).
  hints.x = 100;
  hints.y = 100;
  hints.width = width;
  hints.height = height;
  hints.flags = PPosition | PSize;
  xinfo.wind = XCreateSimpleWindow( xinfo.disp, DefaultRootWindow( xinfo.disp ),
                                hints.x, hints.y, hints.width, hints.height,
                                Border, xinfo.colours[Black],
                                xinfo.colours[White] );
  XSetStandardProperties( xinfo.disp, xinfo.wind, "Mad Birds", "Mad Birds",
                          None, 0, 0, &hints );
  xinfo.gc = XCreateGC (xinfo.disp, xinfo.wind, 0, 0 );
  XSetBackground( xinfo.disp, xinfo.gc, xinfo.colours[White] );
  XSetForeground( xinfo.disp, xinfo.gc, xinfo.colours[Black] );

  //Set up the double buffer.
  XGetWindowAttributes(xinfo.disp, xinfo.wind, &xinfo.windAttr);
  xinfo.double_buffer = XCreatePixmap(xinfo.disp, xinfo.wind,
                                      xinfo.windAttr.width,
                                      xinfo.windAttr.height,
                                      xinfo.windAttr.depth); 

  //Allow button presses, button motions, and exposure events.
  XSelectInput( xinfo.disp, xinfo.wind,
               ButtonPressMask | ButtonReleaseMask | ButtonMotionMask |
               KeyPressMask );

  //Disable graphics exposure events
  XSetGraphicsExposures(xinfo.disp, xinfo.gc, false);

  //Show the Window on screen.
  XMapRaised( xinfo.disp, xinfo.wind );
}

//Method to free the XWindow by freeing the graphics context and display.
void freeXWindow(XInfo &xinfo) {
  XFreeGC(xinfo.disp, xinfo.gc);
  XCloseDisplay(xinfo.disp);
}
