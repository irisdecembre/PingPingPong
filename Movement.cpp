#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#include "Buffscreen.h"
#include "Movement.h"
#include "Keyboard.h"


void	ballMovement(int &ballPosX, int &ballPosY, int &scoreR, int &scoreL, int sizex, int sizey, int &pLeft, int &pRight,
			int &moveUp, int &moveRight, int &moveLeft, int &moveDown, int &minusX, int &minusY, int &plusX, int &plusY)
{
	if(moveUp)			//di chuyen len
	{
		ballPosY -= minusY;		//vi tri hang cua trai bong moi = vi tri hang cua trai bong cu - 1 co nghia la di chuyen trai bong len 1 hang
	}
	else if(moveDown)	//di chuyen xuong
	{
		ballPosY += plusY;		//vi tri hang cua trai bong moi = vi tri hang cua trai bong cu + 1 co nghia la di chuyen trai bong xuong 1 hang
	}
	
	if(moveRight)		//di chuyen qua phai
	{
		ballPosX += plusX;		//vi tri cot cua trai bong moi = vi tri cot cua trai bong cu + 1 co nghia la di chuyen trai bong qua phai 1 cot
	}
	else if(moveLeft)	//di chuyen qua trai
	{
		ballPosX -= minusX;		//vi tri cot cua trai bong moi = vi tri cot cua trai bong cu - 1 co nghia la di chuyen trai bong qua trai 1 cot
	}
	
	//neu bong cham bien tren (dong 2 hoac dong 1) thi cho bong bat xuong do loi neu ballPosY == 2 thi ballPosY - 2 < 0
	if(ballPosY == 2 || ballPosY == 1) 
	{		
		moveUp = 0;   //sai - khong di chuyen len
		moveDown = 1; //dung - di chuyen xuong
	} 
	//neu bong cham bien duoi (dong 28 hoac dong 27) thi cho bong bat len do loi neu ballPosY == 29 thi ballPosY + 2 > 30
	else if(ballPosY == 28 || ballPosY == 27) 
	{	
		moveUp = 1;		//dung - di chuyen len
		moveDown = 0;	//sai - khong di chuyen xuong
	}
	
	//chia cac huong bong nhay khi cham vao bar
	//ben trai
	if(ballPosX == 3 && (pLeft == ballPosY - 2|| pLeft == ballPosY - 1|| pLeft == ballPosY|| pLeft == ballPosY + 1|| pLeft == ballPosY + 2)) 
		//neu bong dap vo thanh nguoi choi hoac vuot qua thanh nguoi choi
	{
		moveLeft = 0;
		moveRight = 1;
		if(pLeft == ballPosY - 2) //ball vang ra goc 60 do tren
		{
			minusY = 2;				//cho vi tri cua bong len 2 hang
			plusY = 2;				//cho vi tri cua bong xuong 2 hang

			moveUp = 0;
			moveDown = 1;
		} 	
		else if(pLeft == ballPosY - 1)	//ball vang ra goc 45 dotren
		{
			minusY = 1;				//cho vi tri cua bong len 1 hang
			plusY = 1;				//cho vi tri cua bong xuong 1 hang

			moveUp = 0;
			moveDown = 1;
		}
		else if(pLeft == ballPosY)		//ball vang 90 do 
		{
			minusX = 2;				//cho vi tri cua bong sang trai 2 cot
			plusX = 2;				//cho vi tri cua bong sang phai 2 cot

			moveUp = 0;
			moveDown = 0;
		}
		else if(pLeft == ballPosY + 1)		//ball vang ra goc 45 do duoi
		{
			minusY = 1;				//cho vi tri cua bong len 1 hang
			plusY = 1;				//cho vi tri cua bong xuong 1 hang
	
			moveUp = 1;
			moveDown = 0;
		} 
		else if(pLeft == ballPosY + 2) 		//ball vang ra goc 60 do duoi
		{
			minusY = 2;				//cho vi tri cua bong len 2 hang
			plusY = 2;				//cho vi tri cua bong xuong 2 hang

			moveUp = 1;
			moveDown = 0;
		}
	}
	if(ballPosX == 65 && (pRight == ballPosY - 2|| pRight == ballPosY - 1|| pRight == ballPosY|| pRight == ballPosY + 1|| pRight == ballPosY + 2)) 
	{
		moveLeft = 1;
		moveRight = 0;
		if(pRight == ballPosY - 2) 
		{
			minusY = 2;					//cho vi tri cua bong len 2 hang
			plusY = 2;					//cho vi tri cua bong xuong 2 hang

			moveUp = 0;
			moveDown = 1;
		} 
		else if(pRight == ballPosY - 1)
		{
			minusY = 1;					//cho vi tri cua bong len 1 hang
			plusY = 1;					//cho vi tri cua bong xuong 2 hang

			moveUp = 0;
			moveDown = 1;
		} 
		else if(pRight == ballPosY) 
		{
			minusX = 2;					//cho vi tri cua bong qua trai 2 cot
			plusX = 2;					//cho vi tri cua bong qua phai 2 cot

			moveUp = 0;
			moveDown = 0;
		} 
		else if(pRight == ballPosY + 1) 
		{
			minusY = 1;					//cho vi tri cua bong len tren 1 hang
			plusY = 1;					//cho vi tri cua bong xuong 1 hang

			moveUp = 1;
			moveDown = 0;
		} 
		else if(pRight == ballPosY + 2) 
		{
			minusY = 2;					//cho vi tri cua bong len 2 hang
			plusY = 2;					//cho vi tri cua bong xuong 2 hang

			moveUp = 1;
			moveDown = 0;
		}
	}
}

void 	playerMovement(int &pLeft, int &pRight)
{
	char keyPress;
	if(kbhit())					//neu nguoi dung nhan 1 phim
	{
		keyPress = getch();		//thi gan phim do vao keyPress
	}
	else						//khong thi gan keyPress == ' '  de khong cho chay lien tuc
	{
		keyPress = ' ';
	}
	//set key
	//player 1
	checkKeyPress(keyPress, pLeft, pRight);

}

void 	diem(int &ballPosX, int &ballPosY, int &scoreR, int &scoreL, int sizex, int sizey,
			int &moveUp, int &moveRight, int &moveLeft, int &moveDown, int &minusX, int &minusY, int &plusX, int &plusY)
{
	if(ballPosX < 1)		//neu hoanh do ball be hon 1
	{
		scoreR++;
		init(ballPosX, ballPosY, scoreR, scoreL, Sizex, Sizey, moveUp, moveRight, moveLeft, moveDown,
			minusX, minusY, plusX, plusY);
	}
	else if(ballPosX > 66)	//neu hoanh do ball lon hon 66
	{
		scoreL++;
		init(ballPosX, ballPosY,scoreR, scoreL, Sizex, Sizey, moveUp, moveRight, moveLeft, moveDown,
			minusX, minusY, plusX, plusY);	
	}
}


