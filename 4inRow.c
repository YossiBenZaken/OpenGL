#include <stdio.h>
#include <math.h>
#include <glut.h>
#include <string.h>
int arr[7][8] = { 0 }, flag = 0, win = 0;
char player1[10], player2[10];
void Reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 700, 600, 0);
	glMatrixMode(GL_MODELVIEW);
}
void cir1(int xc, int yc, int r)
{
	int x, y;
	double alfa;
	for (alfa = 0; alfa < 360; alfa+=0.1)
	{
		x = xc + floor(r*cos(alfa*3.14 / 180) + 0.5);
		y = yc + floor(r*sin(alfa*3.14 / 180) + 0.5);
		glBegin(GL_LINES);
		glVertex2i(xc, yc);
		glVertex2i(x, y);

		glEnd();
	}
}
void kavim()
{
	glColor3f(0, 0, 0);
	for (int i = 1; i < 8; i++)
	{
		glBegin(GL_LINES);
		glVertex2i(i * 100, 0);
		glVertex2i(i * 100, 600);
		glEnd();
	}
	for (int i = 1; i < 7; i++)
	{
		glBegin(GL_LINES);
		glVertex2i(700, i * 100);
		glVertex2i(0, i * 100);
		glEnd();
	}
}
void Sprint(char *st)
{
	while (*st)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *st++);

}
void Draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 8; arr[i][j] = 0, j++);
	for (int i = 1; i <= 14; i+=2)
	{
		for (int j = 1; j <= 12; j += 2) {
			glColor3ub(0, 13, 127);
			cir1(50 * i, 50 * j, 50);
		}
	}
	win = 0;
	kavim();
	glFlush();
}
void check()
{
	int i, j, c, k, z;
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (arr[i][j] == 1)
			{
				k = j;
				c = 0;
				while (k < 7 && arr[i][j] == arr[i][k])
				{
					c++;
					k++;
				}
				if (c >= 4) {
					win = 1; break;
				}
			}
		}
		for (j = 0; j < 7; j++)
		{
			if (arr[i][j] == 1)
			{
				k = i;
				c = 0;
				while (k < 6 && arr[i][j] == arr[k][j])
				{
					c++;
					k++;
				}
				if (c >= 4) {
					win = 1; break;
				}
			}
		}
		for (j = 0; j < 7; j++)
		{
			if (arr[i][j] == 2)
			{
				k = j;
				c = 0;
				while (k < 7 && arr[i][j] == arr[i][k])
				{
					c++;
					k++;
				}
				if (c >= 4) {
					win = 2; break;
				}
			}
		}
		for (j = 0; j < 7; j++)
		{
			if (arr[i][j] == 2)
			{
				k = i;
				c = 0;
				while (k < 7 && arr[i][j] == arr[k][j])
				{
					c++;
					k++;
				}
				if (c >= 4) {
					win = 2; break;
				}
			}
		}
		for (j = 0; j < 7; j++)
		{
			if (arr[i][j] == 1)
			{
				if (arr[i][j] == arr[i + 1][j + 1] && arr[i][j] == arr[i + 2][j + 2] && arr[i][j] == arr[i + 3][j + 3])
				{
					win = 1;
					break;
				}
			}
		}
		for (j = 0; j < 7; j++)
		{
			if (arr[i][j] == 1)
			{
				if (arr[i][j] == arr[i + 1][j - 1] && arr[i][j] == arr[i + 2][j - 2] && arr[i][j] == arr[i + 3][j - 3])
				{
					win = 1;
					break;
				}
			}
		}
		for (j = 0; j < 7; j++)
		{
			if (arr[i][j] == 2)
			{
				if (arr[i][j] == arr[i + 1][j + 1] && arr[i][j] == arr[i + 2][j + 2] && arr[i][j] == arr[i + 3][j + 3])
				{
					win = 2;
					break;
				}
			}
		}
		for (j = 0; j < 7; j++)
		{
			if (arr[i][j] == 2)
			{
				if (arr[i][j] == arr[i + 1][j - 1] && arr[i][j] == arr[i + 2][j - 2] && arr[i][j] == arr[i + 3][j - 3])
				{
					win = 2;
					break;
				}
			}
		}
	}
	glColor3f(0, 1, 0);
	glRasterPos3i(300, 250, -1);
	if (win == 1) {
		Sprint(player1); Sprint(" Win");
	}
	else if (win == 2) {
		Sprint(player2); Sprint(" Win");
	}
}
void MouseFunc(int button, int state, int x, int y)
{
	if (win == 0)
	{
		int xx, yy;
		xx = x / 100;
		yy = y / 100;
		if (flag == 0 && button == 0 && state == 0)
		{
			glColor3f(1, 0, 0);
			if (arr[5][xx] == 0)
			{
				cir1(100*(xx) + 50, 550, 50);
				arr[5][xx] = 1;
			}
			else if (arr[4][xx] == 0)
			{
				cir1(100 * (xx)+50, 450, 50);
				arr[4][xx] = 1;
			}
			else if (arr[3][xx] == 0)
			{
				cir1(100 * (xx)+50, 350, 50);
				arr[3][xx] = 1;
			}
			else if (arr[2][xx] == 0)
			{
				cir1(100 * (xx)+50, 250, 50);
				arr[2][xx] = 1;
			}
			else if (arr[1][xx] == 0)
			{
				cir1(100 * (xx)+50, 150, 50);
				arr[1][xx] = 1;
			}
			else if (arr[0][xx] == 0)
			{
				cir1(100 * (xx)+50, 50, 50);
				arr[0][xx] = 1;
			}
			flag = 1;
		}
		else if (flag == 1 && button == 0 && state == 0)
		{
			glColor3f(1, 1, 0);
			if (arr[5][xx] == 0)
			{
				cir1(100 * (xx)+50, 550, 50);
				arr[5][xx] = 2;
			}
			else if (arr[4][xx] == 0)
			{
				cir1(100 * (xx)+50, 450, 50);
				arr[4][xx] = 2;
			}
			else if (arr[3][xx] == 0)
			{
				cir1(100 * (xx)+50, 350, 50);
				arr[3][xx] = 2;
			}
			else if (arr[2][xx] == 0)
			{
				cir1(100 * (xx)+50, 250, 50);
				arr[2][xx] = 2;
			}
			else if (arr[1][xx] == 0)
			{
				cir1(100 * (xx)+50, 150, 50);
				arr[1][xx] = 2;
			}
			else if (arr[0][xx] == 0)
			{
				cir1(100 * (xx)+50, 50, 50);
				arr[0][xx] = 2;
			}
			flag = 0;
		}
		kavim();
		if (state == 1)
			check();
	}
	glFlush();
}
void main_menu(int value)
{
	switch (value) {
	case 1:	exit(0); break;
	case 2:Draw(); break;
	}
}
int main(int argc, char *argv[])
{
	printf("Enter name player 1:");
	gets(player1);
	printf("Enter name player 2:");
	gets(player2);
	glutInit(&argc, argv);
	glutInitWindowSize(700, 600);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("4inRow");
	glutCreateMenu(main_menu);
	glutAddMenuEntry("Quit", 1);
	glutAddMenuEntry("New Game", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Draw);
	glutMouseFunc(MouseFunc);
	glClearColor(0, 0, 1, 0);
	glutMainLoop();

	return 0;
}
