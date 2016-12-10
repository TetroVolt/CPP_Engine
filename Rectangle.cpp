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

  screen = SDL_SetVideoMode( WIDTH, HEIGHT, bitppix, SDL_SWSURFACE);

  if(!screen)return 1;

  SDL_WM_SetCaption("Rectangle Test", NULL);

  SDL_Delay(3000);

  SDL_FreeSurface(screen);

  return 0;
}
