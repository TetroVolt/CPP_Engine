/**
This program tests the size of classes and subclasses
along with size of the instantiated objects respectively.

*/


#include <iostream>

using namespace std;


class Person {
protected:
  int age;
public:
  Person();
  Person(int);
  int getAge();
  ~Person(){
    std::cout << "Destroying person" << std::endl;
  }

  void suicide(){
    delete this;
  }
};
Person::Person(){
  std::cout << "Creating Person " << std::endl;
}
Person::Person(int a){
  age = a;
}

int Person::getAge(){
  return age;
}

class Employee: public Person {
private:
  long int salary;
public:
  Employee(int, int);
  int getSalary();
  ~Employee(){
    std::cout << "Destroying Employee" << std::endl;
  }
};

Employee::Employee(int a, int s){
  age = a;
  salary = s;
  std::cout << "Creating Employee" << std::endl;
}

int Employee::getSalary(){
  return salary;
}

int main(){
Person * p = new Person(5);
Person * e = new Employee(7, 50000);

/*
cout
<< "sizeof(Person):"
<< sizeof(Person)
<< "\n"
<< "sizeof(Employee):"
<< sizeof(Employee)
<< "\n"
<< "sizeof(*p):"
<< sizeof(*p)
<< "\n"
<< "sizeof(p):"
<< sizeof(p)
<< "\n\n";

cout
<< "sizeof(e):"
<< sizeof(e)
<< "\n"
<< "sizeof(*e):"
<< sizeof(*e)
<< "\n"
<< "sizeof((Employee*)e):"
<< sizeof((Employee*)e)
<< endl
<< "sizeof(*(Employee*)e):"
<< sizeof(*(Employee*)e)
<< endl;
*/
/*
delete p;
delete e;

std::cout << "Past Delete. " << std::endl;

std::cout << "\np == NULL: " << (p == NULL) << std::endl;
std::cout << "e == NULL: " << (e == NULL) << std::endl;

std::cout << "\n e salary: " << ((Employee *)e)->getSalary() << std::endl;

std::cout << "Near return 0." << std::endl;
*/

p->suicide();
e->suicide();

std::cout << "p->getAge() : " << p->getAge() << std::endl;
std::cout << "e->getAge() : " << e->getAge() << std::endl;

return 0;
}
