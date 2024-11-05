//
// CSS 225 FINAL PROJECT 
// Name: table.cpp
// Version 1.0 name: Bradon P 10/21/24 created
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
//

#include "global.hpp"
#include "player.hpp"
#include "table.hpp"
#include "cards.hpp"
#include "hand.hpp"
using namespace std;


TABLE::TABLE(int numOfPlayers):numPlayers(numOfPlayers), pot(0){
	for (int i = 0; i < numOfPlayers; i++){
		if (i == 0){
			players[i] = new HUMAN(i+1);
		} else {
			players[i] = new AI(i+1);
		}
	}
}


void TABLE::buy_in(int buyIn = 0){
	cout << "buy in: " << buyIn << endl;
        this -> buyIn = buyIn;
	bigBlind = buyIn * .1;
}


void TABLE::flop(){
	cout << "flop" << endl;
	deck.discard(); // try using the d-- operator overload
	for (int i = 0; i < 3; i++){
		cards[i] = deck.draw();
		cout << cards[i].get_name() << " of " << cards[i].get_suit() << endl;
	}
}


void TABLE::betting(){
	for (int i = 0; i < numPlayers; i++){
		pot += players[i]->bets();
	}
}


void TABLE::turn(){
	cout << "turn" << endl;
	deck.discard();
	cards[3] = deck.draw();
	cout << cards[3].get_name() << " of " << cards[3].get_suit() << endl;
}


void TABLE::river(){
	cout << "river" << endl;
	deck.discard();
	cards[4] = deck.draw();
	cout << cards[4].get_name() << " of " << cards[4].get_suit() << endl;
}


void TABLE::showdown(){
	const int num_suits = 4;
	const int num_names = 13;
	int mhands[numPlayers][num_suits+1][num_names+1];
		for (int i = 0; i < numPlayers; i++){
    			for (int j = 0; j < num_suits+1; j++){
          			for (int k = 0; k < num_names+1; k++){
					mhands[i][j][k] = 0;
				}
    			}
		}
	// ASSIGNING CARDS
	HAND hands[numPlayers];
	for (int i = 0; i < numPlayers; i++) {
		hands[i] = players[i]->get_hand();
		hands[i] = hands[i] + cards;
		for (int j = 0; j < 7; j++) {
			mhands[i][hands[i].cards[j].get_suit_2()][hands[i].cards[j].get_value()] += 1;
		}
	}
	// SUMMING
	for (int i = 0; i < numPlayers; i++) {
		for (int j = 0; j < num_suits; j++){
			for (int k = 0; k < num_names; k++){
				mhands[i][j][num_names] += mhands[i][j][k];
			}
		}
	}
	for (int i = 0; i < numPlayers; i++){
		for (int j = 0; j < num_suits; j++){
			for (int k = 0; k < num_names+1; k++){
        			mhands[i][num_suits][k] += mhands[i][j][k];
			}
		}
	}
	for (int i = 0; i < numPlayers; i++) {
		cout << endl;
		//hands[i].display_hand();
		//cout << endl;
		for (int j = 0; j < num_suits+1; j++){
			cout << endl;
			for (int k = 0; k < num_names+1; k++){
				cout << mhands[i][j][k] << " ";
			}
		}
	}
	//hands[0].display_hand();
	//hands[1].display_hand();
	//hands[2].display_hand();
	//cout << "showdown" << endl;
}


void TABLE::display() const {
	for (int i = 0; i < numPlayers; i++)
	{
		cout << "Player " << i << "'s " << "hand is: ";
		players[i]->get_hand().display_hand();
	}
	cout << "The table cards are: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cards[i].display();
	}
}


int TABLE::get_big_blind(){
	return bigBlind;
}

/*
int main(){
	deck.shuffle();
	TABLE table(3);
	table.buy_in(100);
	table.flop();
	table.turn();
	table.river();
	table.display();
	table.showdown();
	return 0;
}*/

//HELLLO
