//
// CSS 225 FINAL PROJECT
// Name: cards.cpp
// Version 1.0 name: Thomas Z 10/22/2024created
//


#include "cards.hpp"
using namespace std;



string CARD::get_suit() {return suit;}

string CARD::get_name() {return name;}

void CARD::set_suit(string Suit):suit(Suit) {}

void CARD::set_name(string Name):name(Name) {}

void CARD::display() {cout << name << " of " << suit << endl;}
