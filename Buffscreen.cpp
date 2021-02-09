#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "Screen.h"
#include "Buffscreen.h"


void 	Clrscr()
{
	// xoa man hinh
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void 	Hidecursorscr()
{
	// an con chay
	CONSOLE_CURSOR_INFO cursor;
	cursor.dwSize = 1; cursor.bVisible = 0;
	HANDLE _hscr = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(_hscr, &cursor);
}

void 	gotoxy(int x, int y) 
{ 
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
	COORD position = {x, y}; 
	SetConsoleCursorPosition(hStdout, position); 
}

void 	textcolor(int a)
{
	HANDLE hConsoleColor, hConsoleOutput;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);	
	SetConsoleTextAttribute(hConsoleColor, a);
}
