
#include "GameObjLinkedList.h"
//#include <string>

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

/*
//For ctrl shift b  testing purposes, comment out later

class Playerchar : public GameObj {
string name;
public:
  Playerchar(string name, int type) : GameObj(type) {
    this->name = name;
  }
  string getName(){
    return name;
  }
  ~Playerchar(){
    std::cout << "Playerchar being deleted." << std::endl;
  }
};

int main(){
  std::cout << "\nLinkedList Test:\n" << std::endl;
  GameObjLinkedList * myList = new GameObjLinkedList();


  string names[] = {"John", "Harry", "Jacob"};

  Playerchar * currPlayer = NULL;

  for (unsigned int i = 0; i < 3; ++i) {
    currPlayer = new Playerchar(names[i], 1);
    myList->set(i, currPlayer);
    std::cout << "===============================\n" << std::endl;
    std::cout << "Added Player: " << currPlayer->getName() << std::endl;
  }

  std::cout << "\n\\===================\\\n" << std::endl;
  std::cout << "Find Tests: \n" << std::endl;

  currPlayer = NULL;
  GameObjLinkedListNode * searched;
  for (unsigned int i = 0; i < 4; ++i) {
    searched = myList->find(i);
    if (searched != NULL) {
      currPlayer = (Playerchar *)(searched->gameObj);
      std::cout << "myList->find(" << i << ") :=> " << currPlayer->getName() << std::endl;
    }
  }


  std::cout << "\n===========\nDelete tests:\n" << std::endl;

  currPlayer = NULL;
  for (unsigned int i = 0; i < 4; ++i) {
    searched = myList->find(i);
    if (searched != NULL) {
      std::cout << "myList->delGameObjNode(" << i << ") => " << (bool)(myList->delGameObjNode(i)) << myList<< std::endl;
    }
  }

  std::cout << "\n\\===================\\\n" << std::endl;
  std::cout << "Find Tests 2: \n" << std::endl;

  currPlayer = NULL;
  searched = NULL;
  for (unsigned int i = 0; i < 4; ++i) {
    searched = myList->find(i);
    if (searched != NULL) {
      currPlayer = (Playerchar *)(searched->gameObj);
      std::cout << "myList->find(" << i << ") :=> " << currPlayer->getName() << std::endl;
    }
  }

}

*/
