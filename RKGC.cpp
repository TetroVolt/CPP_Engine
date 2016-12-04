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
  bool heap1Full(){
    GameObj *temp = &heap1[0];
    if(temp==NULL)return false;

    while(temp != NULL){
      if(temp == NULL)
        return false;
    }
    return true;
  }
  bool heap2Full(){
    return false;
  }
  bool heap3Full(){
    return false;
  }
  void handleHeap1(){

  }
public:
  RKGC(unsigned int minbytes, unsigned int min2bytes, unsigned int maxbytes){
    heap1Size = minbytes; heap2Size = min2bytes;  heap3Size = maxbytes;
    heap1 = new GameObj[heap1Size];
    heap2 = new GameObj[heap2Size];
    heap3 = new GameObj[heap3Size];
  //  heap2
  }
  void insert(GameObj inObj){
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
