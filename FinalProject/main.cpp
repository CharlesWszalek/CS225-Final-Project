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


void game() {
	int numPlayers;
	int buyIn;

	cout << "How many players?: " << endl;
	cin >> numPlayers;
	cin.ignore(INT_MAX, '\n');

	deck.shuffle();

	TABLE table(numPlayers);
	cout << "What is the buy in?; " << endl;
	cin >> buyIn;
	cin.ignore(INT_MAX, '\n');

	table.buy_in(buyIn);
	//assign players to table
	// t.players[0].playerId = 1 // dealer
	// t.players[1].playerId = 2 // small
	// t.players[2].playerId = 3 // big
	//betting
		// playerIndex = 0
		// while loop (not all players have raise = 1)
			// go through players indices
				// if player.raise == TRUE
					// leave the loop
				// else
			// playerIndex ++
	table.flop();
	table.betting();
	table.turn();
	table.betting();
	table.river();
	table.betting();
	table.display();
	table.showdown();
}


int main() {
	game();
	return 0;
}
