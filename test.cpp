#include <iostream>

using namespace std;

class myInterface {
public:
  bool mybool;
  virtual void setBool(bool b) = 0;
  virtual bool getBool() = 0;
};

/*
class Hashable {
public:
  virtual unsigned long  hashCode() = 0;
}
*/
class myObj : public myInterface {
public:
  myObj(){}
  void setBool(bool b){
    mybool = b;
  }
  bool getBool() {
    return mybool;
  }

  //unsigned long int hashCode() { return this; }
};

int main(){
  myObj myobj;
  std::cout << "myobj.getBool() : " << myobj.getBool() << std::endl;
  myobj.setBool(true);
  std::cout << "myobj.setBool(true)" << std::endl;
  std::cout << "myobj.getBool() : " << myobj.getBool() << std::endl;


  std::cout << "\nStorage size for long : " << sizeof(long) << std::endl;

}
