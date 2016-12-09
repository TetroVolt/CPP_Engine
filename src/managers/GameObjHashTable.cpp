

#define HASH_TABLE_SIZE 11

class GameObjHashTable {
private:
  GameObjLinkedList * linkedlists;
  int hash(unsigned int ID);
public:
  GameObjHashTable();
  set(int ID, GameObj * gameobj);
  find(unsigned int ID);
  remove(unsigned int ID);
};

int GameObjHashTable::hash(){

}

GameObjHashTable::GameObjHashTable() {
  linkedlists = new GameObjLinkedList[HASH_TABLE_SIZE];
}

//Methods are not correct
GameObjHashTable::set(unsigned int ID, GameObj * gameobj) {

}

GameObj * GameObjHashTable::find(unsigned int ID) {

}

GameObj * GameObjHashTable::remove(unsigned int ID) {

}
