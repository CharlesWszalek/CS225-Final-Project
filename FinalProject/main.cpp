//
// CSS 225 FINAL PROJECT 
// Name: table.h
// Version 1.0 name: Brandon P 10/21/24 created
// 	   1.1 name: Brandon P 10/23/24 game function added
// 	   1.2 name: Brandon P 11/05/24 loop added in main
// 	   1.3 name: Thomas Z  11/10/24 user input fixed in main
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
//

#include <iostream>
#include <climits>
#include "table.hpp"

using namespace std;

// creates a game for the player
void game(){
	int numPlayers; // number of players
	int buyIn; // buy in amount

	cout << "How many players (Max of 5, Min of 2)? " << endl;
	cin >> numPlayers;  // user input 
	while (!cin || numPlayers > 5 || numPlayers <2){ // error checking
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Error, non integer value entered, try again: " << endl;
		cin >> numPlayers;
	}
	cin.ignore(INT_MAX, '\n');

	cout << "What is the buy in? " << endl;
	cin >> buyIn; // user input 
	while (cin.fail () ){ // error checking
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Error, non integer value entered, try again: " << endl;
		cin >> buyIn;
	}
	cin.ignore(INT_MAX, '\n');

	TABLE table(numPlayers, buyIn); // create a table for the game

	table.betting(); //
	table.flop();    //
	table.betting(); //
	table.turn();    // cards being distributed to players
	table.betting(); //
	table.river();   //
	table.betting(); //
	
	table.display(); // show all players cards and the table cards
	
	table.showdown(); // determine the winner
}

// main loop to create games
int main(){
	string input;
	cout << "Shall we play a game? " << endl;
	cin >> input; //user input 
	cin.ignore(INT_MAX, '\n');
	if (input == "No" || input == "no") // error checking
		return 0;
	while (input != "Yes" && input != "yes"){
		cout << "Invalid Input, try again: ";
		cin >> input;
		cin.ignore(INT_MAX, '\n');
		if (input == "No" || input == "no")
			return 0;
	}
	while (input == "Yes" || input == "yes"){
		game(); // play the game if input is "yes"
		cout << "Shall we play again? " << endl;
		cin >> input;
		cin.ignore(INT_MAX, '\n');
	}
	return 0;
}
