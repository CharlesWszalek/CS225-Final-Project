#include "deck.hpp"
#include "table.hpp"
#include "hand.hpp"
#include "cards.hpp"
#include "player.hpp"
#include "global.hpp"
using namespace std;

// Default constructor
HAND::HAND(){}

// Constructor
HAND::HAND(DECK d){
  for(int i=0;i<2;i++){
    cards[i] = d.draw();
  }
}

// Constructor
HAND::HAND(const HAND& h){
  for (int i = 0; i < 5; i++){
    this->cards[i] = h.cards[i];
  }
}

// display hand information for current player
void HAND::display_hand() const {
  for (int i = 0; i < 2; i++) {
    cards[i].display();
    cout << " ";
  }
  cout << endl;
}

// Overloading the + operator to add an array of 5 cards to each player's array of 7 cards
HAND HAND::operator+ (const CARD (&card)[5]){
  HAND temp;
  temp.cards[0] = cards[0];
  temp.cards[1] = cards[1];
  for (int i = 0; i < 5; i++){
    temp.cards[i+2] = card[i];
  };
  return temp;
}
