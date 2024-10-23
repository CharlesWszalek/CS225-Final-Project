//
// CSS 225 FINAL PROJECT 
// Name: player.cpp
// Version 1.0 name: Brandon P 10/21/24 created
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand 
//

#include "player.hpp"
using namespace std;

int PLAYER::minBet = 0;


PLAYER::PLAYER(int num):playerId(num), money(1500){}


int PLAYER::bets(){
	string temp;
	cout << "Would you like to raise, check, or fold: "; //cannot raise if raised already
	cin >> temp;
	int change = 0;
	if (temp == "raise"){
		change = raise();
	} else if (temp == "check"){
		change = check();
	} else if (temp == "fold"){
		change = fold();
	} else {
		cout << "something wend wrong" << endl;
	}
	return change;
}


void PLAYER::set_min(){
	if (betMoney > minBet){
		minBet = betMoney;
	}
}


int PLAYER::raise(){
	int temp = 0;
	do {
		cout << name << " : ";
		cin >> temp;
		
		cout << betMoney+temp << " " << minBet << endl;
	}while (betMoney + temp < minBet);
	betMoney += temp;
	money -= temp;
	set_min();
	return temp;
}


int PLAYER::check(){
	return minBet;
}


int PLAYER::fold(){
	return -1;
}
