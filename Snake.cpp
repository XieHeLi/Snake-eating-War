#include "Snake.h"
#include<gl\glut.h>
#include<math.h>
#include"Food.h"
Snake::Snake()
{
	//type = 1;//默认方向键控制
	direction = 6;//默认朝右边
	BodyLenth = 20;//初始体长为20
	ColorR = 1;
	ColorG = 0;
	ColorB = 0;//默认红色
	life = true;
	int i,j;
	for (i = 0,j=N/2-15; i < BodyLenth; i++,j--)
	{
		x[i] = N / 2 - 1;
		y[i] = j;
	}
}
Snake::Snake(Snake &S)
{
	direction = S.direction;
	BodyLenth = S.BodyLenth;
	ColorR = S.ColorR;
	ColorG = S.ColorG;
	ColorB = S.ColorB;
	life = S.life;
	//type = S.type;
	int i;
	for (i = 0; i < BodyLenth; i++)
	{
		x[i] = S.x[i];
		y[i] = S.y[i];
	}
}
Snake::Snake(int Diretion)
{
	BodyLenth = 20;//初始体长为20
	ColorR = 1;
	ColorG = 0;
	ColorB = 0;//默认红色
	life = true;
	int i, j;
	if (Diretion == 8)//朝上
	{
		direction = 8;
		for (i = 0,j=N/2-25; i < BodyLenth; i++,j++)
		{
			y[i] = N / 2 - 1;
			x[i] = j;
		}
	}
	else if (Diretion == 2)//朝下
	{
		direction = 2;
		for (i = 0, j = N / 2 +25; i < BodyLenth; i++, j--)
		{
			y[i] = N / 2 - 1;
			x[i] = j;
		}
	}
	else if (Diretion == 4)//朝左
	{
		direction = 4;
		for (i = 0, j = N / 2 + 15; i < BodyLenth; i++, j++)
		{
			x[i] = N / 2 - 1;
			y[i] = j;
		}
	}
	else//朝右边
	{
		direction = 6
;
		for (i = 0, j = N / 2 - 15; i < BodyLenth; i++, j--)
		{
			x[i] = N / 2 - 1;
			y[i] = j;
		}
	}
}
Snake::Snake(float R, float G, float B)
{
	float sum;
	sum = R + G + B;
	direction = 6;//默认朝右边
	BodyLenth = 20;//初始体长为20
	ColorR = R/sum;
	ColorG = G/sum;
	ColorB = B/sum;//默认红色
	life = true;
	int i, j;
	for (i = 0, j = N / 2 - 15; i < BodyLenth; i++, j--)
	{
		x[i] = N / 2 - 1;
		y[i] = j;
	}
}
Snake::Snake(int Diretion, float R, float G, float B)
{
	float sum;
	sum = R + G + B;
	BodyLenth = 20;//初始体长为20
	ColorR = R / sum;
	ColorG = G / sum;
	ColorB = B / sum;
	life = true;
	int i, j;
	if (Diretion == 8)//朝上
	{
		direction = 8;
		for (i = 0, j = N / 2 + 25; i < BodyLenth; i++, j++)
		{
			y[i] = N / 2 - 1;
			x[i] = j;
		}
	}
	else if (Diretion == 2)//朝下
	{
		direction = 2;
		for (i = 0, j = N / 2 - 25; i < BodyLenth; i++, j--)
		{
			y[i] = N / 2 - 1;
			x[i] = j;
		}
	}
	else if (Diretion == 4)//朝左
	{
		direction = 4;
		for (i = 0, j = N / 2 + 15; i < BodyLenth; i++, j++)
		{
			x[i] = N / 2 - 1;
			y[i] = j;
		}
	}
	else//朝右边
	{
		direction = 6;
		for (i = 0, j = N / 2 - 15; i < BodyLenth; i++, j--)
		{
			x[i] = N / 2 - 1;
			y[i] = j;
		}
	}
}

