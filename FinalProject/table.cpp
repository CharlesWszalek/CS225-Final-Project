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


int TABLE::bigBlind = 0;


int TABLE::playerTurn = 0;


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
        this -> buyIn = buyIn;
	bigBlind = buyIn * .1;
}


void TABLE::flop(){
	deck.discard(); // try using the d-- operator overload
	cout << endl;
	for (int i = 0; i < 3; i++){
		cards[i] = deck.draw();
		cards[i].display();
		cout << " ";
	}
	cout << endl;
}


void TABLE::betting(){
	for (int i = 0; i < numPlayers; i++){
		if (players[i]->get_hasRaised() == 1){
			players[i]->reset_raised();
		}
	}
	int countdown = numPlayers;
	while (countdown){
		cout << endl << "Player " << playerTurn+1 << endl;
		int temp = players[playerTurn]->get_hasRaised();
		if (temp == -1){//skip if they have folded
			cout << "Previously folded" << endl;
			countdown--;
			next_player();
			continue;
		}
		pot += players[playerTurn]->bets();
		if (temp - players[playerTurn]->get_hasRaised() == -1){//reset countdown when player has raised
			countdown = numPlayers-1;
			next_player();
			continue;
		}
		countdown--;
		next_player();//playerTurn = (playerTurn + 1) % numPlayers;
	}
}


void TABLE::next_player(){
	playerTurn = (playerTurn + 1) % numPlayers;
}


void TABLE::turn(){
	deck.discard();
	cards[3] = deck.draw();
	cout << endl;
	cards[3].display();
	cout << endl;
}


void TABLE::river(){
	deck.discard();
	cards[4] = deck.draw();
	cout << endl;
	cards[4].display();
	cout << endl;
}


void TABLE::blankofakind(int mhands[][5][14], int scoring[][10], int player, int num = 2){
	int count = 0;
	for (int j = 12; j >=0 ; j--) {
		if (count == 0) {
			if (mhands[player][4][j] == num) {
				count++;
				for (int k = 0; k < 5; k++) {
					mhands[player][k][j] = 0;
				}
				switch (num) {
					case 2: scoring[player][1] = j+1; break;
					case 3: scoring[player][3] = j+1; break;
					case 4: scoring[player][7] = j+1; break;
				}
			}
		}
	}
}

void TABLE::royal_flush(int mhands[][5][14], int scoring[][10]) {
	for (int i = 0; i < numPlayers; i++){
		if(mhands[i][4][9]==1 && mhands[i][4][10]==1 && mhands[i][4][11]==1
		&& mhands[i][4][12]==1 && mhands[i][4][0]==1) {
			for(int j = 0; j < 5; j++) {
				if(mhands[i][j][13] == 5)
					scoring[i][9] = 1;
			}
		}

	}
}

void TABLE::flush(int mhands[][5][14], int scoring[][10]) {
	int sum = 0;
	for (int i = 0; i < numPlayers; i++) {
		sum = 0;
		for (int j = 0; j < 5; j++) {
			if(mhands[i][j][13] == 5) {
				for (int k = 0; k < 13; k++) {
					if(mhands[i][j][k] == 1)
						sum+=(k+1);
					}
				scoring[i][5] = sum;
			}
		}
	}
}


void TABLE::straight(int mhands[][5][14], int scoring[][10]) {
	int sum = 0;
	int check = 0;
	for (int i = 0; i < numPlayers; i++) {
		check = 0;
		sum = 0;
		for (int j = 0; j < 10; j++){
			if (mhands[i][4][j] == 1) {
				for (int k = j; k <= j+4; k++) {
					check+=mhands[i][4][k];
					sum+=k;
				}
			}
			if (check == 5)
				scoring[i][4] = sum;
		}
	}
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
}


void TABLE::display() const {
	for (int i = 0; i < numPlayers; i++){
		cout << "Player " << i+1 << "'s " << "hand is: ";
		players[i]->get_hand().display_hand();
	}
	cout << "The table cards are: " << endl;
	for (int i = 0; i < 5; i++){
		cards[i].display();
		cout << " ";
	}
	cout << endl;
}
