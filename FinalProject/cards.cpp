//
// CSS 225 FINAL PROJECT
// Name: cards.cpp
// Version 1.0 name: Thomas Z 10/22/2024created
//


#include "cards.hpp"
using namespace std;

// Default constructor

// Constructor with parameters
CARD::CARD(string Suit, string Name) : suit(Suit), name(Name) {}

string CARD::get_suit() { return suit; }

string CARD::get_name() { return name; }

// Display method
void CARD::display() const {
    cout << name << " of " << suit << endl;
}

/*int main(){
  CARD card("Hearts", "Ace");
  card.display();
  return 0;
}*/

