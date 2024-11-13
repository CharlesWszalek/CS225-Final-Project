//
// CSS 225 FINAL PROJECT 
// Name: deck.h
// Version 1.0 name: Bradon P  10/22/24 created
// Version 1.1 name: Thomas Z  10/22/24 Creating Deck class, function prototypes
// Version 1.2 name: Charles W 11/06/24 updated to match cpp
//

#ifndef DECK_CLASS
#define DECK_CLASS

#include "cards.hpp"
#include <vector>
using namespace std;


class DECK{
protected:
	static vector<CARD> cards;
public:
	DECK();
	CARD draw();
	void shuffle();
	void shuffle(int seed);
	void discard();
	void display() const;
};
#endif
