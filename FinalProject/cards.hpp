//
// CSS 225 FINAL PROJECT 
// Name: cards.h
// Version 1.0 name: Bradon P 10/18/24 Changes created header file
// 	   1.1 name: Bradon P 10/21/24 Changes changed table from being child to containing deck
// 	   1.2 name: Bradon P 10/21/24 Changes moved table to new file
// 	   1.3 name: Thomas Z 10/22/24 Starting work on file
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;


#ifndef CARD_CLASS
#define CARD_CLASS

class CARD {
	private:
		string suit;
		string name;
public:
		CARD();
		void display();
		void set_suit(string);
		void set_rank(string);
		string get_suit();
		string get_name();
};
#endif
