
class RKGC{
  public:

  private:
    long unsigned int * OBJ;

  RKGC(){
    OBJ = (long unsigned int*)malloc(sizeof(long unsigned int ) * 10) ;
  }

  int insert(GameObject inObj){
    if(full())return 1;

    void *temp = OBJ;
    int count = 0;

    while(*temp != NULL){
      temp++;
      count++;
    }

    OBJ[count] = inObj;


  }

};





int main(){


  return 0;
}
