#include "src/oop/GameObj.h"
#include "SDL/SDL.h"
using namespace std;

class Rectangle: public GameObj{
  private:
    typedef struct{
        int x;
        int y;
    } position;

  public:
    void render(){
      if(!isVisable())return;
      
    }

};

int main(){
  return 0;
}
