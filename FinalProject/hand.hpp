//
// CSS 225 FINAL PROJECT 
// Name: hand.h
// Version 1.0 name: Bradon P 10/21/24 Changes moved table to seperate header file
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
//

#include "cards.hpp"
#include "player.hpp"
using namespace std;

#ifndef HAND_CLASS
#define HAND_CLASS

class HAND {
    protected:
        CARD cards[7];
    public:
        void display_hand() const;
};
#endif
