//
// CSS 225 FINAL PROJECT 
// Name: table.cpp
// Version 1.0 name: Brandon P 10/21/24 created
//	   1.1 name: Thomas Z  10/23/24 created new fucntions 
//	   1.2 name: Charles W 10/27/24 created showdown function
//	   1.3 name: Charles W 10/30/24 added hand checkers for showdown
//	   1.4 name: Charles W 11/02/24 added hand checkers for showdown
//	   1.5 name: Thomas Z  11/03/24 added hand checkers for showdown
//	   1.6 name: Charles W 11/07/24 added hand checkers for showdown
//	   1.6 name: Thomas Z  11/10/24 fixed hand checkers for showdown
//	   1.7 name: Thomas Z  11/11/24 fixed hand checkers for showdown
//	   1.8 name: Charles W 11/12/24 fixed hand checkers for showdown
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
//

#include "global.hpp"
#include "player.hpp"
#include "table.hpp"
#include "cards.hpp"
#include "hand.hpp"
#include <stdexcept>
#include <fstream>
using namespace std;

// sets the default big blind
int TABLE::bigBlind = 0;

// keeps track of which player's turn it is based on their index 
int TABLE::playerTurn = 0;

// table constructor
TABLE::TABLE(int numOfPlayers, int buyIn): numPlayers(numOfPlayers), pot(0){
	playerTurn = 0;
	deck.shuffle();
	buy_in(buyIn);
	for (int i = 0; i < numOfPlayers; i++){
		if (i == 0){
			players[i] = new HUMAN(i, buyIn, deck);
		} else {
			players[i] = new AI(i, buyIn, deck);
		}
	}
}

// deconstructor 
TABLE::~TABLE(){
	for (int i = 0; i < numPlayers; i++){
		delete players[i];
	}
	for (int i = 0; i < 52 ; i++){
		try{
			deck.discard();
		}
		catch (const runtime_error& error){
			break;
		}
	}
}

// set buy in and big blind based on user input
void TABLE::buy_in(int buyIn = 0){
        this -> buyIn = buyIn;
	bigBlind = buyIn * .1;
}

// first 3 cards for the table
void TABLE::flop(){
	deck.discard(); // try using the d-- operator overload
	cout << endl;
	int foldedPlayers = 0;
	for (int i = 0; i < numPlayers; i++){
		foldedPlayers += players[i]->get_hasRaised();
	}
	for (int i = 0; i < 3; i++){
		cards[i] = deck.draw();
		if (foldedPlayers != -numPlayers+1){
			cards[i].display();
			cout << " ";
		}
	}
	cout << endl;
}

// allows for money to be bet at the table 
void TABLE::betting(){
	int playersFolded = 0;
	for (int i = 0; i < numPlayers; i++){
		if (players[i]->get_hasRaised() == 1){
			players[i]->reset_raised();
		} else if (players[i]->get_hasRaised() == -1){
			playersFolded++;
		}
	}
	int countdown = numPlayers;
	while (countdown && playersFolded < numPlayers-1){
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
		} else if (temp != -1 && players[playerTurn]->get_hasRaised() == -1){
			playersFolded++;
			//cout << "check: folded" << endl;
		}
		countdown--;
		next_player();//playerTurn = (playerTurn + 1) % numPlayers;
	}
}

// increments the turn counter
void TABLE::next_player(){
	playerTurn = (playerTurn + 1) % numPlayers;
}

// adding annother card to the table 
void TABLE::turn(){
	deck.discard();
	cards[3] = deck.draw();
	cout << endl;
	int foldedPlayers = 0;
	for (int i = 0; i < numPlayers; i++){
		foldedPlayers += players[i]->get_hasRaised();
	}
	if (foldedPlayers != -numPlayers+1){
		for (int i = 0; i < 4; i++){
			cards[i].display();
			cout << " ";
		}
	}
	cout << endl;
}

