#include "../src/oop/GameObj.h"
#include "LazyFooRender.cpp"
#include "SDL/SDL.h"
//#include "SDL2"

const int WIDTH = 640;
const int HEIGHT = 480;
const int bitppix = 32;

using namespace std;
SDL_Surface *screen;


class Rectangle: public GameObj{
  private:


  public:
    typedef struct{
        int x;
        int y;
    } position;
    typedef struct{
        int x;
        int y;
    } size;

    void render(SDL_Surface * screen){
      if(!isVisable())return;

    }

};

void test1(){

    SDL_Rect srcrect;
    srcrect.x = 0;
    srcrect.y = 0;
    srcrect.w = 32;
    srcrect.h = 32;

    const SDL_Rect *rect= &srcrect;

    int posX = 100, posY = 100, width = 320, height = 240;
    SDL_Window *win = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *bitmapTex = NULL;
    SDL_Surface *bitmapSurface = NULL;

    SDL_Init(SDL_INIT_VIDEO);

    win = SDL_CreateWindow("Rectangle Test", posX, posY, width, height, 0);

    //renderer takes in the parameters of SDL_Window, int for index and Unsighned int for flags
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    bitmapSurface = SDL_LoadBMP("rectBack.bmp");
    bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
    SDL_FreeSurface(bitmapSurface);

    while(1){
      SDL_Event e;
      if(SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT)
          break;
      }
      SDL_RenderClear(renderer);
      SDL_RenderCopy(renderer, bitmapTex, NULL, NULL);
      SDL_RenderPresent(renderer);
      if (SDL_RenderDrawRect(renderer, rect))break;
    }

    SDL_DestroyTexture(bitmapTex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    SDL_Quit();
}


int main(){

  fromLazyFoo();
  return 0;
}
