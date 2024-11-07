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
  cout << "*****Your hand*****" << endl;
  for (int i = 0; i < 2; i++) {
    cards[i].display();
    cout << " ";
  }
  cout << endl;
}

HAND HAND::operator + (CARD card[5]){
  HAND temp;
  temp.cards[0] = cards[0];
  temp.cards[1] = cards[1];
  for (int i = 0; i < 5; i++){
    temp.cards[i+2] = card[i];
  };
  return temp;
}
