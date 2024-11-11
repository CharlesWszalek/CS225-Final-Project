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


TABLE::TABLE(int numOfPlayers, int buyIn):numPlayers(numOfPlayers), pot(0){
	buy_in(buyIn);
	for (int i = 0; i < numOfPlayers; i++){
		if (i == 0){
			players[i] = new HUMAN(i, buyIn);
		} else {
			players[i] = new AI(i, buyIn);
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
		cout << endl << players[playerTurn]->get_name() << endl;
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
	for (int i = 0; i < 4; i++){
		cards[i].display();
		cout << " ";
	}
	cout << endl;
}


void TABLE::river(){
	deck.discard();
	cards[4] = deck.draw();
	cout << endl;
	for (int i = 0; i < 5; i++){
		cards[i].display();
		cout << " ";
	}
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

void TABLE::two_pair(int mhands[][5][14], int scoring[][10], int player){
	int count = 0;
	int num = 2;
	int mhands2[numPlayers][5][14];
	for (int i = 0; i < numPlayers; i++) {       // copying mhands
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 14; k++) {
				mhands2[i][j][k] = mhands[i][j][k];
			}
		}
	}
	for (int j = 12; j >=0 ; j--) {
		if (count = 1) {
			if (mhands[player][4][j] == num) {
				count++;
				for (int k = 0; k < 5; k++) {
					mhands2[player][k][j] = 0;
				}
				scoring[player][2] = j+1;
			}
		}if (count = 0) {

		}else
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
	int check = 0;
	int sum = 0;
	for (int i = 0; i < numPlayers; i++) {
		check = 0;
		sum = 0;
		for (int j = 0; j < 4; j++) {
			if(mhands[i][j][13] >= 5) {
				for (int k = 12; k >=0 ; k--) {
					if(mhands[i][j][k] == 1 && check <= 4) {
						check++;
						sum+=(k+1);
					}
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
		for (int j = 0; j < 10; j++){
			check = 0;
			sum = 0;
			if (mhands[i][4][j] >= 1) {
				for (int k = j; k <= j+4; k++) {
					if(mhands[i][4][k % 13] >= 1) {
						check++;
						sum+=k;
					}
					else
						break;
				}
			}
			if (check == 5)
				scoring[i][4] = sum;
		}
	}
}


void TABLE::highcard(int mhands[][5][14], int scoring[][10]) {
	int score = 0;
	for (int i = 0; i < numPlayers; i++) {
		score = 0;
		for (int j = 12; j >=0; j--) {
			for (int k = 3; k>=0; k--) {
				if (mhands[i][j][k] == 1 && score == 0) {
					score = j+1;
				}
			}
		}
		scoring[i][0] = score;
	}
}

void TABLE::straight_flush() {

}

void TABLE::full_house() {

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
	int scoring[numPlayers][10]; // There are 10 different hands
	for (int i = 0; i < numPlayers; i++){
		for (int j = 0; j < 10; j++){
			scoring[i][j] = 0;
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
	/*
	mhands[4][2][3] = 1;
	mhands[4][2][4] = 1;
	mhands[4][2][5] = 1;
	mhands[4][2][6] = 1;
	mhands[4][2][8] = 1;
	*/
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
	cout << endl;
	royal_flush(mhands, scoring);
	straight_flush();		// STRAIGHT FLUSH	needs work
	for (int i = 0; i < numPlayers; i++) {
		blankofakind(mhands, scoring, i, 4);
	}
	full_house();			// FULL HOUSE		needs work
	flush(mhands, scoring);
	straight(mhands, scoring);
	for (int i = 0; i < numPlayers; i++) {
		blankofakind(mhands, scoring, i, 3);
	}
	for (int i = 0; i < numPlayers; i++) {
		two_pair(mhands, scoring, i);
	}
	for (int i = 0; i < numPlayers; i++) {
		blankofakind(mhands, scoring, i, 2);
	}
	highcard(mhands, scoring);
	for (int i = 0; i < numPlayers; i++) {
		cout << endl;
		//hands[i].display_hand();
		//cout << endl;
		for (int j = 0; j < 10; j++){
			cout << scoring[i][j] << " ";
		}
	}

	//Doing Print statements for all of the hands:
	for (int i = 0; i< numPlayers; i++) {
		int scored = 0;
		for (int j = 9; j >=0; j--) {
			if (scoring[i][j] > 0 && scored == 0) {
				scored = 1;
				switch (j) {
					case 9:
						cout << players[i]->get_name() << "'s hand is a royal flush, they win the game!" << endl;
						break;
					case 8:
						cout << players[i]->get_name() << "'s hand is a straight flush." << endl;
						break;
					case 7:
						cout << players[i]->get_name() << "'s hand is a four of a kind." << endl;
						break;
					case 6:
						cout << players[i]->get_name() << "'s hand is a full house." << endl;
						break;
					case 5:
						cout << players[i]->get_name() << "'s hand is a flush." << endl;
						break;
					case 4:
						cout << players[i]->get_name() << "'s hand is a straight." << endl;
						break;
					case 3:
						cout << players[i]->get_name() << "'s hand is a three of a kind." << endl;
						break;
					case 2:
						cout << players[i]->get_name() << "'s hand is a two pair." << endl;
						break;
					case 1:
						cout << players[i]->get_name() << "'s hand is a pair." << endl;
						break;
					case 0:
						cout << players[i]->get_name() << "'s hand is highcard." << endl;
						break;
				}
			}
		}
	}
	//Finding the winner:
	int player_winner;
	int win = 0;
	
	for (int j = 9; j >=0 ; j--) {
		for (int i = 0; i < numPlayers; ++i) {
			if (scoring[i][j] > 0) {
				for(int k = i; k < numPlayers; k++) {
					if (scoring[k][j] > win) {
						win = scoring[k][j];
						player_winner = k;
					}
				}
			}
		}
	}
	cout << "The winner is: " << players[player_winner]->get_name() << endl;
}


void TABLE::display() const {
	for (int i = 0; i < numPlayers; i++){
		cout << players[i]->get_name() << "'s " << "hand is: ";
		players[i]->get_hand().display_hand();
	}
	cout << "The table cards are: " << endl;
	for (int i = 0; i < 5; i++){
		cards[i].display();
		cout << " ";
	}
	cout << endl;
}
