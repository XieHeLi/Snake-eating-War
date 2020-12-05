#pragma once
#include"Food.h"
class Snake
{
	int x[100], y[100];//蛇的每段身体坐标
	int BodyLenth,direction;//蛇的节数和当前移动方向，移动方向说明：8上2下4左6右
	bool life;//记录是否存活
	float ColorR, ColorG, ColorB;//蛇的颜色
	bool Isbroken();//撞到墙或者吃到你自己了吗

public:
	Snake();
	Snake(Snake &S);
	Snake(int Direction);
	Snake(float R=1,float G=0,float B=0);
	Snake(int Direction,float R,float G,float B);
	~Snake();
	int Getlength();
	bool Iseaten(class Food &F);//蛇吃食物了吗
	bool Isalive(class Snake &S);//蛇还活着吗
	bool Isalive();
	bool Isbiten(Snake &S);//被另外一条蛇咬到了吗
	void Grow(class Food &F);
	void Move();
	void KeyBoardFunc(unsigned char key, int X, int Y);//响应opengl中的glutKeyboardFunc（）函数，与W,A,S,D键交互
	void SpecialFunc(int key,int X,int Y);//响应o[engl中的glutSpecialFunc（）函数，与方向键进行交互
	void DisplayFunc();//画图，放入opengl中的glutDisplayFunc( )函数
};

