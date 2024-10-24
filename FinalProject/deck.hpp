//
// CSS 225 FINAL PROJECT 
// Name: deck.h
// Version 1.0 name: Bradon P 10/22/24 created
// Version 1.1 name: Thomas Z 10/22/24 Creating Deck class, function prototypes
//

#include <iostream>
#include "cards.hpp"
using namespace std;


#ifndef DECK_CLASS
#define DECK_CLASS

class DECK {
	private:
          int deck[52];
    public:
          DECK();
          CARD draw();
          void burn();
};




#endif
/*class DECK{
private:
protected:
	std::vector<CARDS> cards;
public:
	DECK();
	CARDS draw();
	void shuffle();
	void discard();
	friend std::ostream& operator<< (std::ostream&, DECK);
};*/