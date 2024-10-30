
#include "hand.hpp"
#include "cards.hpp"
//#include "cards.cpp"
#include "player.hpp"
using namespace std;


HAND::HAND(){}


void HAND::display_hand() const {
  for (int i = 0; i < 2; i++) {
    cards[i].display();
  }
}
