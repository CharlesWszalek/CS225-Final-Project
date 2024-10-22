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


void PLAYER::setmin(){
	if (bet > minBet){
		minBet = bet;
	}
}


void PLAYER::raise(){

}


void PLAYER::check(){

}


void PLAYER::fold(){

}
