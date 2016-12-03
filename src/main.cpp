#include "SDL.h"
#include <iostream>
#include "Game.h"

using namespace std;

int main(){
  Game *game = new Game();
  //Game game;
  game -> run();
  free(game);
}
