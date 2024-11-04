#include "deck.hpp"
#include "table.hpp"
#include "hand.hpp"
#include "cards.hpp"
//#include "cards.cpp"
#include "player.hpp"
using namespace std;
#include "global.hpp"

HAND::HAND(){
  for(int i=0;i<2;i++){
    cards[i] = deck.draw();
  }
}


void HAND::display_hand() const {
  for (int i = 0; i < 2; i++) {
    cards[i].display();
  }
}

HAND HAND::operator + (CARD card[5]){
  HAND temp;
  for (int i = 0; i < 5; i++){
    cards[i+2] = card[i];
    temp.cards[i] = cards[i];
  };
  return temp;
}