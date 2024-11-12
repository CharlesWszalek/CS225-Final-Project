//
// CSS 225 FINAL PROJECT 
// Name: player.cpp
// Version 1.0 name: Brandon P 10/22/24 created
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand 
//

#include "player.hpp"
#include <iostream>
#include <climits>
using namespace std;

int PLAYER::minBet = 0;


PLAYER::PLAYER(int num, int buyIn, DECK d):playerId(num), hand(d), money(buyIn), betMoney(0), hasRaised(0){}


PLAYER::~PLAYER(){}


void PLAYER::set_min(){
	if (betMoney > minBet){
		minBet = betMoney;
	}
}


void PLAYER::display(){
	cout << "playerId:" << playerId << " money:" << money << " hasRaised:" << hasRaised << " betMoney:" << betMoney << " minBet:" << minBet << endl;//hand
}


int PLAYER::check(){
	int moneyForPot = + minBet - betMoney;
	cout << check_or_call() << "ed at " << minBet << endl;
	money -= moneyForPot;
	betMoney = minBet;
	return moneyForPot;
}


string PLAYER::check_or_call(){
	if (minBet == betMoney){
		return "check";
	} else {
		return "call";
	}
}


void PLAYER::fold(){
	hasRaised = -1;
	cout << "folded" << endl;
}


HAND& PLAYER::get_hand() {return hand;}


int PLAYER::get_money() const {return money;};


int PLAYER::get_playerId() const {return playerId;};


void PLAYER::reset_raised(){hasRaised = 0;}


int PLAYER::get_hasRaised() const {return hasRaised;}


string PLAYER::get_name() const {return name;}
