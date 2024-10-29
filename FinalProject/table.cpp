//
// CSS 225 FINAL PROJECT 
// Name: table.cpp
// Version 1.0 name: Bradon P 10/21/24 created
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
//

#include "table.hpp"
#include "cards.hpp"

using namespace std;


TABLE::TABLE():pot(0){
	for (int i = 0; i < 4; i++){
		players[i] = new PLAYER(i+1);
	}
}


void TABLE::buy_in(int buyIn = 0){
	cout << "buy in" << endl;
        this -> buyIn = buyIn;
}


void TABLE::flop(){
	cout << "flop" << endl;
	deck.discard(); // try using the d-- operator overload
	for (int i = 0; i < 3; i++){
		cards[i] = deck.draw();
//		std::cout << cards[i].suit << " " << cards[i].name << " " << std::endl;
	}
}


void TABLE::betting(){
	for (int i = 0; i < 4; i++){
		pot += players[i]->bets();
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
        CARD hands[5][7];
        for (int i = 0; i < sizeof(players); i++){
        	hand0;
        }
}


void TABLE::display(){
	
}

int TABLE::get_big_blind(){
	return bigBlind;
}
