//
// CSS 225 FINAL PROJECT 
// Name: table.h
// Version 1.0 name: Bradon P 10/21/24 Changes moved table to seperate header file
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
//


#ifndef TABLE_CLASS
#define TABLE_CLASS

#include "cards.hpp"
#include "player.hpp"
#include "deck.hpp"
#include "cards.hpp"
#include "hand.hpp"
using namespace std;

class TABLE{
private:
	int numPlayers;
	PLAYER* players[22];
	int pot;
	int buyIn;
	static int playerTurn;
public:
	TABLE(int Input, int buyIn);
	DECK deck;
	CARD cards[5];
	void buy_in(int buyIn);
	void flop();
	void betting();
	void turn();
	void river();
	void showdown();
	void display() const;
	static int bigBlind;
	void next_player();
	void royal_flush(int mhands[][5][14], int scoring[][10]);
	void flush(int mhands[][5][14], int scoring[][10]);
	void straight(int mhands[][5][14], int scoring[][10]);
	void highcard(int mhands[][5][14], int scoring[][10]);
	void blankofakind(int mhands[][5][14], int scoring[][10], int player, int num);
	void two_pair(int mhands[][5][14], int scoring[][10], int player);
	void straight_flush();
	void full_house();
};
#endif
