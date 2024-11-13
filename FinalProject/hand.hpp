//
// CSS 225 FINAL PROJECT 
// Name: hand.hpp
// Version 1.0 name: Bradon P 10/21/24 Changes moved table to seperate header file
// 	   1.1 name: Brandon P 10/25/24 functionality added
//	   1.2 name: Charles W 10/30/24 overloaded + operaator 
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
//

#ifndef HAND_CLASS
#define HAND_CLASS

#include "deck.hpp"
#include "cards.hpp"
#include "global.hpp"
using namespace std;


class HAND {
public:
	CARD cards[7];
	HAND operator+ (const CARD (&)[5]);
	HAND();
	HAND(DECK);
	HAND(const HAND& h);
	void display_hand() const;
};
#endif
