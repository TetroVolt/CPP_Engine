
#include "GameObj.h"

GameObj::GameObj(int type) {
  this->type = type;
  std::cout << "GameObj being constructed with type: [" << type << "]" << std::endl;
}

GameObj::~GameObj() { //might be better not to make our own
  std::cout << "GameObj being destructed." << std::endl;

}

void GameObj::tick() {
  std::cout << "Inside GameObj::tick()" << std::endl;

}

void GameObj::update() {
  std::cout << "Inside GameObj::update()" << std::endl;

}

void GameObj::render() {
  std::cout << "Inside GameObj:;render()" << std::endl;

}

GameObj_TYPE GameObj::getType(){
  return type;
}
//For ctrl shift b purposes
//int main(){}
