#include "Game.h"

using namespace std;

#define desiredFPS 60


//Constructor
Game::Game(){

}

//Run function
void Game::run(){
  //cout << "Inside run() function" << endl;
  unsigned long int start_time, end_time, delta;
  unsigned long int nanoSecPerFrame = 1000000000ul / desiredFPS;
  unsigned long int nanoSecs = 0;
  unsigned long int frames = 0;

  while (is_Running()){
    end_time += 10;
    delta = end_time - start_time;
    nanoSecs += delta;

    if (delta >= nanoSecPerFrame){
      { //Run a frame
      getUserInput();
      updateGameState();
      render();
      }
      start_time = end_time;
      frames++;

    }

    if (nanoSecs >= 1000000000ul){
      cout << "FPS: " << frames << endl;
      frames = 0;
      nanoSecs = 0;
    }
  }

}

void Game::getUserInput(){
  //cout << "Inside getUserInput() function" << endl;
}
void Game::updateGameState(){
  //cout << "Inside updateGameState() function" << endl;
}
void Game::render(){
  //cout << "Inside render() function" << endl;
}
