//
// CSS 225 FINAL PROJECT 
// Name: global.cpp
// Version 1.0 name: Charles W 11/03/24 created
// 	   1.1 name: Brandon P 11/05/24 added conv_string_int
// Reference: 
//

#include "global.hpp"


int conv_string_int(string input){
	int num = 0;
	for (char c : input){
		if (c >= '0' && c <= '9' && c != '\n') {
			num = num * 10 + (c - '0');
		} else {
			cout << "Input must be an integer" << endl;
			return 0;
		}
	}
	return num;
}
