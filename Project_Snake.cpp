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
void DrawString(void *font, const char s[], float r = 0, float g = 0, float b = 0)//画字符提示
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
void timer(int p)//时间回调函数
{
	glClearColor(0.36, 0.36, 0.22, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	food.Appear();
	food.DrawFood(12,230,12);//画出食物
	snake1.DisplayFunc();
	snake2.DisplayFunc();
	snake1.Grow(food);//若吃到食物则增长
	snake2.Grow(food);
	if (!snake1.Isalive(snake2) || !snake2.Isalive(snake1))//如果两条蛇中死了一条
	{
		looper = false;
		if (snake2.Isalive(snake1))DrawString(GLUT_BITMAP_TIMES_ROMAN_24, "Blue Win!", 18, 53, 200);
	    else if(snake1.Isalive())DrawString(GLUT_BITMAP_TIMES_ROMAN_24, "Red Win!", 220, 23, 28);
		else if(snake1.Getlength()>snake2.Getlength())(GLUT_BITMAP_TIMES_ROMAN_24, "Blue Win!", 18, 53, 200);
		else if(snake1.Getlength() <snake2.Getlength())DrawString(GLUT_BITMAP_TIMES_ROMAN_24, "Blue Win!", 18, 53, 85);
		else DrawString(GLUT_BITMAP_TIMES_ROMAN_24, "GameOver!", 0, 0, 0);
		glFlush();
	}
	snake1.Move();//两条蛇移动
	snake2.Move();
	glutSwapBuffers();
	if (looper)
	{
		glutTimerFunc(100, timer, 0);
	}
}
void KeyBoard(unsigned char key, int x, int y)//响应键盘输入
{
	snake1.KeyBoardFunc(key,x,y);
}
void special(int key, int x, int y)//响应方向键输入
{
	snake2.SpecialFunc(key,x,y);
}
void display()//当需要画图时，请调用myDisplay函数
{
	glClearColor(0.41, 0.36, 0.22, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();//双缓冲下交换两个缓冲区指针
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);//对GLUT进行初始化，这个函数必须在其它的GLUT使用之前调用一次。
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);//设置显示方式，其中GLUT_RGB表示使用RGB颜色，与之对应的还有GLUT_INDEX（表示使用索引颜色）。
	//此外，GLUT_SINGLE表示使用单缓冲，与之对应的还有GLUT_DOUBLE（使用双缓冲）。
	glutInitWindowPosition(200, 100);//设置窗口在屏幕中的位置
	glutInitWindowSize(600, 600);//设置窗口的大小。
	glutCreateWindow("青   城   山   下   白   素  贞   的   两   个  同   学");//根据前面设置的信息创建窗口。参数将被作为窗口的标题。

	
	glutDisplayFunc(&display);//设置一个函数，当需要进行画图时，这个函数就会被调用。
	glutTimerFunc(100, timer, 0);
	glutKeyboardFunc(KeyBoard);
	glutSpecialFunc(special);//相应键盘上的特殊按键
	glutMainLoop();//进行一个消息循环。这个函数可以显示窗口，并且等待窗口关闭后才会返回.
	return 0;
}