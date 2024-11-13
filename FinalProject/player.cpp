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

// players can not bet negative money 
int PLAYER::minBet = 0;

// player constructor
PLAYER::PLAYER(int num, int buyIn, DECK d): playerId(num), hand(d), money(buyIn), betMoney(0), hasRaised(0){minBet = 0;}

// player deconstructor 
PLAYER::~PLAYER(){}

// minimum bet is updated by the buy in
void PLAYER::set_min(){
	if (betMoney > minBet){
		minBet = betMoney;
	}
}

// show the player's details
void PLAYER::display(){
	cout << "playerId:" << playerId << " money:" << money << " hasRaised:" << hasRaised << " betMoney:" << betMoney << " minBet:" << minBet << endl;//hand
}

// allows the player to check 
int PLAYER::check(){
	int moneyForPot = + minBet - betMoney;
	cout << check_or_call() << "ed at " << minBet << endl;
	money -= moneyForPot; // removes money from their hand 
	betMoney = minBet;
	return moneyForPot;
}

// allows the player to call or check 
string PLAYER::check_or_call(){
	if (minBet == betMoney){
		return "check";
	} else {
		return "call";
	}
}

// allows the player to fold and stop playing
void PLAYER::fold(){
	hasRaised = -1; // -1 means folded in all cases
	cout << "folded" << endl;
}

// return the players hand
HAND& PLAYER::get_hand(){return hand;}

// return the player's money
int PLAYER::get_money() const {return money;};

// return the player's id (index of the player)
int PLAYER::get_playerId() const {return playerId;};

// resets the amount raised
void PLAYER::reset_raised(){hasRaised = 0;}

// checks to see if the player has raised
int PLAYER::get_hasRaised() const {return hasRaised;}

// returns the player's name (user input or ai #)
string PLAYER::get_name() const {return name;}
