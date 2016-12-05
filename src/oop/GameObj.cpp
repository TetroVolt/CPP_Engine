
#include "GameObj.h"


//GameObj Constructor
GameObj::GameObj(){
  std::cout << "GameObj::GameObj() being constructed." << std::endl;
}

//GameObj Destructor
GameObj::~GameObj(){
  std::cout << "GameObj::~GameObj() being destructed." << std::endl;
}

bool GameObj::hasRef(){
  std::cout << "Inside GameObj::hasRef()" << std::endl;
  return Reffed;
}

void GameObj::setRef(bool ref){
  std::cout << "Inside GameObj::setRef(bool Ref)" << std::endl;
  Reffed = ref;
}

void GameObj::tick(){
  std::cout << "Inside GameObj::tick()" << std::endl;
}

void GameObj::update(){
  std::cout << "Inside GameObj::update()" << std::endl;
}

void GameObj::render(){
  std::cout << "Inside GameObj::render()" << std::endl;
}
