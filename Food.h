#pragma once
#include<gl\glut.h>
#include<math.h>
#include"Snake.h"
const int N = 100;//ȫ�ֱ������൱�ڽ���ͼ���ڻ���ΪN*N������
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
	void Appear();//ÿ�ζ���Ҫ���ô˺������˺���������Ҫ�����µ�ʳ��ʱ�Զ������µ�ʳ��
	void DrawFood(float R=0.0,float G=1.0,float B=0.0);//����ʳ��������Ϊʳ����ɫ��RGBֵ
};