// adding annother card to the table 
void TABLE::river(){
	deck.discard();
	cards[4] = deck.draw();
	cout << endl;
	int foldedPlayers = 0;
	for (int i = 0; i < numPlayers; i++){
		foldedPlayers += players[i]->get_hasRaised();
	}
	if (foldedPlayers != -numPlayers+1){
		for (int i = 0; i < 5; i++){
			cards[i].display();
			cout << " ";
		}
	}
	cout << endl;
}

// checks whether the player has any number of a particular suit up to 4
void TABLE::blank_of_a_kind(int mhands[][5][14], int scoring[][10], int player, int num = 2){
	int count = 0;
	for (int j = 12; j >=0 ; j--){
		if (count == 0){
			if (mhands[player][4][j] == num){
				count++;
				for (int k = 0; k < 5; k++){
					mhands[player][k][j] = 0;
				}
				switch (num){
					case 2: 
						scoring[player][1] = j+1; 
						break;
					case 3: 
						scoring[player][3] = j+1; 
						break;
					case 4: 
						scoring[player][7] = j+1; 
						break;
				}
			}
		}
	}
}

// checks to see if a player has 2 pair 
void TABLE::two_pair(int mhands[][5][14], int scoring[][10], int player){
	int count = 0;
	int num = 2;
	int cardValue = 0;
	int column = 0;
	int mhands2[numPlayers][5][14];
	for (int i = 0; i < numPlayers; i++){				//
		for (int j = 0; j < 5; j++){				// copying mhands
			for (int k = 0; k < 14; k++){			//
				mhands2[i][j][k] = mhands[i][j][k];	//
			}
		}
	}
	for (int j = 12; j >=0 ; j--){
		if (count == 0){
			if (mhands2[player][4][j] == num){
				count++;
				for (int k = 0; k < 5; k++){
					mhands2[player][k][j] = 0;	// deleting first pair from copy
				}
				cardValue = j+1;
				column = j;
			}
		}
		if (count == 1){
			if (mhands2[player][4][j] == num){
				count++;
				for (int k = 0; k < 5; k++){
					mhands[player][k][j] = 0;	// deleting second pair
					mhands[player][k][column] = 0;	// deleting first pair
				}
				scoring[player][2] = cardValue;
			}
		}
	}
}

// checks to see if a player has a roay flush 
void TABLE::royal_flush(int mhands[][5][14], int scoring[][10]){
	for (int i = 0; i < numPlayers; i++){
		if(mhands[i][4][9]==1 && mhands[i][4][10]==1 && mhands[i][4][11]==1
		&& mhands[i][4][12]==1 && mhands[i][4][0]==1){
			for(int j = 0; j < 5; j++){
				if(mhands[i][j][13] == 5)
					scoring[i][9] = 1;
			}
		}
	}
}

// checks to see if a player has a flush that is not royal 
void TABLE::flush(int mhands[][5][14], int scoring[][10]){
	int check = 0;
	int sum = 0;
	for (int i = 0; i < numPlayers; i++){
		check = 0;
		sum = 0;
		for (int j = 0; j < 4; j++){
			if(mhands[i][j][13] >= 5){
				for (int k = 12; k >=0 ; k--){
					if(mhands[i][j][k] == 1 && check <= 4){
						check++;
						sum+=(k+1);
					}
				}
				scoring[i][5] = sum;
			}
		}
	}
}

// checks to see if a player has a straight 
void TABLE::straight(int mhands[][5][14], int scoring[][10]){
	int sum = 0;
	int check = 0;
	for (int i = 0; i < numPlayers; i++){
		for (int j = 0; j < 10; j++){
			check = 0;
			sum = 0;
			if (mhands[i][4][j] >= 1){
				for (int k = j; k <= j+4; k++){
					if(mhands[i][4][k % 13] >= 1){
						check++;
						sum+=k;
					} else {
						break;
					}
				}
			}
			if (check == 5){
				scoring[i][4] = sum;
			}
		}
	}
}

// checks for the highest card left in the hand 
void TABLE::highcard(int mhands[][5][14], int scoring[][10]){
	int score = 0;
	for (int i = 0; i < numPlayers; i++){
		score = 0;
		for (int j = 12; j >=0; j--){
			for (int k = 3; k>=0; k--){
				if (mhands[i][j][k] == 1 && score == 0){
					score = j+1;
				}
			}
		}
		scoring[i][0] = score;
	}
}

