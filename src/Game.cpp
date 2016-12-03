#include "Game.h"

using namespace std;

#define desiredFPS 60


//Constructor
Game::Game(){
  setup();
}

void Game::setup(){
  cout << "Setting up" << endl;

  Game::eventList = new SDL_KeyboardEvent[EVENT_POLL_SIZE];
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


    if (delta >= nanoSecPerFrame){
    { //Run a frame
      nanoSecs += delta;
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

void Game::quit(){
  free(eventList);
}

void Game::getUserInput(){

}
void Game::updateGameState(){
  //cout << "Inside updateGameState() function" << endl;
}
void Game::render(){
  //cout << "Inside render() function" << endl;
}
