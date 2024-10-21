//
// CSS 225 FINAL PROJECT 
// Name: cards.h
// Version 1.0 name: Bradon P 10/18/24 Changes
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
	friend std::ostream& operator<< (std::ostream&, DECK);
};


class TABLE: public DECK{
private:
	CARDS cards[5];
protected:
public:
	void flop();
	void turnRiver();
	void showdown();
};
#endif
