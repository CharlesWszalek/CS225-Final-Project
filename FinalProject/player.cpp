//
// CSS 225 FINAL PROJECT 
// Name: player.cpp
// Version 1.0 name: Brandon P 10/21/24 created
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand 
//

#include "player.h"


int PLAYER::minBet = 0;


PLAYER::PLAYER(int num): bet(0), playerNum(num), money(1500){}


int PLAYER::bets(){
	std::string temp;
	std::cout << "Would you like to raise, check, or fold: ";
	std::cin >> temp;
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


void PLAYER::setmin(){
	if (bet > minBet){
		minBet = bet;
	}
}


int PLAYER::raise(){
	int temp = 0;
	do {
		std::cout << "player " << playerNum << ", What would you like to bet: ";
		std::cin >> temp;
		
		std::cout << bet+temp << " " << minBet << std::endl;
	}while (bet + temp < minBet);
	bet += temp;
	money -= temp;
	setmin();
	return temp;
}


int PLAYER::check(){
	return 0;
}


int PLAYER::fold(){
	return 0;
}
