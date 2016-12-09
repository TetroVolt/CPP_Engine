
#include "GameObjLinkedList.h"

using namespace std;

//Constructor
GameObjLinkedList::GameObjLinkedList(){ }

GameObjLinkedListNode * GameObjLinkedList::find(unsigned int ID, GameObjLinkedListNode *& PREV) {
  GameObjLinkedListNode * ret = NULL;
  GameObjLinkedListNode * curr = head;

  while (curr != NULL) {      //Iterate through
    if (curr->ID_NUM == ID) { //If match
      ret = curr;             //Set ret to curr
      break;
    }
    PREV = curr;       //(PREV == NULL) == (ret == HEAD)
    curr = curr->next; //else keep going
  }

  return ret; //If ret NULL, not found
}

GameObjLinkedListNode * GameObjLinkedList::find(unsigned int ID) {
  GameObjLinkedListNode * PREV = NULL; //Dummy variable
  GameObjLinkedListNode * ret = find(ID, PREV);
  return ret;
}

GameObjLinkedListNode * GameObjLinkedList::set(unsigned int ID, GameObj * gameObj) {

  if (head == NULL) {
    head = new GameObjLinkedListNode(ID, gameObj);
    return head;
  }

  GameObjLinkedListNode * PREV = NULL;
  GameObjLinkedListNode * search = NULL;
  search = find(ID, PREV);

  if (search == NULL) { //Cant find, must append new one
    PREV->next = new GameObjLinkedListNode(ID, gameObj);
    return PREV->next;
  }

  GameObj * go = search->gameObj;
  delete go;
  search->gameObj = gameObj; //straightforward assignment
  return search;
}

GameObjLinkedListNode * GameObjLinkedList::pop(unsigned int ID) {
  GameObjLinkedListNode * ret = NULL;

  if (head->ID_NUM == ID) { //Special case for head node
    ret = head;
    head = head->next;
    return ret;
  }

  GameObjLinkedListNode * PREV = NULL;
  ret = find(ID, PREV);

  if (ret == NULL) { return NULL; }

  PREV->next = ret->next; //Stitch together

  return ret;
}

bool GameObjLinkedList::delGameObjNode(unsigned int ID) {
  GameObjLinkedListNode * found = pop(ID);

  if (found == NULL) return false;

  found->next = NULL; //disconnects next node
  /*
  GameObj * gameObj = found->gameObj;
  delete gameObj;
  */
  delete found;
  return true;
}

bool GameObjLinkedList::purgeAll() {
  if (head == NULL) return false;

  GameObjLinkedListNode * curr = head;
  while (curr->next != NULL) {
    head = head->next;
    delete curr;
    curr = head;
  }
  delete curr;

  return true;
}
