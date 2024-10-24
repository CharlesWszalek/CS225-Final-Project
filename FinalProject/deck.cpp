//
// CSS 225 FINAL PROJECT
// Name: cards.cpp
// Version 1.0 name: Brandon P 10/18/24 defined functions for the DECK and TABLE classes
// 	   1.1 name: Brandon P 10/21/24 moved shuffle into shuffle function, added drawing cards
// 	   1.2 name: Brandon P 10/21/24 moved table to seperate file
//	   1.3 name: Thomas Z 10/22/24 writing function body for Cards Class
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
// 	      https://en.cppreference.com/w/cpp/algorithm/random_shuffle
// 	      https://www.geeksforgeeks.org/cpp-vector-of-structs/
// 	      https://www.geeksforgeeks.org/vector-in-cpp-stl/
//

#include "cards.h"
#include <algorithm>
#include <random>
#include <time.h>
using namespace std;

srand(time(NULL));
DECK();
CARDS draw();
DECK shuffle();
void burn();











/*DECK::DECK(){
	for (int i = 0; i < 13; ++i){
		for (int j = 0; j < 4; ++j){
			CARDS temp;
			switch (j % 4){
				case 0:
					temp.suit = "Clubs";
					break;
				case 1:
					temp.suit = "Spades";
					break;
				case 2:
					temp.suit = "Hearts";
					break;
				case 3:
					temp.suit = "Diamonds";
					break;
			}
			switch (i % 13){
				case 0:
					temp.name = "Ace";
					temp.value = 14;
					break;
				case 1:
					temp.name = "Two";
					temp.value = i+1;
					break;
				case 2:
					temp.name = "Three";
					temp.value = i+1;
					break;
				case 3:
					temp.name = "Four";
					temp.value = i+1;
					break;
				case 4:
					temp.name = "Five";
					temp.value = i+1;
					break;
				case 5:
					temp.name = "Six";
					temp.value = i+1;
					break;
				case 6:
					temp.name = "Seven";
					temp.value = i+1;
					break;
				case 7:
					temp.name = "Eight";
					temp.value = i+1;
					break;
				case 8:
					temp.name = "Nine";
					temp.value = i+1;
					break;
				case 9:
					temp.name = "Ten";
					temp.value = i+1;
					break;
				case 10:
					temp.name = "Jack";
					temp.value = i+1;
					break;
				case 11:
					temp.name = "Queen";
					temp.value = i+1;
					break;
				case 12:
					temp.name = "King";
					temp.value = i+1;
					break;
			}
			cards.push_back(temp);
		}
	}
	shuffle();
}


CARDS DECK::draw(){
	CARDS temp = cards.back();
	cards.pop_back();
	return temp;
}


void DECK::shuffle(){
	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(cards.begin(), cards.end(), g);
}


void DECK::discard() {
	cards.pop_back();
}


std::ostream& operator<< (std::ostream& c, DECK d){
	for (auto i = d.cards.begin(); i != d.cards.end(); ++i){
		c << i->suit << " " << i->name << " " << i->value << std::endl;
	}
	return c;
}
*/
