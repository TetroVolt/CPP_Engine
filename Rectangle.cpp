#include "src/oop/GameObj.h"
#include "SDL/SDL.h"

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

int main(){

  SDL_Rect srcrect;
  srcrect.x = 0;
  srcrect.y = 0;
  srcrect.w = 32;
  srcrect.h = 32;

  int posX = 100, posY = 100, width = 320, height = 240;
  SDL_Window *win = NULL;
  SDL_Renderer *renderer = NULL;

  SDL_Init(SDL_INIT_VIDEO);

  win = SDL_CreateWindow("Rectangle Test", posX, posY, width, height, 0);

  //renderer takes in the parameters of SDL_Window, int for index and Unsighned int for flags
  renderer = SDL_CreateRenderer(win, -1, SDL_RENDER_ACCELERATED);

  





  /*screen = SDL_SetVideoMode( WIDTH, HEIGHT, bitppix, SDL_SWSURFACE);

  if(!screen)return 1;

  SDL_WM_SetCaption("Rectangle Test", NULL);

  SDL_Delay(3000);

  SDL_FreeSurface(screen);
  */

  return 0;
}
