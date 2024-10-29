//
// CSS 225 FINAL PROJECT 
// Name: human.cpp
// Version 1.0 name: Brandon P 10/21/24 created
// 	   1.1 name: Brandon P 10/26/24 added error checking
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
// 	      https://www.geeksforgeeks.org/convert-string-to-int-in-cpp/ 
//

#include "player.hpp"
#include <iostream>
#include <climits>
using namespace std;

//int HUMAN::minBet = 0;


HUMAN::HUMAN(int num, int buyIn):PLAYER(num, buyIn){name = "tempname";}


int HUMAN::bets(){
	if(hasRaised != -1){
		string temp = "0";
		while (!((hasRaised == 0 && temp == "raise") || temp == check_or_call() || temp == "fold")) {
			if (hasRaised == 0 && minBet - betMoney + 5/*get_big_blind*/ < money) {
				cout << "Would you like to raise, " << check_or_call() << ", or fold: "; //cannot raise if raised already
			} else if (hasRaised == 1 || minBet - betMoney + 5/*get_big_blind*/ < money) {
				cout << "Would you like to call or fold: "; //cannot raise if raised already
			}
			getline(cin, temp);//cin >> temp;
			if (!cin) { //that was not an int, cin is in error
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
		if (temp == "raise" && hasRaised == 0 && minBet - betMoney + 5/*get_big_blind*/ < money){
			raise();
		} else if (temp == check_or_call()){
			check();
		} else if (temp == "fold"){
			fold();
		} /*else {
			cout << "something went wrong" << endl;
		}*/
		set_min();
		return 1;
	} else {
		cout << "player has previously folded" << endl;
		return 0; //comunicate player has folded
	}
}


string HUMAN::check_or_call(){
	if (minBet == 0){
		return "check";
	} else {
		return "call";
	}
}


int HUMAN::conv_string_int(string input){
	int num = 0;
	for (char c : input){
		if (c >= '0' && c <= '9' && c != '\n') {
			num = num * 10 + (c - '0');
		} else {
			cout << "Input must be an integer" << endl;
			return 0;
		}
	}
	return num;
}


void HUMAN::raise(){
	int betChange = 0;
	do {
		cout << name << ", how much would you like to bet over the current bet of $" << minBet << ": ";
		string input;
		getline(cin, input);//cin >> betChange;
		if ((betChange = conv_string_int(input)) < 5/*get_big_blind()*/){
			cout << "Bet must be larger than Big Blind: $" << 5 /*get_bit_blind()*/ << endl;
			continue;
		} else if (!cin) { //that was not an int, cin is in error
			cout << "Invalid input" << endl;;
			cin.clear(); //clear error flag
			cin.ignore(INT_MAX, '\n');
		} else if (money < betChange + minBet - betMoney){
			cout << "total bet must be less than or equal to your total money: $" << minBet << " + $" << betChange << " - $" << betMoney << " > $" << money << endl;
			betChange = 0;
		}
	} while (betChange < 5 /*get_big_blind()*/);
	hasRaised = 1;
	money -= betChange + minBet - betMoney;
	betMoney = minBet + betChange;
}
