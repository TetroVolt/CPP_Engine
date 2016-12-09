#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include <stdio.h>
#include <iostream>
#include "SDL2/SDL.h"

class GameObj {
protected:
  bool Reffed;
public:
  GameObj();
  ~GameObj();
  bool hasRef();
  void setRef(bool ref);
  void tick();
  void update();
  void render();
};

#endif
