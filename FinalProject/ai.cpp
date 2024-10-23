//
// CSS 225 FINAL PROJECT 
// Name: ai.cpp
// Version 1.0 name: Brandon P 10/22/24 created
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand 
//

#include "player.hpp"
using namespace std;

AI::AI(int num): bet(0), playerNum(num), money(1500){}


int AI::bets(){
	string temp;
	cout << "Would you like to raise, check, or fold: ";
	cin >> temp;
	int change;
	if (temp == "raise"){
		change = raise();
	} else if (temp == "check"){
		change = check();
	} else if (temp == "fold"){
		change = fold();
	}
	return change;
}


void AI::setmin(){
	if (bet > minBet){
		minBet = bet;
	}
}


int AI::raise(){
	int temp = 0;
	do {
		cout << "player " << playerNum << ", What would you like to bet: ";
		cin >> temp;
		
		cout << bet+temp << " " << minBet << endl;
	}while (bet + temp < minBet);
	bet += temp;
	money -= temp;
	setmin();
	return temp;
}


int AI::check(){
	return 0;
}


int AI::fold(){
	return 0;
}
