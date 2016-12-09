#ifndef GAMEOBJHASHTABLE_H
#define GAMEOBJHASHTABLE_H

#include "GameObjLinkedList.h"
#include "../oop/GameObj.h"

/**********************************



**********************************/
class GameObjHashTable {

private: //private accessor variables and functions
  GameObjLinkedList * linkedlists;

  /** This functions maps unique
    * @param ID - unsigned integer to be hashed
    * @return - index location in linkedlists array
    * */
  int hash(unsigned int ID);


public: //public accessor functions
  GameObjHashTable(); //Constructor

  /** This functions maps a GameObj to an ID number. If ID is already in use,
    * it reassigns the pointer to that object and deletes previous object.
    * @param ID      - id to map to
    * @param gameobj - pointer to gameobj to be mapped
    * */
  void set(unsigned int ID, GameObj * gameobj);

  /** This function finds and returns a GameObj based on mapped ID
    * @param ID - ID number of GameObj to find
    * @return   - NULL if not found, pointer to GameObj if found
    * */
  GameObj * find(unsigned int ID);

  /** This function removes a GameObj from the mapped ID and returns a pointer
    * to that object.
    * @param ID - ID number of GameObj to pop off list
    * @return   - NULL if not found, pointer to popped GameObj if found
    * */
  GameObj * pop(unsigned int ID);

  /** This function deletes the GameObj mapped to the ID param
    * @param ID - ID number of GameObj to delete
    * @return   - false if unable to find object based on ID, true if found and
    * deleted.
    * */
  bool delGameObj(unsigned int ID);

  /** This functions deletes all GameObj stored in HashTable
    * */
  bool purgeAll();
};

#endif
