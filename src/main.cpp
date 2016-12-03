//#include "SDL.h"
#include <iostream>
#include "Game.h"

using namespace std;

int main(int argc, char ** argv){


  //there is a setup function that is now run in the constructor
  Game *game = new Game();
  //Game method exitGame() is called when the game loop terminates
  game -> run();
  free(game);

}
