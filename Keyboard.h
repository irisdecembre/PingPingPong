#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <stdio.h>

#define		Sizex	70
#define 	Sizey	30

#define 	BLACK 		0
#define 	BLUE 		1 
#define 	GREEN 		2 
#define 	CYAN 		3
#define 	RED 		4 
#define 	MAGENTA 	5 
#define 	YELLOW 		6 
#define 	WHITE 		7 
#define 	GRAY 		8
#define 	LT_BLUE 	9
#define 	LT_GREEN 	10 
#define 	LT_CYAN 	11 
#define 	LT_RED 		12 
#define		LT_MAGENTA	13 
#define 	LT_YELLOW 	14 
#define 	LT_WHITE 	15

#define		UP_1		97		//a
#define		DB_UP_1		115		//s
#define		DOWN_1		122		//z
#define		DB_DOWN_1	120		//x
	
#define		UP_2		59		//;
#define		DB_UP_2		108		//l
#define		DOWN_2		46		//.
#define		DB_DOWN_2	44		//,

#define 	ESC			13
#define		SPACE		32
#define		RETURN		114

#define		high		3


void 	init(int &ballPosX, int &ballPosY, int &scoreR, int &scoreL, int sizex, int sizey,
			int &moveUp, int &moveRight, int &moveLeft, int &moveDown, int &minusX, int &minusY, int &plusX, int &plusY);


void	checkKeyPress(char keyPress, int &pLeft, int &pRight);

#endif
