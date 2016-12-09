#ifndef GAMEOBJDEFINTIONS_H
#define GAMEOBJDEFINTIONS_H

//#include <iostream>

class Renderable { //Renderable interface
public:
  virtual void render(/*Ideally pass a painter param*/) = 0;
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
  void render(/*Ideally pass a painter param*/) { }
  void tick() { }
  void update() { }
};

#endif
