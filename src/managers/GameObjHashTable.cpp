
#ifndef HASH_TABLE_SIZE
  #define HASH_TABLE_SIZE 11
#endif

#include "GameObjHashTable.h"

//Constructor
GameObjHashTable::GameObjHashTable() {
  //Initialize array of GameObj LinkedLists.
  linkedlists = new GameObjLinkedList[HASH_TABLE_SIZE];
  GameObjLinkedList * temp = NULL;
  for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
    temp = new GameObjLinkedList();
    linkedlists[i] = *temp;
  }
}

/*
  simply hashes index based on modulus of ID number and size of LinkedList array
*/
int GameObjHashTable::hash(unsigned int ID) {
  //return ID & (HASH_TABLE_SIZE - 1);

  return ID % HASH_TABLE_SIZE;
}

/*
  returns pointer to GameObj mapped to ID param.
*/
GameObj * GameObjHashTable::find(unsigned int ID) {
  int pos = hash(ID);
  GameObjLinkedListNode * searchNode = linkedlists[pos].find(ID);
  if (searchNode == NULL) return NULL;
  //if (searchNode->gameObj == NULL) return NULL;
  return searchNode->gameObj; //Will be NULL if gameobj is NULL
}

/*
  Pops pointer of GameObj mapped to ID param.
  returns pointer.
*/
GameObj * GameObjHashTable::pop(unsigned int ID) {
  int pos = hash(ID);
  GameObjLinkedListNode * popped = linkedlists[pos].pop(ID);
  if (popped == NULL) return NULL;
  return popped->gameObj; //Will be NULL if gameobj is NULL
}

/*
  Sets GameObj mapped to ID param, calls set method after obtaining hash index
*/
void GameObjHashTable::set(unsigned int ID, GameObj * gameObj) {
  int pos = hash(ID);
  linkedlists[pos].set(ID, gameObj);
}

/*
  Deletes GameObj mapped to ID param, calls delete method after obtaining hash
  index.
*/
bool GameObjHashTable::delGameObj(unsigned int ID) {
  int pos = hash(ID);
  return linkedlists[pos].delGameObjNode(ID);
}

/*
  Calls individual purgeAll methods for each linkedlist
*/
bool GameObjHashTable::purgeAll(){
  bool b = true;
  for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
    b = b & (linkedlists[i].purgeAll());
  }
  return b;
}
