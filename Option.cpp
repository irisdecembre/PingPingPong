#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
	
#include "Screen.h"
#include "Buffscreen.h"
#include "Movement.h"
#include "Keyboard.h"
#include "Option.h"

	
void 	checkKeyEnd(char end)
{
	if(end == RETURN) 
	{
		system("cls");
		welcomeScreen();
		Play();
	}
	else 
	{
		Bye();
	}
}

void 	Play()
{
	char 	board[Sizey][Sizex];

	int		ballPosX = Sizex /2, ballPosY = Sizey /2;
	int 	moveUp    = 1;
	int 	moveDown  = 0;
	int 	moveLeft  = 0;
	int 	moveRight = 1;
	int 	minusY = 1, minusX = 1, plusY = 1, plusX = 1;
	int 	scoreL = 0, scoreR = 0;

	int 	pLeft  = 3; 
	int 	pRight = 3;
	
	init(ballPosX, ballPosY, scoreR, scoreL, Sizex, Sizey, moveUp, moveRight, moveLeft, moveDown,
			minusX, minusY, plusX, plusY);
	while(scoreL < high && scoreR < high)	//lap vo tan
	{
		Clrscr();
		//setup player movement
		playerMovement(pLeft, pRight);
		
		//setup board
		setupBoard(board, Sizex, Sizey, pRight, pLeft, ballPosY, ballPosX);
		//ball movement
		ballMovement(ballPosX, ballPosY, scoreR, scoreL, Sizex, Sizey, pLeft, pRight, moveUp, moveRight, moveLeft, moveDown,
			minusX, minusY, plusX, plusY);
		//diem 
		diem(ballPosX, ballPosY, scoreR, scoreL, Sizex, Sizey, moveUp, moveRight, moveLeft, moveDown,
			minusX, minusY, plusX, plusY);
		//in bang
		printBoard(board, Sizex, Sizey, scoreL, scoreR);
	}
	endScreen(scoreL, scoreR);
}

void 	Bye()
{
	system("cls");
	srand(time(NULL));
	int x = rand() % 2;

	switch(x)
	{
		case 0: 
		{
			textcolor(8 + rand() % 8);
			printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
			printf("*  CHAO TAM BIET VA HEN GAP LAI *\n");
			printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n\n\n");
		}
		break;
		case 1: 
		{
			textcolor(8 + rand() % 8);
			printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
			printf("* GOODBYE AND SEE YOU LATER *\n\n");
			printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n\n\n");
		}
		break;
		default: 
		{
			textcolor(8 + rand() % 8);
			printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
			printf("*  AU REVOID ET À PLUS TARD *\n\n");
			printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n\n\n");
		}
	}
}




