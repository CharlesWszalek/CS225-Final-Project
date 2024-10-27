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


PLAYER::PLAYER(int num, int buyIn):playerId(num), money(1500){hasRaised = 0;}


void PLAYER::set_min(){
	if (betMoney > minBet){
		minBet = betMoney;
	}
}


void PLAYER::display(){
	cout << "playerId:" << playerId << " money:" << money << " hasRaised:" << hasRaised << " betMoney:" << betMoney << " minBet:" << minBet << endl;//hand
}
