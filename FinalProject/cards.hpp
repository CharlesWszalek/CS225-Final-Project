//
// CSS 225 FINAL PROJECT 
// Name: cards.h
// Version 1.0 name: Bradon P  10/18/24 Changes created header file
// 	   1.1 name: Bradon P  10/21/24 Changes changed table from being child to containing deck
// 	   1.2 name: Bradon P  10/21/24 Changes moved table to new file
// 	   1.3 name: Thomas Z  10/22/24 Starting work on file
// 	   1.4 name: Charles W 10/30/24 updated to match cpp
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
//

#ifndef CARD_CLASS
#define CARD_CLASS

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class CARD {
private:
	string suit;
	string name;
	int value;
public:
	CARD();
	CARD(string, string);
	void display() const;
	void set_suit(string);
	void set_value(int);
	string get_suit();
	int get_suit_2();
	string get_name();
	int get_value();
};
#endif
