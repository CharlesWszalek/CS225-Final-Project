//
// CSS 225 FINAL PROJECT 
// Name: ai.cpp
// Version 1.0 name: Brandon P 10/22/24 created
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand 
//

#include "player.hpp"
using namespace std;

AI::AI(int num, int buyIn): PLAYER(num, buyIn){srand(time(NULL));}


int AI::bets(){
	if(hasRaised != -1){
		int chance = rand() % 10;
		if (chance < 4){
			raise();
		} else if (chance < 8){
			check();
		} else {
			fold();
		}
		set_min();
		return 1;
	} else {
		cout << "player has previously folded" << endl;
		return 0; //comunicate player has folded
	}
}


void AI::raise(){
	int betChange = rand() % (money - 5) + 5;/*(money - get_big_blind()) + get_big_blind()*/
	hasRaised = 1;
	money -= betChange + minBet - betMoney;
	betMoney = minBet + betChange;
	cout << "raised by " << betChange << " to " << betMoney << endl;
}
