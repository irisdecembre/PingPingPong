#ifndef MOVEMENT_H
#define MOVEMENT_H

void	ballMovement(int &ballPosX, int &ballPosY, int &scoreR, int &scoreL, int sizex, int sizey, int &pLeft, int &pRight,
			int &moveUp, int &moveRight, int &moveLeft, int &moveDown, int &minusX, int &minusY, int &plusX, int &plusY);
void 	playerMovement(int &pLeft, int &pRight);
void 	Play();
void	diem(int &ballPosX, int &ballPosY, int &scoreR, int &scoreL, int sizex, int sizey,
			int &moveUp, int &moveRight, int &moveLeft, int &moveDown, int &minusX, int &minusY, int &plusX, int &plusY);


#endif

