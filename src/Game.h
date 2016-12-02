#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "SDL/SDL.h"

class Game {
private:
  bool isRunning = true;
public:
  Game();
  void run();
  void getUserInput();
  void updateGameState();
  void render();
  bool is_Running(){ return isRunning; }
};

#endif
