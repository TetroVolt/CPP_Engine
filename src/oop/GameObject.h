#ifndef GAME_H
#define GAMEOBJECT_H

#include <stdio.h>
#include <iostream>
#include "SDL.h"

using namespace std;

class GameObject {
public:
  GameObject();
  void update();
  void render();
};



#endif
