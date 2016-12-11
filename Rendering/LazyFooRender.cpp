#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdio.h>
#include <string>
#include <cmath>

//Screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates a window
bool init();

//Loads media
bool loadMedia();

//Frees up the media and shuts down SDL
void close();

//Loads individual image as texture
SDL_Texture *loadTexture (std::string path);

//The window to render to
SDL_Window *gWindow = NULL;

//the actual window renderer
SDL_Renderer *gRenderer = NULL;


bool init(){
  //Initilization flags
  bool success = true;

  //Initilize SDL
  if( SDL_Init(SDL_INIT_VIDEO)<0){
    printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
    success = false;
  }
  else{
    //set texture filtering to linear
    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
      printf("Warning: Linear texture texture filtering not enabled!\n");
    //create window
    gWindow = SDL_CreateWindow("Rect Practice", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(gWindow == NULL){
      printf("Window could not be created! SDL Error: %s\n", SDL_GetError() );
      success = false;
    }
    else{
      //create a renderer for the window
      gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
      if(gRenderer == NULL){
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        success = false;
      }//end gRenderer == NULL
      else{
        //Initialize renderer color
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

        //initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        //not sure why single & and not double but i shall not question
        if(!(IMG_Init(imgFlags) & imgFlags)){
          printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
          success = false;
        }
      }// end gRenderer else block

    }//end else for gWindow

  }//end else for init

  return success;

}//end init function

bool loadMedia(){
  bool success = true;

  //this is because there is nothhing to load, so no way to fail
  return success;
}

void close(){
  //destroy window
  SDL_DestroyRenderer(gRenderer);
  SDL_DestroyWindow(gWindow);
  gWindow = NULL;
  gRenderer = NULL;

  //Quit SDL subsystems
  IMG_Quit();
  SDL_Quit();
}


SDL_Texture *loadTexture(std::string path){
  //The final texture
  SDL_Texture * newTexture = NULL;

  //Load image at specified path
  SDL_Surface *loadedSurface = IMG_Load(path.c_str() );
  if(loadedSurface == NULL){
    printf("Unable to load image%s!  SDL_Image Error: %s\n",path.c_str(), IMG_GetError() );
  }//end if loaded surface
  else{
    // create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
    if(newTexture == NULL)
      printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );

    //get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);

  }//end loaded surface else

  return newTexture;

}//end function



int fromLazyFoo(){
  //using this method to simulate the main from the tutorial
  //  i want to call it from the other file
  if( !init() )
    printf("Failed to initialize!\n");
  else{
    //load media
    if(!loadMedia() )
      printf("Failed to load media!\n");
    else{
      bool quit = false;
      SDL_Event e;

      while(!quit){

        while(SDL_PollEvent( &e ) != 0){
            if(e.type == SDL_QUIT)
              quit = true;
        }//end while poll event

        //clear the screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear( gRenderer );

        //Render red filled quad
        SDL_Rect fillRect = {SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
        SDL_RenderFillRect(gRenderer, &fillRect );

        //Render green outlined quad
        SDL_Rect outlineRect = {SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3};
        SDL_SetRenderDrawColor( gRenderer, 0x00, 0xFF, 0x00, 0xFF);
        SDL_RenderDrawRect( gRenderer, &outlineRect);

        //Draw blue horizontal linear
        SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0xFF, 0xFF );
        SDL_RenderDrawLine(gRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

        //Draw vertical line of yellow dots
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0x00, 0xFF);
        for(int i = 0; i < SCREEN_HEIGHT; i+=4){
          SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, i);
        }

        //update screen
        SDL_RenderPresent(gRenderer);

      }//end while !quit

    }//end else load media

  }// end else init

  //Free resources and close SDL_Renderer
  close();

  return 0;

}//end function
