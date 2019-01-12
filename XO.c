#include <glut.h>
#include <string.h>
#include <stdio.h>
int arr[3][3] = { 0 }, flag = 0, win = 0;
void Reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 300, 300, 0);
	glMatrixMode(GL_MODELVIEW);
}

void kavim()
{
	glColor3f(0, 0, 0);
	for (int i = 1; i < 3; i++)
	{
		glBegin(GL_LINES);
		glVertex2i(i * 100, 0);
		glVertex2i(i * 100, 300);
		glEnd();
	}
	for (int i = 1; i < 3; i++)
	{
		glBegin(GL_LINES);
		glVertex2i(300, i * 100);
		glVertex2i(0, i * 100);
		glEnd();
	}
}
void Draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	kavim();
	glFlush();
}
void Sprint(char *st)
{
	int l, i;

	l = strlen(st);
	glRasterPos3i(100, 150, -1);
	for (i = 0; i < l; i++)
	{
		glColor3f(1, 0, 0);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]);
	}

}
void check()
{
	if (arr[0][0] == 1)
	{
		if (arr[1][0] == 1 && arr[2][0] == 1) { Sprint("Red Win"); win = 1; }
		else if (arr[0][1] == 1 && arr[0][2] == 1) { Sprint("Red Win"); win = 1; }
		else if (arr[1][1] == 1 && arr[2][2] == 1) {Sprint("Red Win"); win = 1;}
	}
	if (arr[0][2] == 1)
	{
		if (arr[1][2] == 1 && arr[2][2] == 1) { Sprint("Red Win"); win = 1; }
		else if (arr[1][1] == 1 && arr[2][0] == 1) { Sprint("Red Win"); win = 1; }
	}
	if (arr[0][1] == 1)
	{
		if (arr[1][1] == 1 && arr[2][1] == 1) { Sprint("Red Win"); win = 1; }
	}
	if (arr[2][2] == 1)
	{
		if (arr[2][0] == 1 && arr[2][1] == 1) { Sprint("Red Win"); win = 1; }
	}
	if (arr[1][0] == 1)
	{
		if (arr[1][1] == 1 && arr[1][2] == 1) { Sprint("Red Win"); win = 1; }
	}

	if (arr[0][0] == 2)
	{
		if (arr[1][0] == 2 && arr[2][0] == 2) { Sprint("Green Win"); win = 1; }
		else if (arr[0][1] == 2 && arr[0][2] == 2) { Sprint("Green Win"); win = 1; }
		else if (arr[1][1] == 2 && arr[2][2] == 2) { Sprint("Green Win"); win = 1; }
	}
	if (arr[0][2] == 2)
	{
		if (arr[1][2] == 2 && arr[2][2] == 2) { Sprint("Green Win"); win = 1; }
		else if (arr[1][1] == 2 && arr[2][0] == 2) { Sprint("Green Win"); win = 1; }
	}
	if (arr[0][1] == 2)
	{
		if (arr[1][1] == 2 && arr[2][1] == 2) { Sprint("Green Win"); win = 1; }
	}
	if (arr[2][2] == 2)
	{
		if (arr[2][0] == 2 && arr[2][1] == 2) {Sprint("Green Win"); win = 1;}
	}
	if (arr[1][0] == 2)
	{
		if (arr[1][1] == 2 && arr[1][2] == 2) { Sprint("Green Win"); win = 1; }
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
			if (arr[yy][xx] == 0)
			{
				glColor3f(1, 0, 0);
				glRectf(100 * (xx), 100 * (yy), 100 * (xx)+100, 100 * (yy)+100);
				arr[yy][xx] = 1;
				flag = 1;
			}
		}
		else if (flag == 1 && button == 0 && state == 0)
		{
			if (arr[yy][xx] == 0)
			{
				glColor3f(0, 1, 0);
				glRectf(100 * (x / 100), 100 * (y / 100), 100 * (x / 100) + 100, 100 * (y / 100) + 100);
				arr[yy][xx] = 2;
				flag = 0;
			}
		}
		if (state == 1)
			check();
		kavim();
	}
	glFlush();
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("XO");
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Draw);
	glutMouseFunc(MouseFunc);
	glClearColor(1, 1, 1, 0);
	glutMainLoop();
	return 0;
}
