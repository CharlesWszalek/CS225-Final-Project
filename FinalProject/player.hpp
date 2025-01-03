//
// CSS 225 FINAL PROJECT 
// Name: player.hpp
// Version 1.0 name: Brandon P 10/21/24 created
// 	   1.1 name: Brandon P 10/26/24 added parent class HUMAN and made the getter functions 
//	   1.2 name: Brandon P 10/30/24 made folding be "-1"
//	   1.3 name: Brandon P 11/10/24 fixed final betting bugs
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand 
//

#ifndef PLAYER_CLASS
#define PLAYER_CLASS

#include "hand.hpp"
using namespace std;


class PLAYER{
private:
	virtual int raise() = 0;
protected:
	int playerId;
	HAND hand;//change to hand when we have one
	int money;
	int betMoney;
	int hasRaised;
	static int minBet;
	virtual int check();
	virtual void fold();
	string name;
public:
	PLAYER(int, int, DECK);
	virtual ~PLAYER();
	void display();
	string check_or_call();
	HAND& get_hand();
	int get_money() const;
	int get_playerId() const;
	void set_min();
	virtual void reset_raised();
	virtual int bets() = 0;
	int get_hasRaised() const;
	string get_name() const;
};


class HUMAN: public PLAYER{
private:
	int raise();
protected:
public:
	HUMAN(int, int, DECK);
	int bets();
};


class AI: public PLAYER{
private:
	int raise();
protected:
public:
	AI(int, int, DECK);
	int bets();
};

#endif
