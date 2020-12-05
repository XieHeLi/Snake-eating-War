#include "Food.h"
#include<time.h>
#include<cstdlib>

Food::Food(void)
{
	srand(time(NULL));//随机出现从0~N-1的x坐标
	x = rand() % (N-1);
	srand(time(NULL));
	y = rand() %(N-1);
	IsApper = false;
}
Food::Food(Food &F) 
{
	x = F.x;
	y = F.y;
	IsApper = F.IsApper;
}
Food::Food(int x,int y)
{
	this->x = x;
	this->y = y;
	IsApper = false;
}
Food::~Food()
{
}
void Food::Appear()
{
	if (IsApper)
	{
		srand(time(NULL));
		x = rand() % (N-1);
		srand(time(NULL));
		y = rand() % (N-1);
		IsApper = false;
	}
}
void Food::DrawFood(float R,float G,float B)
{
	float sum;
	float x0, y0, x1, y1;
	sum = R + G + B;
	R = R/sum;
	G = G / sum;
	B = B / sum;
	x0 = ((float)y - (float)N / 2) * 2 / (float)N;
	y0 = ((float)N/2- (float)x-1) * 2 / (float)N;
	x1 = ((float)y- (float)N/2+1) * 2 / (float)N;
	y1 = ((float)N/2- (float)x) * 2 / (float)N;
	glColor3f(R,G,B);
	glRectf(x0,y0,x1,y1);
	glFlush();
}