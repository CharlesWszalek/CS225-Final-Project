//
// CSS 225 FINAL PROJECT 
// Name: cards.h
// Version 1.0 name: Bradon P 10/18/24 Changes created header file
// Version 1.1 name: Bradon P 10/21/24 Changes changed table from being child to containing deck
// Version 1.2 name: Bradon P 10/21/24 Changes moved table to new file
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
//

#include <iostream>
#include <vector>

#ifndef CARD_CLASS
#define CARD_CLASS

typedef struct {
	std::string suit;
	std::string name;
	int value;
} CARDS;


class DECK{
private:
protected:
	std::vector<CARDS> cards;
public:
	DECK();
	CARDS draw();
	void shuffle();
	void discard();
	friend std::ostream& operator<< (std::ostream&, DECK);
};
#endif
