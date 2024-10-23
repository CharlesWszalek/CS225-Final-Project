//
// CSS 225 FINAL PROJECT 
// Name: deck.h
// Version 1.0 name: Bradon P 10/22/24 created
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
//

#include <iostream>
#include <vector>

#ifndef DECK_CLASS
#define DECK_CLASS

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
