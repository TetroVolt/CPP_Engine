//#include "SDL.h"
#include <iostream>
#include "Game.h"

using namespace std;

int main(){
  Game *game = new Game();
  //Game method exitGame() is called when the game loop terminates
  game -> run();
  free(game);
}
