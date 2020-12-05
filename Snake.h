#pragma once
#include"Food.h"
class Snake
{
	int x[100], y[100];//�ߵ�ÿ����������
	int BodyLenth,direction;//�ߵĽ����͵�ǰ�ƶ������ƶ�����˵����8��2��4��6��
	bool life;//��¼�Ƿ���
	float ColorR, ColorG, ColorB;//�ߵ���ɫ
	bool Isbroken();//ײ��ǽ���߳Ե����Լ�����

public:
	Snake();
	Snake(Snake &S);
	Snake(int Direction);
	Snake(float R=1,float G=0,float B=0);
	Snake(int Direction,float R,float G,float B);
	~Snake();
	int Getlength();
	bool Iseaten(class Food &F);//�߳�ʳ������
	bool Isalive(class Snake &S);//�߻�������
	bool Isalive();
	bool Isbiten(Snake &S);//������һ����ҧ������
	void Grow(class Food &F);
	void Move();
	void KeyBoardFunc(unsigned char key, int X, int Y);//��Ӧopengl�е�glutKeyboardFunc������������W,A,S,D������
	void SpecialFunc(int key,int X,int Y);//��Ӧo[engl�е�glutSpecialFunc�����������뷽������н���
	void DisplayFunc();//��ͼ������opengl�е�glutDisplayFunc( )����
};

