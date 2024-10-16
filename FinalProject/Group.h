//
// Created by Charles Wszalek on 10/15/24.
//

#ifndef Group_h
#define Group_h

#include <stdio.h>
#include <string>

using namespace std;

class Group{
private:
    string name1;
    string name2;
    string name3;
public:
    Group(string, string, string);
    void Display();
};

#endif /* GroupProject_hpp */