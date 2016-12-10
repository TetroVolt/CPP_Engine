#include "src/oop2/GameObjDefinitions.h"
#include "SDL/SDL.h"


using namespace std;

typedef struct {
  int x; int y;
} position;




class Rectangle: public GameObj{
  private:
    position p;
    bool isVisable = false;
  public:
    Rectangle(int xpos, int ypos) : GameObj() {
      p.x = xpos;
      p.y = ypos;
    }

    void render(SDL_Surface * screen){
      if(!isVisable())return;
      //Render here
    }

};

int main(){
  return 0;
}
