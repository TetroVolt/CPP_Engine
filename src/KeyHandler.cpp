#include "KeyHandler.h"

SDL_KeyboardEvent *currentKeys(){
  int counter = 0;
  SDL_Event event;
  SDL_KeyboardEvent *temp = new SDL_KeyboardEvent[EVENT_POLL_SIZE];

  while(SDL_PollEvent( &event) && counter < EVENT_POLL_SIZE){
    temp[counter] = event.key;
    counter++;
  }//end while event

  return temp;
}
