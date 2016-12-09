#ifndef GAMEOBJLINKEDLIST_H
#define GAMEOBJLINKEDLIST_H

#include "../oop/GameObj.h"

class GameObjLinkedListNode {
public:
  const unsigned int ID_NUM;
  GameObj * gameObj = NULL;
  GameObjLinkedListNode * next = NULL;

  GameObjLinkedListNode(unsigned int ID, GameObj * gameObj) : ID_NUM(ID){
    this->gameObj = gameObj;
  }
  //~GameObjLinkedListNode(){}
};

class GameObjLinkedList {
private:
  GameObjLinkedListNode * head = NULL;
public:
  GameObjLinkedList();
  /*
    finds GameObjLinkedListNode with matching ID,
    assigns previous node of found node to PREV,
    returns node with matching ID, null if not found
  */
  GameObjLinkedListNode * find(unsigned int ID, GameObjLinkedListNode *& PREV);

  /*
    overloaded find
  */
  GameObjLinkedListNode * find(unsigned int ID);

  /*
    Finds which node to put gameObj in based on ID and assigns it.
    If not found, appends.
    returns the set node
  */
  GameObjLinkedListNode * set(unsigned int ID, GameObj * gameObj);

  /*
    Removes node with matching ID
    node will still have next pointing to the next it was connected to
    returns that node
  */
  GameObjLinkedListNode * pop(unsigned int ID);

  /*
    Removes node and deletes it
    returns false if node not found
    returns true if node was found and deleted
  */
  bool delGameObjNode(unsigned int ID);

  bool purgeAll();
  //~GameObjLinkedList(){}
};

#endif
