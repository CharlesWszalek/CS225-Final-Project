//
// CSS 225 FINAL PROJECT 
// Name: game.h
// Version 1.0 name: Bradon P 10/21/24 Changes moved table to seperate header file
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
//

#include "cards.hpp"
#include "player.hpp"
#include "table.hpp"

#ifndef GAME_CLASS
#define GAME_CLASS

class GAME{
private:
    TABLE table;
protected:
public:
    GAME(TABLE table) {
        this->table = table;
    };
};

#endif