// checks a players hand for a straight flush that is not royal 
void TABLE::straight_flush(int mhands[][5][14], int scoring[][10]){
    int check = 0;
    int max = 0;
    for (int i = 0; i < numPlayers; i++){
        for (int j = 0; j < 4; j++){
            if (mhands[i][j][13] >= 5){
                for (int k = 0; k <= 9; k++){ // Loop up to 9 to prevent out-of-bounds
                    max = 0;
                    check = 0;
                    for (int z = k; z < k + 5; z++){
                        if (mhands[i][j][z] == 1){
                            max = z+1;
                            check++;
                        } else {
                            break;
                        }
                    }
                    if (check == 5){
                        break; // Exit loop if a straight flush is found
                    }
                }
            }
        }
        scoring[i][8] = max; // Assign the highest value if found
    }
}

// checks to see if a player has a full house 
void TABLE::full_house(int mhands[][5][14], int scoring[][10]){
	int step = 0;
	int max = 0;
	for (int i = 0; i < numPlayers; i++){
		step = 0;
		max = 0;
		for (int j = 0; j < 13; j++){
			if (mhands[i][4][j] >= 3){
				step = 1;
				max = j+1;
				break;
			}
		}
		if (step == 1){
			for (int k = 0; k < 13; k++){
				if (mhands[i][4][k] == 2){
					scoring[i][6] = max;
					break;
				}
			}
		}
	}
}

// calls all of the checking
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
	for (int i = 0; i < numPlayers; i++){
		hands[i] = players[i]->get_hand();
		hands[i] = hands[i] + cards;
		for (int j = 0; j < 7; j++){
			mhands[i][hands[i].cards[j].get_suit_2()][hands[i].cards[j].get_value()] += 1;
		}
	}
	// SUMMING
	for (int i = 0; i < numPlayers; i++){
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
	// checking each hand
	royal_flush(mhands, scoring);
	straight_flush(mhands, scoring);
	for (int i = 0; i < numPlayers; i++){
		blank_of_a_kind(mhands, scoring, i, 4);
	}
	full_house(mhands, scoring);
	flush(mhands, scoring);
	straight(mhands, scoring);
	for (int i = 0; i < numPlayers; i++){
		blank_of_a_kind(mhands, scoring, i, 3);
	}
	for (int i = 0; i < numPlayers; i++){
		two_pair(mhands, scoring, i);
	}
	for (int i = 0; i < numPlayers; i++){
		blank_of_a_kind(mhands, scoring, i, 2);
	}
	highcard(mhands, scoring);
	//Doing Print statements for all of the hands:
	for (int i = 0; i< numPlayers; i++){
		int scored = 0;
		for (int j = 9; j >=0; j--){
			if (scoring[i][j] > 0 && scored == 0){
				scored = 1;
				switch (j){
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
	
	for (int j = 9; j >=0 ; j--){
		for (int i = 0; i < numPlayers; ++i){
			if (scoring[i][j] > 0){
				for(int k = i; k < numPlayers; k++){
					if (scoring[k][j] > win && players[k]->get_hasRaised() != -1){
						win = scoring[k][j];
						player_winner = k;
					}
				}
			}
		}
	}
	cout << endl << "The winner is: " << players[player_winner]->get_name() << endl;
	//File IO stuff
    	ofstream myfile;
    	myfile.open("GameHistory.txt", ios::app);  // Open in append mode
    	myfile << "The winner of the game is: " << players[player_winner]->get_name() << endl;
    	myfile << "They won " << pot << " dollars!" << endl;
    	myfile.close();
}


void TABLE::display() const {
	cout << endl;
	for (int i = 0; i < numPlayers; i++){
		cout << players[i]->get_name() << "'s " << "hand is: ";
		players[i]->get_hand().display_hand();
	}
	cout << endl << "The table cards are: " << endl;
	for (int i = 0; i < 5; i++){
		cards[i].display();
		cout << " ";
	}
	cout << endl << endl;
}
