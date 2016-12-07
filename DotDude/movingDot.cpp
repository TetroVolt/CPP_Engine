#include "SDL/SDL2/SDL.h"
#include <string>
#include <iostream>

#define KEY_UP_ 72
#define KEY_DOWN_ 80
#define KEY_LEFT_ 75
#define KEY_RIGHT_ 77

const int WIDTH = 640;
const int HEIGHT = 480;
const int bitppix = 32;

SDL_Surface *dotDude = NULL;
SDL_Surface *background = NULL;
SDL_Surface *screen = NULL;

int dotDudeX = 0;
int dotDudeY = HEIGHT / 2;

SDL_Surface *loadImage(std::string filename){
  SDL_Surface *loadedImage = NULL;
  SDL_Surface *optimizedImage = NULL;

  loadedImage = SDL_LoadBMP(filename.c_str() ) ;

  if(loadedImage != NULL){
    optimizedImage = SDL_DisplayFormat(loadedImage);
    SDL_FreeSurface(loadedImage);
  }

  return optimizedImage;
}

void applySurface(int x, int y, SDL_Surface *source, SDL_Surface *destination){
  SDL_Rect offset;

  offset.x = x;
  offset.y = y;

  SDL_BlitSurface(source, NULL, destination, &offset);
}

void closeRefs(){

  SDL_FreeSurface(dotDude);
  SDL_FreeSurface(background);

  SDL_Quit();
}

char getUserInput(){
  
}

int main(int argc, char * args[] ){
  screen = SDL_SetVideoMode( WIDTH, HEIGHT, bitppix, SDL_SWSURFACE);

  if(!screen)
    return 1;

  SDL_WM_SetCaption("Dot Dude", NULL);

  dotDude = loadImage("dot.bmp");
  background = loadImage("background.bmp");

  while(dotDudeX < WIDTH){
    applySurface(0, 0, background, screen);
    applySurface(320, 0, background, screen);
    applySurface(0, 240, background, screen);
    applySurface(320, 240, background, screen);
    applySurface(dotDudeX, dotDudeY, dotDude, screen);
    if(SDL_Flip(screen) == -1)
      return 1;

    getUserInput();
  }

  if(SDL_Flip(screen) == -1)
    return 1;


    closeRefs();
  return 0;
}
