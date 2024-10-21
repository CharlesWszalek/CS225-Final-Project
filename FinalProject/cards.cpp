//
// CSS 225 FINAL PROJECT 
// Name: cards.cpp
// Version 1.0 name: Bradon P 10/18/24 defined functions for the DECK and TABLE classes
// 	   1.1 name: Bradon P 10/21/24 moved shuffle into shuffle function, added drawing cards
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
// 	      https://en.cppreference.com/w/cpp/algorithm/random_shuffle
// 	      https://www.geeksforgeeks.org/cpp-vector-of-structs/
// 	      https://www.geeksforgeeks.org/vector-in-cpp-stl/
//

#include "cards.h"
#include <algorithm>
#include <random>


DECK::DECK(){
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


std::ostream& operator<< (std::ostream& c, DECK d){
	for (auto i = d.cards.begin(); i != d.cards.end(); ++i){
		c << i->suit << " " << i->name << " " << i->value << std::endl;
	}
	return c;
}
void TABLE::flop(){
/*	DECK::cards.pop_back();
	DECK::cards.pop_back();
	for (int i = 0; i < 3; i++){
		TABLE::cards[i] = draw();
		std::cout << TABLE::cards[i].suit << " " << TABLE::cards[i].name << " " << TABLE::cards[i].value << std::endl;
	}*/
}


void TABLE::turnRiver(){

}


void TABLE::showdown(){

}


int main() {
	DECK here;
	std::cout << here;
	std::cout << "your card is: ";
	CARDS c = here.draw();
	std::cout << c.suit << " " << c.name << " " << c.value << std::endl;
	std::cout<< std::endl;
	std::cout << here;
	std::cout<< std::endl;

/*	TABLE t;
	t.flop();
	std::cout<< std::endl;
	std::cout << here;
*/
	return 0;
}
