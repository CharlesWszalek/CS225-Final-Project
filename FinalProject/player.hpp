//
// CSS 225 FINAL PROJECT 
// Name: player.h
// Version 1.0 name: Brandon P 10/21/24 created
// 	   1.1 name: Brandon P 10/26/24 added parent class HUMAN
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand 
//

#include "cards.hpp"

#ifndef PLAYER_CLASS
#define PLAYER_CLASS
using namespace std;


class PLAYER{
private:
	virtual void raise() = 0;
	virtual void check() = 0;
	virtual void fold() = 0;
protected:
	int playerId;
	CARDS cards[2];//change to hand when we have one
	int money;
	int betMoney;
	int hasRaised;
	static int minBet;
public:
	PLAYER(int, int);
	void display();
	CARDS* get_hand(){return cards;};
	int get_money(){return money;};
	int get_playerId(){return playerId;};
	void set_playerId();
	void set_min();
	virtual void reset_raised(){hasRaised = 0;};
	virtual int bets() = 0;
};


class HUMAN: public PLAYER{
private:
	//int playerId;
	string name;
	/*CARDS cards[2];//change to hand when we have one
	int money;
	int betMoney;
	int hasRaised;
	static int minBet;*/
	void raise();
	void check();
	void fold();
protected:
public:
	HUMAN(int, int=100);
	//void display();
	string check_or_call();
/*	CARDS* get_hand(){return cards;};
	string get_name(){return name;};
	int get_money(){return money;};
	//int get_playerId(){return playerId;};
	void set_playerId();
	void set_min();
	void reset_raised(){hasRaised = 0;};*/
	int bets();
	int conv_string_int(string);
};


class AI: public HUMAN{
};
#endif
