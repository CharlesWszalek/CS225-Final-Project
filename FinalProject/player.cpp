//
// CSS 225 FINAL PROJECT 
// Name: player.cpp
// Version 1.0 editor1 name: 10/21/24 created
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand 
//

#include "player.h"


int PLAYER::minBet = 0;


PLAYER::PLAYER(int num): bet(0), playerNum(num){}


void PLAYER::bets(){
	int temp;
	std::cout << "player " << playerNum << ", What would you like to bet: ";
	std::cin >> temp;
	bet += temp;
	setmin();
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
