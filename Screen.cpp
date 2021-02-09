#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "Screen.h"
#include "Buffscreen.h"
#include "Movement.h"
#include "Keyboard.h"
#include "Option.h"

char	Player1[50], Player2[50];

void 	drawWelcome()
{
	textcolor(LT_GREEN);
	drawFrame(50,16,0,0);
	
	for(int i = 1; i < 50; i++)
	{
    	gotoxy(i, 2);
    	printf("%c", 205); 
    }
    
	for(int i = 3; i < 16; i++)
	{
    	gotoxy(25, i);
    	printf("%c", 186); 
    }
    for(int i = 1; i < 50; i++)
	{
    	gotoxy(i, 8);
    	printf("%c", 205);
		gotoxy(i, 10); 
		printf("%c", 205);
    }
	
	gotoxy(0, 2); printf("%c", 204);
    gotoxy(50, 2); printf("%c", 185);
    
    gotoxy(25, 2); printf("%c", 203);
	gotoxy(25, 16); printf("%c", 202);
	
	gotoxy(0, 8); printf("%c", 204);
    gotoxy(50, 8); printf("%c", 185);
    
	gotoxy(25, 10); printf("%c", 203);
	gotoxy(25, 8); printf("%c", 202);
	
	gotoxy(0, 10); printf("%c", 204);
    gotoxy(50, 10); printf("%c", 185);
	
}

void 	writePlayer(int x, int y, int option)
{
	textcolor(LT_RED);
	gotoxy(x, y);
	puts(Player1);

	if(option == 1) 
	{
		gotoxy(x - 6, y + 2);
		printf("Up: %c 	Down: %c", UP_1,DOWN_1);
	}
	else
	{
		gotoxy(x - 6 , y + 2);
		printf("Up: %c 	Down: %c", DB_UP_1,DB_DOWN_1);
	}
	
	textcolor(LT_YELLOW);
	gotoxy(x + 25, y);

	puts(Player2);
	
	if(option == 1) 
	{
		gotoxy(x + 18, y + 2);
		printf("Up: %c 	Down: %c", UP_2,DOWN_2);
	}
	else
	{
		gotoxy(x + 18, y + 2);
		printf("Up: %c 	Down: %c", DB_UP_2,DB_DOWN_2);
	}
}

void 	Player()
{
	gotoxy(3, 2);
	printf("--- Enter your name, please! ---");
	gotoxy(3, 3);
	printf("--------------------------------");
	gotoxy(5, 5);
	printf("Player 1 : ");
	fflush(stdin); gets(Player1);
	gotoxy(5, 7);
	printf("Player 2 : ");
	fflush(stdin); gets(Player2);

	system("cls");
}

void 	welcomeScreen()
{
	Player();
	drawWelcome();
	
	textcolor(LT_BLUE);
    gotoxy(17, 1);
	printf("o0o CONTROLS o0o ");
	
	writePlayer(11, 3, 1);

	textcolor(LT_BLUE);

	gotoxy(15, 9);
	printf("o0o DOUBLE PRESS o0o ");

	writePlayer(11, 11, 2);

	textcolor(LT_BLUE);
	gotoxy(20, 17);
	printf("Have funnn.");
	gotoxy(12, 18);
	printf("Nhan phim bat ki de bat dau.");
     
	getch();
    system("cls");
    Hidecursorscr();
}

void 	tim(int x, int y)
{
	srand(time(NULL));

	int a = rand() % 15 + 1;	
	textcolor(a);		
	gotoxy(x, y);
	printf(" * *   * *  ");  
	gotoxy(x, y + 1);     
	printf("* * * * * * ");
	gotoxy(x, y + 2);
	printf("  * * * *  ");
	gotoxy(x, y + 3);
	printf("   * * *");
	gotoxy(x, y + 4);
	printf("     * ");
	Sleep(100);
	
	gotoxy(x, y);
	printf("  **   **  ");
	gotoxy(x, y + 1);     
	printf(" *** * *** ");
	gotoxy(x, y + 2);
	printf("  ** * **  ");
	gotoxy(x, y + 3);
	printf("   * * *");
	gotoxy(x, y + 4);
	printf("     * ");
}

