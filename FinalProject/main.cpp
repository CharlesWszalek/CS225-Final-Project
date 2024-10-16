//
//  main.cpp
//  FinalProject
//
//  Created by Charles Wszalek on 10/14/24.
//

#include <iostream>
#include "Group.h"
using namespace std;

void greeting(string name) {
    for (int i = 0; i < 5; i++) {
        cout <<"Hello "<<name <<endl;
    }
}

int main() {
    Group group("Charles Wszalek", "Brandon Pillon", "Thomas Zanin");
    group.Display();

}