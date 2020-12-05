#pragma once
#include<gl\glut.h>
#include<math.h>
#include"Snake.h"
const int N = 100;//全局变量，相当于将视图窗口划分为N*N个矩形
class Food
{
	friend class Snake;
	int  x, y;
	bool  IsApper;

public:

	Food(void);
	Food(Food &F);
	Food(int x,int y);
	~Food();
	void Appear();//每次都需要调用此函数，此函数能在需要产生新的食物时自动产生新的食物
	void DrawFood(float R=0.0,float G=1.0,float B=0.0);//绘制食物，传入参数为食物颜色的RGB值
};

