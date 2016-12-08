#include "../oop/GameObj.h"
#include "../oop/GameObj.cpp"

class GameObjDoubleLinkedList {
private:
  GameObjDoubleLinkedList* prev = NULL;
  GameObjDoubleLinkedList* next = NULL;
  GameObj * gameobj;
public:
  GameObjDoubleLinkedList(GameObj* gameobj){
    this->gameobj = gameobj;
  }
  GameObj * getGameObject(){
    return gameobj;
  }

  bool hasPrev(){
    return prev == NULL;
  }
  GameObjDoubleLinkedList * getPrev(){
    return prev;
  }
  void setPrev(GameObjDoubleLinkedList * pr){
    prev = pr;
  }


  bool hasNext(){
    return next == NULL;
  }
  GameObjDoubleLinkedList * getNext(){
    return next;
  }
  void setNext(GameObjDoubleLinkedList * ne){
    next = ne;
  }


  ~GameObjDoubleLinkedList(){}
};

class GameObjectHashTable {
private:
  GameObjDoubleLinkedList * gameobjects[11];
  const int ARRAY_SIZE = 11;
  int hash(GameObj * search){

  }
public:
  GameObjectHashTable(){

  }
};
