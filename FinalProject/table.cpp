//
// CSS 225 FINAL PROJECT 
// Name: table.cpp
// Version 1.0 name: Bradon P 10/21/24 created
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
//

#include "table.h"


TABLE::TABLE():pot(0){
	for (int i = 0; i < 4; i++){
		player[i] = new PLAYER(i+1);
	}
}


void TABLE::buyIn(){
	std::cout << "buy in" << std::endl;
}


void TABLE::flop(){
	std::cout << "flop" << std::endl;
	deck.discard(); // try using the d-- operator overload
	deck.discard();
	for (int i = 0; i < 3; i++){
		cards[i] = deck.draw();
//		std::cout << cards[i].suit << " " << cards[i].name << " " << cards[i].value << std::endl;
	}
}


void TABLE::betting(){
	for (int i = 0; i < 4; i++){
		pot += player[i]->bets();
	}
}


void TABLE::turn(){
	std::cout << "turn" << std::endl;
	deck.discard();
	cards[3] = deck.draw();
}


void TABLE::river(){
	std::cout << "river" << std::endl;
	deck.discard();
	cards[4] = deck.draw();
}


void TABLE::showdown(){
	std::cout << "Showdown" << std::endl;
}


void TABLE::display(){
	
}
