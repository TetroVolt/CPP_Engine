#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include <iostream>
#include "SDL2/SDL.h"
typedef int GameObj_TYPE;

class GameObj {
private:
  GameObj_TYPE type;
  bool visable = true;
public:
  GameObj(int type);
  ~GameObj();

  void tick();
  void update();
  void render();
  void setVisable(bool in);
  bool isVisable();
  GameObj_TYPE getType();
};

#endif
