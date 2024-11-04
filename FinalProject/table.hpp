//
// CSS 225 FINAL PROJECT 
// Name: table.h
// Version 1.0 name: Bradon P 10/21/24 Changes moved table to seperate header file
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
//

#include "cards.hpp"
#include "player.hpp"
#include "deck.hpp"
#include "cards.hpp"
using namespace std;

#ifndef TABLE_CLASS
#define TABLE_CLASS

class TABLE{
private:
	int numPlayers;
	CARD cards[5];
	PLAYER* players[5];
	int pot;
	int buyIn;
	int bigBlind;
public:
	TABLE(int Input);
	void buy_in(int buyIn);
	void flop();
	void betting();
	void turn();
	void river();
	void showdown();
	void display() const;
	int get_big_blind();
};
#endif
