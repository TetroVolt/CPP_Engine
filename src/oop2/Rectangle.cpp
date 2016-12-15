#include "GameObjDefinitions.h"
#include "SDL2/SDL.h"


using namespace std;

typedef struct {
  int x; int y;
} position;



class Rectangle: public GameObj{
private:
  position p;
public:
  Rectangle(int xpos, int ypos) : GameObj() {
    p.x = xpos;
    p.y = ypos;
  }

  void render(SDL_Surface * screen){
    if (! this->visable) return;
    //Render here
  }
};

/*
int main(){
  return 0;
}
*/