void 	endScreen(int scoreL, int scoreR)
{
	while(1)
	{
		system("cls");
		srand(time(NULL));
		textcolor(8 + rand() % 8);

		drawFrame(60, 15, 0, 0);
	
		textcolor(8 + rand() % 8);
		
		gotoxy(25, 2);
		if(scoreL > scoreR)
		{
			puts(Player1);
		}
		else 
		{
			puts(Player2);
		}
		gotoxy(26, 4);

		printf("WIN");
		gotoxy(10, 6);
		
		printf("<3 Cam on vi ban da choi game nay <3");
		Sleep(10);

		int a = rand() % 70 + 15;
		int b = rand() % 25 + 17;

		tim(a, b);
		
		textcolor(8 + rand() % 8);
		gotoxy(3, 10);
		printf("Choi lai : R ");
		gotoxy(3, 11);
		printf("Thoat ra : ESC ");
		Sleep(70);
		char keyEnd;
		if(kbhit()) 					//neu nguoi dung nhan 1 phim
		{
			keyEnd = getch();		//thi gan phim do vao keyPress
			checkKeyEnd(keyEnd);
			break;
		}
	}	
}

void 	drawFrame(int x, int y, int startX, int startY)
{
	for(int i = startX; i <= x; i++)
	{
    	gotoxy(i, startY);
    	printf("%c", 205); 
    }
    for(int i = startY; i <= y; i++)
	{
    	gotoxy(startX, i);
    	printf("%c", 186); 
    }
	for(int i = startX; i <= x; i++)
	{
   		gotoxy(i, y);
    	printf("%c", 205); 
    }	
    for(int i = startY; i <= y; i++)
	{
   		gotoxy(x, i);
    	printf("%c", 186); 
    }
    
 	gotoxy(startX, startY); printf("%c", '\xc9');
	gotoxy(startX, y); printf("%c", '\xc8');		
	gotoxy(x, startY); printf("%c", '\xbb');		
	gotoxy(x, y); printf("%c", '\xbc');						
}

void 	setupBoard(char board[][70], int sizex, int sizey, int pRight, int pLeft, int ballPosY, int ballPosX)
{
	int x, y;
	for(x = 0; x < sizex; x++)
	{
		for(y = 0; y < sizey; y++)
		{
			if((y == pLeft - 2|| y == pLeft - 1|| y == pLeft|| y == pLeft + 1|| y == pLeft + 2) && x == 2)
			{
				board[y][x] = 177;
			}
			else if(((y == pRight - 2|| y == pRight - 1|| y == pRight|| y == pRight + 1|| y == pRight + 2) && x == 67))	
			//hai thanh bar cach nhau
			{
				board[y][x] = 177;
			}
			else 
			{
				//khung choi
				textcolor(LT_GREEN);
				for(int i = 1; i < sizey - 1; i++) 	// in ra cot ben trai cua khung
				{
					board[i][0]  = '\xba';  
				}
				
				for(int i = 1; i < sizex - 1; i++)	 // in ra dong tren cua khung
				{
					board[0][i]	 = '\xcd';
				}
				for(int i = 1; i < sizey - 1; i++) 		// in ra cot ben phai cua khung	
				{
					board[i][sizex - 1] = '\xba';
				}
				for(int i = 1; i < sizex - 1; i++)		// in ra dong duoi cua khung
				{
					board[sizey - 1][i] = '\xcd';
				}
				//in 4 goc
				board[0][0] = '\xc9';		
				board[0][sizex - 1] = '\xbb';
				board[sizey - 1][0] = '\xc8';
				board[sizey - 1][sizex - 1] = '\xbc';

				for(int i = 1; i < sizey - 1; i++) 	// in ra cot ben trai cua khung
				{
					board[i][sizex / 2]  = '|';  
				}
				
				board[y][x] = ' ';
				board[ballPosY][ballPosX] = 'O';	
			}
		}
	}
}

void 	printBoard(char board[][70], int sizex, int sizey, int scoreL, int scoreR)
{
	int x, y;
	for(y = 0; y < sizey; y++)
	{
		for(x = 0; x < sizex; x++)
		{ 
			printf("%c", board[y][x]);	
			if ((y == sizey - 1) && (x == sizex - 2)) 
				printf("%c", '\xbc');	//in goc duoi ben phai 
		}
		printf("\n");
	}
	
	textcolor(LT_YELLOW);
	gotoxy(93, 2);
	printf("SCORE");
	textcolor(LT_BLUE);
	gotoxy(85, 5); puts(Player1);
	gotoxy(101, 5); puts(Player2);
	textcolor(BLUE);
	gotoxy(87, 7);
	printf("%d", scoreL);// in diem  
	gotoxy(103, 7);
	printf("%d", scoreR);// in diem
	
	textcolor(LT_CYAN);

	drawFrame(110, 10, 80, 4);
	for(int i = 5; i <= 9; i++)
	{
		gotoxy(95, i);
		printf("%c", 176);  
	}
}

