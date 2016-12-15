#ifndef GAMEOBJDEFINTIONS_H
#define GAMEOBJDEFINTIONS_H

#include "SDL2/SDL.h"

class Renderable { //Renderable interface
protected:
  bool visable = false;
public:
  virtual void render(SDL_Surface * screen) = 0;
  void setVisable(bool vis) { visable = vis; }
  bool isVisable() { return visable; };
};

class Updateable { //Updateable interface
public:
  virtual void tick() = 0;
  virtual void update() = 0;
};


//GameObj base class
class GameObj : public Renderable, public Updateable {
public:
  GameObj();
  //~GameObj();
  void render(SDL_Surface * screen) { }
  void update() { }
  void tick() { }
};

#endif
