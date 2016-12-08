
#include "GameObj.h"

GameObj::GameObj(int ID) {
  ID_NUM = ID;
}

GameObj::~GameObj() {
  
}

GameObj::bool hasRef() {
  return Reffed;
}

GameObj::void deRef(bool ref) {
  Reffed = false;
}
