//
// CSS 225 FINAL PROJECT 
// Name: player.h
// Version 1.0 name: Brandon P 10/21/24 created
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand 
//

#include "cards.h"


#ifndef PLAYER_CLASS
#define PLAYER_CLASS

class PLAYER{
private:
	CARDS cards[2];
	int bet;
	static int minBet;
	int playerNum;
protected:
public:
	PLAYER(int);
	void bets();
	void raise();
	void check();
	void fold();
	void setmin();
};
#endif
