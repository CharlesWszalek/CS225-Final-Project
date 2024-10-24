//
// CSS 225 FINAL PROJECT 
// Name: table.h
// Version 1.0 name: Bradon P 10/21/24 created
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
//

#include <iostream>

#include "table.hpp"
#include "game.hpp"
using namespace std;


void texas() {
	TABLE t();
	int numPlayers;
	int buyIn;
	cout << "How many players?: " << endl;
	cin >> numPlayers;
	cout << "What is the buy in?; " << endl;
	cin >> buyIn;
	GAME g(t);
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
	t.flop();
	//betting
	t.turn();
	//betting
	t.river();
	//betting
	t.showdown();
}


int main() {
	texas();
	return 0;
}
