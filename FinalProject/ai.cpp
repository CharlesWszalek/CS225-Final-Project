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


AI::AI(int num, int buyIn): PLAYER(num, buyIn){srand(time(NULL));name = "Ai " + to_string(num);}


int AI::bets(){
	if(hasRaised != -1){
		int forPot;
		int chance = rand() % 10;
		if (chance < 4 && hasRaised == 0 && minBet - betMoney + TABLE::bigBlind <= money){
			forPot = raise();
		} else if (chance < 8){
			forPot = check();
		} else {
			fold();
			return -1;
		}
		set_min();
		return forPot;
	} else {
		cout << "player has previously folded" << endl;
		return -1; //comunicate player has folded
	}
}


int AI::raise(){
	int betChange;
	if (money - minBet + betMoney - TABLE::bigBlind == 0){
		betChange = 5;
	} else {
		betChange = rand() % (money - minBet + betMoney - TABLE::bigBlind) + TABLE::bigBlind + 1;
	}
	hasRaised = 1;
	int moneyForPot = betChange + minBet - betMoney;
	money -= moneyForPot;
	betMoney = minBet + betChange;
	cout << "raised by " << betChange << " to " << betMoney << endl;
	return moneyForPot;
}
