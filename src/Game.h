#ifndef EVENT_POLL_SIZE
  #define EVENT_POLL_SIZE 4
#endif

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "SDL/SDL.h"
#include "KeyHandler.h"
#include "Renderer.h"

class Game {
private:
  bool isRunning = true;
  SDL_KeyboardEvent *eventList;
public:
  Game();
  void run();
  void getUserInput();
  void updateGameState();
  void render();
  bool is_Running(){ return isRunning; }
  void setup();
  void quit();
  void stopRunning();
  void handleUserInput();
};

#endif
