//
// CSS 225 FINAL PROJECT 
// Name: human.cpp
// Version 1.0 name: Brandon P 10/21/24 created
// 	   1.1 name: Brandon P 10/26/24 added error checking
// 	   1.2 name: Brandon P 10/29/24 fixed error where last 5 dollars couldn't be bet
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
// 	      https://www.geeksforgeeks.org/convert-string-to-int-in-cpp/ 
//

#include "player.hpp"
#include "table.hpp"
#include <iostream>
#include <climits>
using namespace std;

// Constructor
HUMAN::HUMAN(int num, int buyIn, DECK d):PLAYER(num, buyIn, d){cout << "What do you want to be called? " << endl; getline(cin, name);}

// controls how the player is allowed to bet and how much they are allowed to bet
int HUMAN::bets(){
	if(hasRaised != -1){
		string temp = "0";
		hand.display_hand(); // show the player their hand
		while (!((hasRaised == 0 && temp == "raise") || temp == check_or_call() || temp == "fold")) {
			if (hasRaised == 0 && minBet - betMoney + TABLE::bigBlind <= money) {
				cout << "Would you like to raise, " << check_or_call() << ", or fold: "; //cannot raise if raised already
			} else {
				cout << "Would you like to "<< check_or_call() <<" or fold: "; //cannot raise if raised already
			}
			getline(cin, temp); // prompt the user for the behavior
			if (!cin) { // error handling for ints inputed
				cout << "Invalid input" << endl;;
				cin.clear(); //clear error flag
				cin.ignore(INT_MAX, '\n');
			} else if (!(temp == "raise" || temp == check_or_call() || temp == "fold")){
				cout << "Input must be raise, " << check_or_call() << ", or fold" << endl;
			}
			if (hasRaised == 1 && temp == "raise"){
				cout << "Cannot raise again after raising" << endl;
			}
		}

		int forPot; // the amount of money that will be added to the pot from they player's hand
		if (temp == "raise" && hasRaised == 0 && minBet - betMoney + TABLE::bigBlind <= money){
			forPot = raise();
		} else if (temp == check_or_call()){
			forPot = check();
		} else if (temp == "fold"){
			fold();
			return -1;
		} else {
                  forPot = 0;
                }
		set_min();
		return forPot;
	} else { // makes sure they player can't play if they folded
		cout << "player has previously folded" << endl;
		return -1; //comunicate player has folded
	}
}

// allows the player to raise and controls the amount by which they are allowed to do so
int HUMAN::raise(){
	int betChange = 0;
	do {
		cout << name << ", how much would you like to bet over the current bet of $" << minBet << ": ";
		string input;
		getline(cin, input); // ask the user for raise value
		if ((betChange = conv_string_int(input)) < TABLE::bigBlind){ // error handling
			cout << "Bet must be larger than Big Blind: $" << TABLE::bigBlind << endl;
			continue;
		} else if (!cin) { // int error handling
			cout << "Invalid input" << endl;;
			cin.clear(); //clear error flag
			cin.ignore(INT_MAX, '\n');
		} else if (money < betChange + minBet - betMoney){
			cout << "total bet must be less than or equal to your total money: $" << minBet << " + $" << betChange << " - $" << betMoney << " => $" << money << endl;
			betChange = 0;
		}
	} while (betChange < TABLE::bigBlind);
	hasRaised = 1;
	int moneyForPot = betChange + minBet - betMoney;
	money -= moneyForPot;
	betMoney = minBet + betChange;
	return moneyForPot;
}
