//
// CSS 225 FINAL PROJECT 
// Name: table.h
// Version 1.0 name: Bradon P 10/21/24 Changes moved table to seperate header file
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
//

#include "cards.h"
#include "player.h"

#ifndef TABLE_CLASS
#define TABLE_CLASS

class TABLE{
private:
	CARDS cards[5];
	DECK deck;
	PLAYER* player[4];
protected:
public:
	TABLE();
	void buyIn();
	void flop();
	void betting();
	void turn();
	void river();
	void showdown();
	friend std::ostream& operator<< (std::ostream&, DECK);
	void display();
};
#endif
