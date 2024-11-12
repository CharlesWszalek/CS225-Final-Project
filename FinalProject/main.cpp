//
// CSS 225 FINAL PROJECT 
// Name: table.h
// Version 1.0 name: Bradon P 10/21/24 created
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
//

#include <iostream>
#include <climits>
#include "table.hpp"

using namespace std;

// creates a game for the player
void game() {
	int numPlayers; // number of players playing: 1 + number of ai
	int buyIn; // the buy in for that game

	cout << "How many players? " << endl; // read in number of players
	cin >> numPlayers;
	cin.ignore(INT_MAX, '\n');

	cout << "What is the buy in? " << endl; // read in the buy in
	cin >> buyIn;
	cin.ignore(INT_MAX, '\n');

	TABLE table(numPlayers, buyIn); // create a table for the game to be played on

	table.betting(); //
	table.flop();    //
	table.betting(); //
	table.turn();    // have the players play their turns and add cards to the table
	table.betting(); //
	table.river();   //
	table.betting(); //

	table.display(); // show the cards on the table and in everyones hands

	table.showdown(); // compare the cards of each of the players and determine a winner
}

// main loop to create games
int main(){
	string input; // take input yes or no
	cout << "Shall we play a game? " << endl;
	cin >> input;
	while (input == "Yes" || input == "yes")
	{
		game();
		cout << "Shall we play again? " << endl;
		cin >> input;
	}
	return 0;
}
