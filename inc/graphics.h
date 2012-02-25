#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

class Graphics {
public:
  virtual void DrawBird(int, int) = 0;
  virtual void DrawBlock(int, int) = 0;
  virtual void DrawTarget(int, int, bool) = 0;
  virtual void DrawTerrain(int, int, int, int) = 0;
  virtual void DrawSling(int, int, int, int) = 0;
  virtual void DrawTrajectory(int, int) = 0;
  virtual void DrawForeground() = 0;
  virtual void DrawBackground() = 0;
  virtual void DrawGameEnd() = 0;
  virtual void DrawLevel(int, int, int) = 0;
  virtual void DrawScore(int, int, int) = 0;

  virtual ~Graphics() = 0;
};

#endif
