#define minsize 10

class GameObj {
private:
  int age;
public:
  GameObj(int a){
    age = a;
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
  const int heap1Size = 10, heap2Size = 25, heap3Size = 50;

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
    return false;
  }
  bool heap2Full(){
    return false;
  }
  bool heap3Full(){
    return false;
  }
public:
  RKGC(unsigned int minbytes, unsigned int min2bytes, unsigned int maxbytes){
    //OBJ = (GameObj*)malloc(sizeof(GameObj ) * 10);
  }
  /*void insert(GameObj inObj){
    if(heap1Full(){
      handleHeap1();
    }
    void *temp = OBJ;
    int count = 0;
    while(*temp != NULL){
      temp++;
      count++;
    }
    OBJ[count] = inObj;
  }
  */
};



int main(){

  return 0;
}
