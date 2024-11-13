//
// CSS 225 FINAL PROJECT 
// Name: ai.cpp
// Version 1.0 name: Brandon P 10/22/24 created
// 	   1.2 name: Brandon P 10/29/24 transfered the code from human to ai for bets and raise 
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand 
//

#include "player.hpp"
#include "table.hpp"
#include <string>
using namespace std;

// Constructor
AI::AI(int num, int buyIn, DECK d): PLAYER(num, buyIn, d){srand(time(NULL));name = "Ai " + to_string(num);}

// Checks to see if the ai players can bet and then control how much they are allowed to bet
int AI::bets(){
	if(hasRaised != -1){
		int forPot; // amount of money addded to the pot 
		int chance = rand() % 10;  // randomly determine the behavior the the ai
		if (chance < 4 && hasRaised == 0 && minBet - betMoney + TABLE::bigBlind <= money){
			forPot = raise();
		} else if (chance < 8){
			forPot = check();
		} else {
			fold();
			return 0;
		}
		set_min();
		return forPot;
	} else {
		cout << "player has previously folded" << endl;
		return 0; 
	}
}

// Checks to see if the ai players can raise and then control how much they are allowed to put into the pot
int AI::raise(){
	int betChange;
	if (money - minBet + betMoney - TABLE::bigBlind == 0){
		betChange = 5;
	} else {
		betChange = rand() % (money - minBet + betMoney - TABLE::bigBlind) + TABLE::bigBlind + 1;  // randomly determine the behavior the the ai
	}
	hasRaised = 1;
	int moneyForPot = betChange + minBet - betMoney;
	money -= moneyForPot; // remove the money from the ai's hand
	betMoney = minBet + betChange;
	cout << "raised by " << betChange << " to " << betMoney << endl;
	return moneyForPot;
}
