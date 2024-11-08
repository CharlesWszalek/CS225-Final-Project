//
// CSS 225 FINAL PROJECT 
// Name: deck.h
// Version 1.0 name: Bradon P 10/22/24 created
// Version 1.1 name: Thomas Z 10/22/24 Creating Deck class, function prototypes
//

#ifndef DECK_CLASS
#define DECK_CLASS

#include "cards.hpp"
#include <array>
using namespace std;


class DECK{
protected:
	array<CARD> cards;
public:
	DECK();
	CARD draw();
	void shuffle();
	void shuffle(int seed);
	void discard();
	void display() const;
};




#endif
/**/
