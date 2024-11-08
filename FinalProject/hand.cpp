#include "deck.hpp"
#include "table.hpp"
#include "hand.hpp"
#include "cards.hpp"
//#include "cards.cpp"
#include "player.hpp"
using namespace std;
#include "global.hpp"

HAND::HAND(int enpty){
  for(int i=0;i<2;i++){
    cards[i] = deck.draw();
  }
}


HAND::HAND(){}


HAND::HAND(const HAND& h){
	for (int i = 0; i < 5; i++){
		this->cards[i] = h.cards[i];
	}
}


void HAND::display_hand() const {
  for (int i = 0; i < 2; i++) {
    cards[i].display();
    cout << " ";
  }
  cout << endl;
}

HAND HAND::operator+ (const CARD (&card)[5]){
  HAND temp;
  temp.cards[0] = cards[0];
  temp.cards[1] = cards[1];
  for (int i = 0; i < 5; i++){
    temp.cards[i+2] = card[i];
  };
  return temp;
}
