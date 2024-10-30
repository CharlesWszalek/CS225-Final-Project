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
protected:
	int playerId;
	HAND hand;//change to hand when we have one
	int money;
	int betMoney;
	int hasRaised;
	static int minBet;
	virtual void check();
	virtual void fold();
public:
	PLAYER(int, int);
	void display();
	HAND get_hand() const {return hand;}
	int get_money(){return money;};
	int get_playerId(){return playerId;};
	void set_playerId();
	void set_min();
	virtual void reset_raised(){hasRaised = 0;};
	virtual int bets() = 0;
};


class HUMAN: public PLAYER{
private:
	string name;
	void raise();
protected:
public:
	HUMAN(int, int=100);
	string check_or_call();
	int bets();
	int conv_string_int(string);/*separate file*/
};


class AI: public PLAYER{
private:
	void raise();
protected:
public:
	AI(int, int=100);
	int bets();
};
#endif
