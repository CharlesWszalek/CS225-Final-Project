//
// Created by Charles Wszalek on 10/15/24.
//

#include <iostream>
#include <cstdio>
#include "Group.h"

using namespace std;

Group::Group(string name1, string name2, string name3){
    this -> name1 = name1;
    this -> name2 = name2;
    this -> name3 = name3;
};

void Group::Display(){
    cout << "Group with members: " << name1 << ", " << name2 << ", " << name3 << " created. " << endl;
};