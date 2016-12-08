#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include <stdio.h>
#include <iostream>
#include "SDL2/SDL.h"


class GameObj {
protected:
  bool Reffed = true;
  unsigned int ID_NUM;
public:
  GameObj(unsigned int ID);
  ~GameObj();
  bool hasRef();
  void deRef();
  virtual void tick() const = 0;
  virtual void update() const = 0;
  virtual void render() const = 0;
};

#endif
