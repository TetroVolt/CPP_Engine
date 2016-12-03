#include "Renderer.h"

void setupScreen(){
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
  SDL_EnableUNICODE( 1 );
}
void cleanup(){
  SDL_Quit();
  exit( 0 );
}
