//
// CSS 225 FINAL PROJECT 
// Name: table.hpp
// Version 1.0 name: Brandon P 10/21/24 Changes moved table to seperate header file
//	   1.1 name: Thomas Z  10/23/24 created new fucntions 
//	   1.2 name: Charles W 10/27/24 created showdown function
//	   1.3 name: Charles W 10/30/24 added hand checkers for showdown
//	   1.4 name: Charles W 11/02/24 added hand checkers for showdown
//	   1.5 name: Thomas Z  11/03/24 added hand checkers for showdown
//	   1.6 name: Charles W 11/07/24 added hand checkers for showdown
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
	PLAYER* players[6];
	int pot;
	int buyIn;
	static int playerTurn;
public:
	TABLE(int Input, int buyIn);
	~TABLE();
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
	void straight_flush(int mhands[][5][14], int scoring[][10]);
	void flush(int mhands[][5][14], int scoring[][10]);
	void straight(int mhands[][5][14], int scoring[][10]);
	void highcard(int mhands[][5][14], int scoring[][10]);
	void blank_of_a_kind(int mhands[][5][14], int scoring[][10], int player, int num);
	void two_pair(int mhands[][5][14], int scoring[][10], int player);
	void full_house(int mhands[][5][14], int scoring[][10]);
};
#endif
