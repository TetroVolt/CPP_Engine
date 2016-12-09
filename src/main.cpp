#define PLAYERTYPE 1

//#include "SDL2/SDL.h"
#include <iostream>
//#include "Game.h"
#include "./managers/GameObjHashTable.h"
#include "./oop/GameObj.h"
#include <string>

using namespace std;

class Player : public GameObj {
public:
  string name;
  Player(string name) : GameObj(PLAYERTYPE) {
    std::cout << "Constructing player with name: " << name << std::endl;
    this->name = name;
  }
};

void test(){
  GameObjHashTable * hashtable = new GameObjHashTable();
  GameObj * curr = NULL;

  int LEN = 6;
  unsigned int IDS[] = { 12352, 23456, 23167, 57234, 34653, 34566 };
  string names[] = {"John", "Jacob", "Henry", "Albert", "Austin", "Barry" };
  for (int i = 0; i < LEN; ++i) {
    curr = new Player(names[i]);
    hashtable->set(IDS[i], curr);
  }

  std::cout << "|========= Searching for Players =========|" << std::endl;
  curr = NULL;
  for (int i = 0; i < LEN; ++i) {
    curr = (Player*)hashtable->find(IDS[i]);
    std::cout << "Player[" << IDS[i]<< "] => ";
    if (curr != NULL) {
      std::cout << ((Player*)curr)->name << std::endl;
    } else {
      std::cout << "NULL" << std::endl;
    }
  }

  std::cout << "|========= Deleting for Players =========|" << std::endl;
  curr = NULL;
  for (int i = 0; i < LEN; ++i) {
    hashtable->delGameObj(IDS[i]);
  }

  std::cout << "|========= Searching for Players =========|" << std::endl;
  curr = NULL;
  for (int i = 0; i < LEN; ++i) {
    curr = (Player*)hashtable->find(IDS[i]);
    std::cout << "Player[" << IDS[i]<< "] => ";
    if (curr != NULL) {
      std::cout << ((Player*)curr)->name << std::endl;
    } else {
      std::cout << "NULL" << std::endl;
    }
  }
}

int main(){
  std::cout << "\n|==========| tests |==========|\n" << std::endl;
  test();
  /*
  Game *game = new Game();
  //Game method exitGame() is called when the game loop terminates
  game -> run();
  delete game;
  */
}
