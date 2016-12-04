#define minsize 10
/*
class RKGC{

  private:
    long unsigned int * OBJ = new (long unsigned int*);
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

    bool full(){
      return size == actualsize - 1;
    }
};

*/

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
