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

#include "deck.hpp"
#include "cards.hpp"
#include <algorithm>    // For std::shuffle
#include <random>       // For random number generation
#include <ctime>        // For seeding the random generator
using namespace std;

// Constructor to initialize the deck with 52 cards
DECK::DECK() {
	const vector<string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
	const vector<string> names = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

	// Populate the deck with all 52 cards
	for (const auto& suit : suits) {
		for (const auto& name : names) {
			cards.emplace_back(suit, name);
		}
	}
}

// Draw a card from the top of the deck
CARD DECK::draw() {
	if (cards.empty()) {
		throw out_of_range("No cards left in the deck!");
	}
	CARD drawn_card = cards.back();
	cards.pop_back();
	return drawn_card;
}

// Shuffle the deck
void DECK::shuffle() {
	random_device rd;
	mt19937 g(rd());
	std::shuffle(cards.begin(), cards.end(), g);
}

// Discard the top card from the deck
void DECK::discard()
{
	if (!cards.empty()) {
		cards.pop_back();
	}
}

// Display all cards in the deck
void DECK::display() const {
	for (const auto& card : cards) {
		card.display();
	}
}

int main()
{
	const DECK deck;
	deck.display();
}