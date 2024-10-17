/*
 * Author: Brandon Pillon
 * Purpose: Fit image to size of display
 * Version: 1.0 10/15/24 tried making display using GLUT
 * 	    1.1 10/16/24 display using a matrix of text
 * recources:
 *
 * note: try using unistd.h 
 * */

#define SCRNWIDTH 16*10
#define SCRNHEIGHT 9*10

#include <iostream>

int main () {
	char screen[SCRNHEIGHT][SCRNWIDTH+1];
	for (int i=0; i < SCRNHEIGHT; i++) {
		for (int j=0; j < SCRNWIDTH; j++) {
			screen[i][j] = 219;
		}
		screen[i][SCRNWIDTH] = '\n';
		screen[i][SCRNWIDTH+1] = '\0';
	}
//	screen[SCRNHEIGHT][SCRNWIDTH+1] = '\0';
	std::cout << *screen << std::endl;
	return 0;
}
