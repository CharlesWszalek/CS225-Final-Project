//
// CSS 225 FINAL PROJECT 
// Name: hand.h
// Version 1.0 name: Bradon P 10/21/24 Changes moved table to seperate header file
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
//

#ifndef HAND_CLASS
#define HAND_CLASS
#include "deck.hpp"
#include "cards.hpp"
#include "global.hpp"
using namespace std;


class HAND {
    //protected:
    //    CARD cards[7];
    public:
        CARD cards[7];
        HAND operator+ (const CARD (&)[5]);
        HAND();
        HAND(DECK);
	HAND(const HAND& h);
        void display_hand() const;
};
#endif
