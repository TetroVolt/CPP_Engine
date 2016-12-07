#include "SDL/SDL2/SDL.h"


void PrintKeyInfo( SDL_KeyboardEvent *key);
void PrintModifiers( SDLMod mod );

int main(int argc, char *args[] ){

  SDL_Event event;
  int quit = 0;

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

  //loop until we find an SDL event
  //SDL_Quit is litterally when you hit the x
  while(!quit){

    //poll for events
    while(SDL_PollEvent( &event) ){

      switch(event.type){
        case SDL_KEYDOWN:
        case SDL_KEYUP:
          PrintKeyInfo( &event.key);
          break;

        case SDL_QUIT:
          quit = 1;
          break;

        default:
          break;
      }
    }//end while event
  }//end while quit

  SDL_Quit();
  exit( 0 );
}

//prin key info when pressed or released
void PrintKeyInfo(SDL_KeyboardEvent *key){

  //find wether press or released
  if( key->type == SDL_KEYUP )
    printf("Release:- ");
  else
    printf("Press:- ");

  //scancode key value
  printf("Scancode: 0x%02X", key->keysym.scancode );
  //print key name
  printf(", Name: %s", SDL_GetKeyName( key->keysym.sym));

  if(key->type == SDL_KEYDOWN){
    printf(", univode: ");
    if(key->keysym.unicode< 0x80 && key->keysym.unicode >0){
      printf("%c (ox%04X", (char)key->keysym.unicode, key->keysym.unicode );
    }
    else{
      printf("? (0x%04X", key->keysym.unicode );
    }
  }
  printf("\n");
  PrintModifiers(key->keysym.mod);
}

void PrintModifiers(SDLMod mod){
  printf("Modifiers: ");

  if(mod == KMOD_NONE){
    printf("None\n");
    return;
  }

  if( mod & KMOD_NUM ) printf( "NUMLOCK " );
  if( mod & KMOD_CAPS ) printf( "CAPSLOCK " );
  if( mod & KMOD_LCTRL ) printf( "LCTRL " );
  if( mod & KMOD_RCTRL ) printf( "RCTRL " );
  if( mod & KMOD_RSHIFT ) printf( "RSHIFT " );
  if( mod & KMOD_LSHIFT ) printf( "LSHIFT " );
  if( mod & KMOD_RALT ) printf( "RALT " );
  if( mod & KMOD_LALT ) printf( "LALT " );
  if( mod & KMOD_CTRL ) printf( "CTRL " );
  if( mod & KMOD_SHIFT ) printf( "SHIFT " );
  if( mod & KMOD_ALT ) printf( "ALT " );
  printf( "\n" );

}
