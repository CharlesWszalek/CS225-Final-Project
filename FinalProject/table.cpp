//
// CSS 225 FINAL PROJECT 
// Name: table.cpp
// Version 1.0 name: Bradon P 10/21/24 created
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
//

#include "player.hpp"
#include "table.hpp"
#include "cards.hpp"
//#include "cards.cpp"
//#include "player.cpp"
#include "hand.hpp"
//#include "hand.cpp"
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
	cout << "buy in" << endl;
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
}


void TABLE::river(){
	cout << "river" << endl;
	deck.discard();
	cards[4] = deck.draw();
}


void TABLE::showdown(){
	int mhands[numPlayers][5][14];
		for (int i = 0; i < numPlayers; i++){
    			for (int j = 0; j < 5; j++){
          			for (int k = 0; k < 14; k++){
					mhands[i][j][k] = 0;
				}
    			}
		}
	mhands[0][0][0] = 1;
	for (int i = 0; i < numPlayers; i++){
		for (int j = 0; j < 4; j++){
		        for (int k = 0; k < 13; k++){
        			mhands[i][j][13] += mhands[i][j][k];
			}
		}
	}
	for (int i = 0; i < numPlayers; i++){
		for (int j = 0; j < 13; j++){
			for (int k = 0; k < 4; k++){
        			mhands[i][4][j] += mhands[i][j][k];
			}
		}
	}
	//cout << mhands[0][0][13] << endl;
	cout << "showdown" << endl;
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

int main(){
	TABLE table(3);
	table.buy_in(100);
	table.showdown();
	return 0;
}