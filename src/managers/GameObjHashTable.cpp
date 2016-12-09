
#ifndef HASH_TABLE_SIZE
  #define HASH_TABLE_SIZE 11
#endif

#include "GameObjHashTable.h"

GameObjHashTable::GameObjHashTable() {
  linkedlists = new GameObjLinkedList[HASH_TABLE_SIZE];
  GameObjLinkedList * temp = NULL;
  for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
    temp = new GameObjLinkedList();
    linkedlists[i] = *temp;
  }
}

int GameObjHashTable::hash(unsigned int ID){
  return ID % HASH_TABLE_SIZE;
}

GameObj * GameObjHashTable::find(unsigned int ID) {
  int pos = hash(ID);
  GameObjLinkedListNode * searchNode = linkedlists[pos].find(ID);
  if (searchNode == NULL) return NULL;
  //if (searchNode->gameObj == NULL) return NULL;
  return searchNode->gameObj; //Will be NULL if gameobj is NULL
}

GameObj * GameObjHashTable::pop(unsigned int ID) {
  int pos = hash(ID);
  GameObjLinkedListNode * popped = linkedlists[pos].pop(ID);
  if (popped == NULL) return NULL;
  return popped->gameObj; //Will be NULL if gameobj is NULL
}

void GameObjHashTable::set(unsigned int ID, GameObj * gameObj) {
  int pos = hash(ID);
  linkedlists[pos].set(ID, gameObj);
}

bool GameObjHashTable::delGameObj(unsigned int ID) {
  int pos = hash(ID);
  return linkedlists[pos].delGameObjNode(ID);
}

bool GameObjHashTable::purgeAll(){
  bool b = true;
  for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
    b = b & (linkedlists[i].purgeAll());
  }
  return b;
}
