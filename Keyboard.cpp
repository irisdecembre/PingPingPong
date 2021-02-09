#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "Keyboard.h"


void 	init(int &ballPosX, int &ballPosY, int &scoreR, int &scoreL, int sizex, int sizey,
			int &moveUp, int &moveRight, int &moveLeft, int &moveDown, int &minusX, int &minusY, int &plusX, int &plusY)
{
	srand(time(NULL));

	ballPosX = Sizex/2;  //dat lai vi tri cua qua bong o giua ban
	ballPosY = rand() % (Sizey - 3) + 10;
	
	moveUp = 1;			
	moveRight = 1;
	moveLeft = 0;
	moveDown = 0;
	minusX = 1;
	minusY = 1;
	plusX = 1;
	plusY = 1;

}

void 	checkKeyPress(char keyPress, int &pLeft, int &pRight)
{
	//player 1
	if(keyPress == UP_1 && pLeft > 3)   //neu nhan a thi di chuyen thanh len 1 hang va khong duoc cham bien tren
	{
		pLeft -= 1;
	}
	if(keyPress == DOWN_1 && pLeft < 26)	//neu nhan z thi di chuyen thanh xuong 1 hang va khong duoc cham bien duoi
	{
		pLeft += 1;
	}
	if(keyPress == DB_UP_1 && pLeft > 3)	//neu nhan S thi di chuyen thanh len 2 hang va khong duoc cham bien tren
	{
		pLeft -= 2;
		if(pLeft == 2)
		{
			pLeft = 3;
		}
	}
	if(keyPress == DB_DOWN_1 && pLeft < 26)	//neu nhan X thi di chuyen thanh xuong 2 hang va khong duoc cham bien duoi
	{
		pLeft += 2;
		if(pLeft == 27)					//do pLeft += 2 moi lan xuong hang nen khi pLeft == 25 no khong cham duoc bien duoi
		{
			pLeft = 26;					//nen gan pLeft = 26 khi pLeft == 25
		}	
	}
	//player 2
	if(keyPress == UP_2 && pRight > 3)
	{
		pRight -= 1;
	}
	if(keyPress == DOWN_2 && pRight < 26)
	{
		pRight += 1;
	}
	if(keyPress == DB_UP_2 && pRight > 3)	
	{
		pRight -= 2;
		if(pRight == 2)
		{
			pRight = 3;
		}
	}
	if(keyPress == DB_DOWN_2 && pRight < 26)	//neu nhan , thi di chuyen thanh xuong 2 hang va khong duoc cham bien duoi
	{
		pRight += 2;
		if(pRight == 27)					//do pLeft += 2 moi lan xuong hang nen khi pRight == 25 no khong cham duoc bien duoi
		{
			pRight = 26;					//nen gan pRight = 26 khi pRight == 25
		}
	}
}

