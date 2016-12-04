#define minsize 10

class RKGC{
private:
  long unsigned int * heap1;
  long unsigned int * heap2;
  long unsigned int * heap3;
  int size = 0, actualsize = minsize;

  void doubleSize(){
    long unsigned int * OBJ2 = ;
    for (int i = 0; i < actualsize; ++i){
      (OBJ2 + i)->(OBJ + i);
    }
    for (int i = 0; i < actualsize; ++i){
      free(OBJ + i);
    }
    actualsize *= 2;
  }
  bool reachedCapacity(){
    return size == actualsize - 1;
  }
public:
  RKGC(unsigned int minbytes, unsigned int min2bytes, unsigned int maxbytes){
    OBJ = (long unsigned int*)malloc(sizeof(long unsigned int ) * 10);
  }
  int insert(GameObject inObj){
    if(reachedCapacity())return 1;
    void *temp = OBJ;
    int count = 0;
    while(*temp != NULL){
      temp++;
      count++;
    }
    OBJ[count] = inObj;
  }
};

class Person {
private:
  int age;
public:
  Person(int a){
    age = a;
  }
  int getNum(){
    return age;
  }
};


void * getPerson(){
  Person p = new Person(5);

  return p;
}


int main(){
  Person * p = (Person *)getPerson();
  cout
  << "p.getNum(): "
  << (p)->getNum()
  << endl;
  return 0;
}
