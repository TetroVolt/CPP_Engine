//Remove this


//These includes only for testing CTRL SHIFT B
#include "../oop/GameObj.h"
#include "../oop/GameObj.cpp"

class GameObjLinkedListNode {
public:
  GameObjLinkedListNode * next = NULL;
  //GameObjLinkedListNode * prev = NULL;
  const unsigned int ID_NUM;
  GameObj * gameObj;
  GameObjLinkedListNode(unsigned int ID, GameObj * val){
    ID_NUM = ID;
    gameObj = val;
  }

  /*
  bool deleteGameObj(){
    delete gameObj;
    return true;
  }
  */
};

class GameObjLinkedList {
private:
  GameObjLinkedListNode * head = NULL;

public:
  //Constructor
  GameObjLinkedList() {  }

  /**
    * Returns GameObjLinkedListNode or Null if not found
    */
  GameObjLinkedListNode * search(int ID) {
    GameObjLinkedListNode * curr = head;
    GameObjLinkedListNode * ret == NULL;
    while (curr->next != NULL) { //Iterate through
      if (curr->gameObj->getID() == ID) { //If matching ID
        ret = curr->gameObj;
        break;
      }
    }
    return ret; //Return LinkedListNode
  }

  bool def(GameObj * gameObj) {
    if (head == NULL) {
      head = new GameObjLinkedListNode(gameObj);
    } else {
      GameObjLinkedListNode * curr = head;
      while (curr->next != NULL) {
        if (curr->gameObj == gameObj) {
          return true;
        }
        curr = curr->next;
      }
      //While loop will terminate where curr is last node and curr->next == NULL
      //Remember curr->gameObj != gameObj
      curr -> next = new GameObjLinkedListNode(gameObj);
    }
    return false;
  }

  GameObjLinkedListNode * append(GameObj * gameObj){
    if (head == NULL) {
      head = new GameObjLinkedListNode(gameObj);
      tail = head;
      return head; //May not be a good idea
    }

    tail->next = new GameObjLinkedListNode(gameObj);
    tail = tail->next;
    return tail;
  }

  GameObj * get(unsigned int ID){
    GameObj * ret = NULL;
    GameObjLinkedListNode * find = search(ID);
    if (find != NULL) {
      ret = find->gameObj;
    }
    return ret;
  }

  bool remove(unsigned int ID){

  }
};



class GameObjHashTable {
  unsigned const int ARRAY_SIZE = 11;
  GameObjLinkedList * gameobjlinkedlists;

  unsigned int hash(unsigned int ID) {
    return ID % ARRAY_SIZE;
  }
public:
  GameObjHashTable() {
    gameobjlinkedlists = new GameObjLinkedList[ARRAY_SIZE];
    /*
    for (int i = 0; i < ARRAY_SIZE; ++i) {
      gameobjlinkedlists[i] = new GameObjLinkedList();
    }
    */
  }



  void def(GameObj * gameObj) {
    if (gameObj == NULL) { return; }
    int pos = hash(gameObj->getID()); //Which linkedlist it should go

    if (gameobjlinkedlists[pos] == NULL) {
      gameobjlinkedlists[pos] = new GameObjLinkedList();
    }

    gameobjlinkedlists[pos]->set(gameObj); //Set it
  }

  GameObj * get(unsigned int ID){
    int pos = hash(gameObj->getID()); //Where it should be

    if (gameobjlinkedlists[pos] == NULL) { return NULL; } //If null return null

    GameObj * ret = gameobjlinkedlists[pos]->get(ID); //retrieve pointer
    return ret;
  }

  bool remove(unsigned int ID){
    int pos = hash(ID); //Where it should be
    if (gameobjlinkedlists[pos] == NULL) { //If null return false
      //No such object exists
      return false;
    }
    return gameobjlinkedlists[pos]->remove(ID);
  }

};
