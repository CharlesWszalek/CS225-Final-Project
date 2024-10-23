//
// CSS 225 FINAL PROJECT 
// Name: player.h
// Version 1.0 name: Brandon P 10/21/24 created
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand 
//

#include "cards.hpp"

#ifndef PLAYER_CLASS
#define PLAYER_CLASS
using namespace std;


class PLAYER{
private:
	int playerId;
	string name;
	CARDS cards[2];//change to hand when we have one
	int money;
	int betMoney;
	int hasRaised;
	static int minBet;
protected:
public:
	PLAYER(int);
	void display();
	CARDS* get_hand(){return cards;};
	string get_name(){return name;};
	int get_money(){return money;};
	int get_playerId(){return playerId;};
	void set_playerId();
	void set_min();
	void reset_raised(){hasRaised = 0;};
	int bets();
	int raise();
	int check();
	int fold();
};

/*
class HUMAN{
private:
	int playerId;
	string name;
	CARDS cards[2];//change to hand when we have one
	int money;
	static int minBet;
protected:
public:
	PLAYER(int);
	void display();
	int get_hand();
	string get_name();
	int get_money();
	int get_playerId();
	void set_playerId();
	void set_min();
	int bets();
};


class AI{
private:
	int playerId;
	string name;
	CARDS cards[2];//change to hand when we have one
	int money;
	static int minBet;
protected:
public:
	PLAYER(int);
	void display();
	int get_hand();
	string get_name();
	int get_money();
	int get_playerId();
	void set_playerId();
	void set_min();
	int bets();
};*/
#endif
