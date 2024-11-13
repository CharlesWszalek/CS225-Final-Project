//
// CSS 225 FINAL PROJECT 
// Name: global.cpp
// Version 1.0 name: Charles W 11/03/24 created
// 	   1.1 name: Brandon P 11/05/24 added conv_string_int
// 	   1.2 name: Thomas Z  10/30/24 added the deck to global so all could access it
// 	   1.2 name: Brandon P 11/8/24  removed the deck to global for better solution
// Reference: 
//

#include "global.hpp"

// Converts a string to an int
int conv_string_int(string input){
	int num = 0;
	for (char c : input){  // in put
		if (c >= '0' && c <= '9' && c != '\n') {  // checks input
			num = num * 10 + (c - '0');
		} else {
			cout << "Input must be an integer" << endl;
			return 0;
		}
	}
	return num; // returns conversion
}
