#ifndef GAMEOBJ_H
#define GAMEOBJ_H


#include <iostream>
#include "SDL2/SDL.h"
typedef int GameObj_TYPE;

class GameObj {
private:
  GameObj_TYPE type;
public:
  GameObj(int type);
  ~GameObj();

  void tick();
  void update();
  void render();
  GameObj_TYPE getType();
};

#endif
