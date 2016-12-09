#ifndef GAMEOBJHASHTABLE_H
#define GAMEOBJHASHTABLE_H

#include "GameObjLinkedList.h"
#include "../oop/GameObj.h"

class GameObjHashTable {
private:
  GameObjLinkedList * linkedlists;
  int hash(unsigned int ID);
public:
  GameObjHashTable();
  void set(int ID, GameObj * gameobj);
  GameObj * find(unsigned int ID);
  GameObj * pop(unsigned int ID);
  void set(unsigned int ID, GameObj * gameobj);
  bool delGameObj(unsigned int ID);
  bool purgeAll();
};

#endif
