//
// Created by Charles Wszalek on 10/15/24.
//

#include "scratch1.h"

class Person {
  private:
    string name;
  public:
    Person(string name){
      this -> name = name;
      cout << "Person name: " << name << endl;
    }
    ~Person(){
      cout << "Person gone. " << endl;
    }
};
