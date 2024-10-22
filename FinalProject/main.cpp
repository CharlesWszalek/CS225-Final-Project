//
// CSS 225 FINAL PROJECT 
// Name: table.h
// Version 1.0 name: Bradon P 10/21/24 created
// Reference: https://en.wikipedia.org/wiki/Texas_hold_%27em#Play_of_the_hand
//

//#include <iostream>
#include "table.h"
using namespace std;


void texas_hold_em() {
	TABLE t;
	t.betting();
	t.flop();
}


int main() {
	texas_hold_em();
	return 0;
}