Snake::~Snake()
{
}
int Snake::Getlength()
{
	return BodyLenth;
}
bool Snake::Isbroken()
{
	if (x[0]<0 || x[0]>N-1 || y[0]<0 || y[0]>N-1)return true;
	for (int i = 1; i < BodyLenth; i++)
	{
		if (x[0] == x[i] && y[0] == y[i])return true;
	}
	return false;
}
bool Snake::Isbiten(Snake &S) 
{
	int i;
	for (i = 1; i < BodyLenth; i++)
	{
		if (x[i] == S.x[0] && y[i] == S.y[0])return true;
	}
	return false;
}
bool Snake::Isalive(Snake &S)
{
	if (Isbroken())
		life = false;
	if (Isbiten(S))//如果被另外一条蛇咬到了
		life = false;
	if (x[0] == S.x[0] && y[0] == S.y[0])
		life = false;
	return life;
}
bool Snake::Isalive() {
	return life;
}
bool Snake::Iseaten(Food &F)
{
	if (x[0] == F.x&&y[0] == F.y)return true; 
	else return false;
}
void Snake::Grow(Food &F)
{
	if (Iseaten(F))
	{
		for (int i = BodyLenth; i > 0; i--)
		{
			x[i] = x[i - 1];
			y[i] = y[i - 1];
		}
		if (direction == 8) x[0]--;
		else if (direction == 4)y[0]--;
		else if (direction == 6)y[0]++;
		else x[0]++;
		BodyLenth++;
		F.IsApper = true;
	}
}
void Snake::Move()
{
	int i = 0;
	switch (direction)
	{
	case 8:
		for (i = BodyLenth-1; i > 0; i--)
		{
			x[i] = x[i - 1];
			y[i] = y[i - 1];
		}
		x[0]--;
		break;
	case 4:
		for (i = BodyLenth - 1; i > 0; i--)
		{
			x[i] = x[i - 1];
			y[i] = y[i - 1];
		}
		y[0]--;
		break;
	case 6:
		for (i = BodyLenth - 1; i > 0; i--)
		{
			x[i] = x[i - 1];
			y[i] = y[i - 1];
		}
		y[0]++;
		break;
	case 2:
		for (i = BodyLenth - 1; i > 0; i--)
		{
			x[i] = x[i - 1];
			y[i] = y[i - 1];
		}
		x[0]++;
		break;
	default:
		break;
	}
}
void Snake::KeyBoardFunc(unsigned char key, int X, int Y)
{
	int i;
	switch (key)
	{
	case 87://向上移动
		if (direction == 2)break;//原来向下移动直接退出
		for (i = BodyLenth - 1; i > 0; i--)
		{
			x[i] = x[i - 1];
			y[i] = y[i - 1];
		}
		x[0]--;
		direction = 8;
		glutPostRedisplay();//标记当前窗口需要重新绘制
		break;
	case 119:
		if (direction == 2)break;//原来向下移动直接退出
		for (i = BodyLenth - 1; i > 0; i--)
		{
			x[i] = x[i - 1];
			y[i] = y[i - 1];
		}
		x[0]--;
		direction = 8;
		glutPostRedisplay();
		break;
	case 97://向左移动
		if (direction == 6)break;
		for (i = BodyLenth - 1; i > 0; i--)
		{
			x[i] = x[i - 1];
			y[i] = y[i - 1];
		}
		y[0]--;
		direction = 4;
		glutPostRedisplay();//标记当前窗口需要重新绘制
		break;
	case 65:
		if (direction == 6)break;
		for (i = BodyLenth - 1; i > 0; i--)
		{
			x[i] = x[i - 1];
			y[i] = y[i - 1];
		}
		y[0]--;
		direction = 4;
		glutPostRedisplay();
		break;
	case 83://向下移动
		if (direction == 8)break;
		for (i = BodyLenth - 1; i > 0; i--)
		{
			x[i] = x[i - 1];
			y[i] = y[i - 1];
		}
		x[0]++;
		direction = 2;
		glutPostRedisplay();
		break;
	case 115:
		if (direction == 8)break;
		for (i = BodyLenth - 1; i > 0; i--)
		{
			x[i] = x[i - 1];
			y[i] = y[i - 1];
		}
		x[0]++;
		direction = 2;
		glutPostRedisplay();
		break;
	case 68://向右移动
		if (direction == 4)break;
		for (i = BodyLenth - 1; i > 0; i--)
		{
			x[i] = x[i - 1];
			y[i] = y[i - 1];
		}
		y[0]++;
		direction = 6;
		glutPostRedisplay();
		break;
	case 100:
		if (direction == 4)break;
		for (i = BodyLenth - 1; i > 0; i--)
		{
			x[i] = x[i - 1];
			y[i] = y[i - 1];
		}
		y[0]++;
		direction = 6;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}
void Snake::SpecialFunc(int key, int X, int Y)
{
	int i;
	switch (key)
	{
	case GLUT_KEY_LEFT:
		if (direction == 6)break;
		for (i = BodyLenth - 1; i > 0; i--)
		{
			x[i] = x[i - 1];
			y[i] = y[i - 1];
		}
		y[0]--;
		direction = 4;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		if (direction == 4)break;
		for (i = BodyLenth - 1; i > 0; i--)
		{
			x[i] = x[i - 1];
			y[i] = y[i - 1];
		}
		y[0]++;
		direction = 6;
		glutPostRedisplay();
		break;
	case GLUT_KEY_UP:
		if (direction == 2)break;//原来向下移动直接退出
		for (i = BodyLenth - 1; i > 0; i--)
		{
			x[i] = x[i - 1];
			y[i] = y[i - 1];
		}
		x[0]--;
		direction = 8;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		if (direction == 8)break;
		for (i = BodyLenth - 1; i > 0; i--)
		{
			x[i] = x[i - 1];
			y[i] = y[i - 1];
		}
		x[0]++;
		direction = 2;
		glutPostRedisplay();
		break;
	}
}
void Snake::DisplayFunc()
{
	float x0, y0, x1, y1;
	int i;
	glColor3f(ColorR,ColorG,ColorB);
	for (i = 0; i < BodyLenth; i++)
	{
		x0 = ((float)y[i] - (float)N / 2) * 2 / (float)N;
		y0 = ((float)N / 2 - (float)x[i] - 1) * 2 / (float)N;
		x1 = ((float)y[i] - (float)N / 2 + 1) *2 / (float)N;
		y1 = ((float)N / 2 - (float)x[i]) * 2 / (float)N;
		glRectf(x0, y0, x1, y1);
	}
	glFlush();
}