#include <iostream>

using namespace std;


class Person {
protected:
  int age;
public:
  Person();
  Person(int);
  int getAge();
};
Person::Person(){}
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
};

Employee::Employee(int a, int s){
  age = a;
  salary = s;
}

int Employee::getSalary(){
  return salary;
}

int main(){
Person * p = new Person(5);
Person * e = new Employee(7, 50000);



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


return 0;
}