void 	welcome()
{
	while (1)
	{
//		system("cls"); //nhap nhay
		Clrscr(); //ko nhap nhay 
		srand(time(NULL));
		textcolor(8 + rand() % 8);
		Sleep(5);
		gotoxy(10, 8);
		printf("  /$$$$$                                         /$$$$$                                                   ");
		gotoxy(10, 9);
		printf(" /$$__ $$                                       /$$__ $$                                            ");
		gotoxy(10, 10);
		printf("| $$  \\$$  /$$                                 | $$  \\$$  /$$                                           ");
		gotoxy(10, 11); 
		printf("| $$   $$  |__/  /$$$$$$$     /$$$$$$          | $$   $$  |__/  /$$$$$$$     /$$$$$$              ");
		gotoxy(10, 12);
		printf("| $$$$$$    /$$ | $$ __  $$ | $$__  $$         | $$$$$$    /$$ | $$ __  $$ | $$__  $$           ");
		gotoxy(10, 13);
		printf("| $$       | $$ | $$   \\ $$ | $$  \\ $$         | $$       | $$ | $$   \\ $$ | $$  \\ $$                       ");
		gotoxy(10, 14);
		printf("| $$       | $$ | $$   | $$ | $$  | $$         | $$       | $$ | $$   | $$ | $$  | $$      ");
		gotoxy(10, 15);
		printf("| $$       | $$ | $$   | $$ | $$  | $$         | $$       | $$ | $$   | $$ | $$  | $$             ");
		gotoxy(10, 16);
		printf("|__/       |__/ |__/   |__/  \\$$$$$$$$         |__/       |__/ |__/   |__/  \\$$$$$$$$                  ");
		gotoxy(10, 17);
		printf("                                ____$$                                         ____$$                                 ");
		gotoxy(10, 18);
		printf("                                   |$$                                            |$$                                    ");
		gotoxy(10, 19);
		printf("                             /$$   |$$                                      /$$   |$$                                    ");
		gotoxy(10, 20);
		printf("                             | $$$$$$/                                      | $$$$$$/                                   ");
		gotoxy(10, 21);
		printf("                              \\_____                                         \\_____                                    ");
	
		textcolor(8 + rand() % 8);
		Sleep(5);
		gotoxy(30, 25);
		printf("  /$$$$$                                                                                       ");
		gotoxy(30, 26);
		printf(" /$$__ $$   ");
		gotoxy(30, 27);
		printf("| $$  \\$$                                                                       ");
		gotoxy(30, 28); 
		printf("| $$   $$    /$$$$$     /$$$$$$       /$$$$$$              ");
		gotoxy(30, 29);
		printf("| $$$$$$   /$$___ $$  | $$ __  $$   | $$__  $$             \n");
		gotoxy(30, 30);
		printf("| $$      | $$   \\$$  | $$   \\ $$   | $$  \\ $$            ");
		gotoxy(30, 31);
		printf("| $$      | $$   |$$  | $$   | $$   | $$  | $$          ");
		gotoxy(30, 32);
		printf("| $$      |  $$$$$$/  | $$   | $$   | $$  | $$          ");
		gotoxy(30, 33);
		printf("|__/       \\______/   |__/   |__/    \\ $$$$$$$           ");
		gotoxy(30, 34);
		printf("                                        ____$$                                          ");
		gotoxy(30, 35);
		printf("                                           |$$                                    ");
		gotoxy(30, 36);
		printf("                                     /$$   |$$                                            ");
		gotoxy(30, 37);
		printf("                                     | $$$$$$/                                       ");
		gotoxy(30, 38);
		printf("                                      \\_____                                   ");

		gotoxy(40, 40);
		textcolor(14);
		printf("Nhan SPACE de bat dau.");
 		char keyPress;
		if(kbhit())					//neu nguoi dung nhan 1 phim
		{
			keyPress = getch();		//thi gan phim do vao keyPress
			if ( keyPress == 32)
			{
				system("cls");
				break;
			}
		}		
	}
	welcomeScreen();
}

