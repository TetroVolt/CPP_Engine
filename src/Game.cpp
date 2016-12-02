#include "Game.h"

using namespace std;

#define desiredFPS 60


int quit = 0;


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

  while (is_Running() && !Game::quit){
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
  gameExit();

}

//method that cleans up allthe SDL bullshit when were done
void Game::gameExit(){
    SDL_Quit();
    exit( 0 );
}

//method called in the constructor to set up the screen and get ready for input
void Game::setup(){
  //initialize the SDL
  if(SDL_Init(SDL_INIT_VIDEO) < 0){
    //< 0 if error
    fprintf(stderr, "Could not initalise SDL: %s\n", SDL_GetError() );
    exit(-1);
  }

  //set up video mode
  if( !SDL_SetVideoMode( 320, 200, 0, 0) ){
    fprintf(stderr, "Could not set video mode %s\n", SDL_GetError() );
    exit(-1);
  }

  //unicode translation for keyboard input
  SDL_EnableUNICODE( 1 );
}

//handle logic assosiated with when the user pushes a key down
void Game::handleKeyDown(SDL_KeyboardEvent *key){
  printf("Keydown \'%c\' detected ", (char)key->keysym.unicode);
}

//handle logic assosiated with when the user releases a key
void Game::handleKeyUp(SDL_KeyboardEvent *key){
  printf("Keyup \'%c\' detected ", (char)key->keysym.unicode);
}

void Game::getUserInput(){
  SDL_Event event;
  //poll for events
  while(SDL_PollEvent( &event) ){

    switch(event.type){
      case SDL_QUIT:
        Game::quit = 1;
        break;
      case SDL_KEYDOWN:
        handleKeyDown(&event.key);
        break;
      case SDL_KEYUP:
        handleKeyUp( &event.key);
        break;
      default:
        break;
    }
  }//end while event
}

void Game::updateGameState(){
  //cout << "Inside updateGameState() function" << endl;
}
void Game::render(){
  //cout << "Inside render() function" << endl;
}
