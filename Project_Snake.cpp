#include<iostream>
#include<gl\glut.h>
#include<math.h>
#include<Windows.h>
#include"Food.h"
#include"Snake.h"
Food food;
Snake snake1(6, 220, 23, 28);
Snake snake2(4, 18, 53, 200);
bool looper = true;
void DrawString(void *font, const char s[], float r = 0, float g = 0, float b = 0)//���ַ���ʾ
{
	float x = -0.2, y = 0.1, sum;
	sum = r + g + b;
	r = r / sum;
	g = g / sum;
	b = b / sum;
	glColor3f(r, g, b);
	unsigned int i;
	glRasterPos2f(x, y);
	for (i = 0; i < strlen(s); i++)
	{
		glutBitmapCharacter(font, s[i]);
	}
}
void timer(int p)//ʱ��ص�����
{
	glClearColor(0.36, 0.36, 0.22, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	food.Appear();
	food.DrawFood(12,230,12);//����ʳ��
	snake1.DisplayFunc();
	snake2.DisplayFunc();
	snake1.Grow(food);//���Ե�ʳ��������
	snake2.Grow(food);
	if (!snake1.Isalive(snake2) || !snake2.Isalive(snake1))//���������������һ��
	{
		looper = false;
		if (snake2.Isalive(snake1))DrawString(GLUT_BITMAP_TIMES_ROMAN_24, "Blue Win!", 18, 53, 200);
	    else if(snake1.Isalive())DrawString(GLUT_BITMAP_TIMES_ROMAN_24, "Red Win!", 220, 23, 28);
		else if(snake1.Getlength()>snake2.Getlength())(GLUT_BITMAP_TIMES_ROMAN_24, "Blue Win!", 18, 53, 200);
		else if(snake1.Getlength() <snake2.Getlength())DrawString(GLUT_BITMAP_TIMES_ROMAN_24, "Blue Win!", 18, 53, 85);
		else DrawString(GLUT_BITMAP_TIMES_ROMAN_24, "GameOver!", 0, 0, 0);
		glFlush();
	}
	snake1.Move();//�������ƶ�
	snake2.Move();
	glutSwapBuffers();
	if (looper)
	{
		glutTimerFunc(100, timer, 0);
	}
}
void KeyBoard(unsigned char key, int x, int y)//��Ӧ��������
{
	snake1.KeyBoardFunc(key,x,y);
}
void special(int key, int x, int y)//��Ӧ���������
{
	snake2.SpecialFunc(key,x,y);
}
void display()//����Ҫ��ͼʱ�������myDisplay����
{
	glClearColor(0.41, 0.36, 0.22, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();//˫�����½�������������ָ��
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);//��GLUT���г�ʼ�����������������������GLUTʹ��֮ǰ����һ�Ρ�
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);//������ʾ��ʽ������GLUT_RGB��ʾʹ��RGB��ɫ����֮��Ӧ�Ļ���GLUT_INDEX����ʾʹ��������ɫ����
	//���⣬GLUT_SINGLE��ʾʹ�õ����壬��֮��Ӧ�Ļ���GLUT_DOUBLE��ʹ��˫���壩��
	glutInitWindowPosition(200, 100);//���ô�������Ļ�е�λ��
	glutInitWindowSize(600, 600);//���ô��ڵĴ�С��
	glutCreateWindow("��   ��   ɽ   ��   ��   ��  ��   ��   ��   ��  ͬ   ѧ");//����ǰ�����õ���Ϣ�������ڡ�����������Ϊ���ڵı��⡣

	
	glutDisplayFunc(&display);//����һ������������Ҫ���л�ͼʱ����������ͻᱻ���á�
	glutTimerFunc(100, timer, 0);
	glutKeyboardFunc(KeyBoard);
	glutSpecialFunc(special);//��Ӧ�����ϵ����ⰴ��
	glutMainLoop();//����һ����Ϣѭ�����������������ʾ���ڣ����ҵȴ����ڹرպ�Ż᷵��.
	return 0;
}