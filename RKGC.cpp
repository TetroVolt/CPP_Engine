#define minsize 10

class GameObj {
private:
  int age;
public:
  GameObj(){

  }
  int getNum(){
    return age;
  }
};


class RKGC{
private:
  //represents the first level of objects
  GameObj * heap1;
  //second level
  GameObj * heap2;
  //third and final level
  GameObj * heap3;

  //size of each individuap heal for easy access
   unsigned int heap1Size, heap2Size, heap3Size;

  /*void doubleSize(){
    long unsigned int * OBJ2 = ;
    for (int i = 0; i < actualsize; ++i){
      (OBJ2 + i)->(OBJ + i);
    }
    for (int i = 0; i < actualsize; ++i){
      free(OBJ + i);
    }
    actualsize *= 2;
  }
  */
  //true if the first heap is full, usually called before migrating from the
  //  first heap to the second heap
  bool heap1Full(){
    GameObj *temp = heap1;
    //If we find a pointer that is pot pointing to anything we know that there
    //  is an extra space in the heap
    if(temp==NULL)return false;

    //Just moving the pointer through elements in the heap array and searving for
    //  an empty spot
    while(temp != NULL){
      temp++;
      if(temp == NULL)
        return false;
    }
    return true;
  }
  //before moving to third heap
  bool heap2Full(){
    GameObj *temp = heap2;
    if(temp==NULL)return false;

    while(temp != NULL){
      temp++;
      if(temp == NULL)
        return false;
    }
    return true;
  }

  //at this point everything is defreferenced because we ran out of space
  bool heap3Full(){
    GameObj *temp = heap3;
    if(temp==NULL)return false;

    while(temp != NULL){
      temp++;
      if(temp == NULL)
        return false;
    }
    return true;
  }

  //migrating objects that have a referance to the second heap
  void handleHeap1(){

  }
public:

  //constructor that takes in 3 parameters.  One for each of the heap arrays
  //  of GameObjs
  RKGC(unsigned int minbytes, unsigned int min2bytes, unsigned int maxbytes){
    heap1Size = minbytes; heap2Size = min2bytes;  heap3Size = maxbytes;
    heap1 = new GameObj[heap1Size];
    heap2 = new GameObj[heap2Size];
    heap3 = new GameObj[heap3Size];
  //  heap2
  }

  //takes in a gameobject and places it into the heap.
  //  migrates the heap if its full
  void create(GameObj inObj){
    if(heap1Full()){
      handleHeap1();
    }
    GameObj *temp = heap1;
    int count = 0;
    while(temp != NULL){
      temp++;
      count++;
    }
    heap1[count] = inObj;
  }

};



int main(){

  return 0;
}
