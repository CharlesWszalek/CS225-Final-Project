// CSS 225 FINAL PROJECT
// Name: cards.cpp
// Version 1.0 name: Brandon P 10/18/24 defined functions for the DECK and TABLE classes
// 	   1.1 name: Brandon P 10/21/24 moved shuffle into shuffle function, added drawing cards
// 	   1.2 name: Brandon P 10/21/24 moved table to seperate file
//	   1.3 name: Thomas Z 10/22/24 writing function body for Cards Class
//

#include"cards.hpp"   // Need the header file for this one as well
//#include"cards.cpp" // For some reason this is needed
#include "deck.hpp"   // To include the header file
#include <algorithm>  // For shuffle
#include <random>     // For random_device, std::mt19937
#include <iostream>   // For cout

using namespace std;

// Constructor: Initializes a standard deck of 52 cards
DECK::DECK() {
	// Define suits and names
	const array<string, 4> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
	const array<string, 13> names = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

	// Create a card for each combination of suit and name
	for (size_t i = 0; i < suits.size(); ++i) {
		for (size_t j = 0; j < names.size(); ++j) {
			cards.emplace_back(suits[i], names[j]);  // Using CARD's parameterized constructor
		}
	}
}

// Draws a card from the top of the deck and removes it
CARD DECK::draw() {
	if (cards.empty()) {
		throw runtime_error("No more cards in the deck to draw.");
	}

	CARD topCard = cards.back();
	cards.pop_back();  // Remove the last card
	return topCard;
}

// Shuffles the deck of cards
void DECK::shuffle(){
	random_device rd;
	mt19937 g(rd());
	std::shuffle(cards.begin(), cards.end(), g);
}
void DECK::shuffle(int seed){
	random_device rd;
	mt19937 g(seed);
	std::shuffle(cards.begin(), cards.end(), g);
}

// Discards the top card (removes it without returning it)
void DECK::discard() {
	if (cards.empty()) {
		throw runtime_error("No more cards in the deck to discard.");
	}
	cards.pop_back();
}

// Displays all cards currently in the deck
void DECK::display() const {
	for (size_t i = 0; i < cards.size(); ++i) {
		cards[i].display();  // Calls CARD's display method
	}
}
