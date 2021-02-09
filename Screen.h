#ifndef SCREEN_H
#define SCREEN_H

void 	welcomeScreen();
void 	drawFrame(int x, int y, int startX, int startY);
void 	drawWelcome();
void 	setupBoard(char board[][70], int sizex, int sizey, int pRight, int pLeft, int ballPosY, int ballPosX);
void 	printBoard(char board[][70], int sizex, int sizey, int scoreL, int scoreR);
void 	writePlayer(int x, int y, int option);
void 	Player();
void 	welcome();
void 	endScreen(int scoreL, int scoreR);

#endif
