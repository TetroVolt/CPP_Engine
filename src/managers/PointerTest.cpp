#include <typeinfo>
#include <type_traits>
#include <iostream>

class LLN {
public:
  int myData = 0;
  LLN * next;
  LLN(int i){ myData = i; }
};

class LL {
private:
  LLN * head = NULL;
  LLN * tail = NULL;
public:
  LL(){}
  LLN * append(int data) {
    LLN * ret = NULL;
    if (head == NULL) {
      head = new LLN(data);
      tail = head;
    } else {
      tail->next = new LLN(data);
      tail = tail->next;
      //tail = tail->next;
    }
    ret = tail;
    return ret;
  }

  LLN * find(int data, LLN*& PREV){
    LLN * curr = head;
    LLN * ret = NULL;
    while (curr != NULL) {
      if (curr->myData == data) {
        ret = curr;
        break;
      }
      PREV = curr;
      curr = curr->next;
    }
    return ret;
  }

  LLN * find(int data){
    LLN * prev = NULL; //Unused variable to avoid writing duplicate code
    //Not sure if prev is deallocated after this function finishes

    LLN * ret = find(data, prev);
    //delete &prev;
    return ret;
  }

};

bool getBool(bool b) {
  return b ^ b || b;
}

int main(){
  /*
  LL * list = new LL();
  for (int i = 0; i< 10; ++i) {
    list->append(i);
  }

  for (int i = 0; i < 10; ++i) {
    std::cout << "List[" << i << "] : " << list->find(i)->myData << std::endl;
  }

  std::cout << "\n=============\n" << std::endl;

  LLN * PREV = NULL;
  LLN * found = list->find(5, PREV);

  std::cout << "found[5]::(PREV==NULL) : " << (PREV==NULL) << std::endl;
  //std::cout << "found[5]::PREV->myData : " << PREV->myData << std::endl;
  std::cout << "found[5] : " << found->myData << std::endl;


  std::cout << "typeid(list) : " << typeid(list).name() << std::endl;
  */

  
}
