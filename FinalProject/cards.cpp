//
// CSS 225 FINAL PROJECT
// Name: cards.cpp
// Version 1.0 name: Thomas Z 10/22/2024created
//

#include "cards.hpp"
using namespace std;

// Default constructor

// Constructor with parameters
CARD::CARD(){}

CARD::CARD(string Suit, string Name) : suit(Suit), name(Name){
  if(name == " Ace "){
    value = 0;
  } else if (name == "  2  "){
    value = 1;
  } else if (name == "  3  "){
    value = 2;
  } else if (name == "  4  "){
    value = 3;
  } else if (name == "  5  "){
    value = 4;
  } else if (name == "  6  "){
    value = 5;
  } else if (name == "  7  "){
    value = 6;
  } else if (name == "  8  "){
    value = 7;
  } else if (name == "  9  "){
    value = 8;
  } else if (name == " 10  "){
    value = 9;
  } else if (name == "Jack "){
    value = 10;
  } else if (name == "Queen"){
    value = 11;
  } else if (name == "King "){
    value = 12;
  }
}


string CARD::get_suit(){return suit;}


int CARD::get_suit_2(){
  if(suit == " Clubs  "){
    return 0;
  } else if (suit == "Diamonds"){
    return 1;
  } else if (suit == " Hearts "){
    return 2;
  } else if (suit == " Spades "){
    return 3;
  }
  return 0;
}


string CARD::get_name(){return name;}


int CARD::get_value(){return value;};



// Display method
void CARD::display() const {
    cout << "| " << name << " of " << suit << " |";
}

/*int main(){
  CARD card("Hearts", "Ace");
  card.display();
  return 0;
}*/

