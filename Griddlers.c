#include <glut.h>
#include <stdio.h>
int correctArr[3][5][5] = { {{1,0,0,0,1},{1,1,0,1,1},{0,1,0,1,0},{0,1,1,1,0},{0,0,1,0,0}},
{{1,0,0,0,1},{1,1,0,1,1},{0,1,1,1,0},{0,1,0,1,0},{0,1,1,1,0} },
{{0,1,0,0,0},{0,1,0,1,1},{0,0,1,0,0},{1,1,1,0,0},{1,1,1,1,0}} };
int gameArr[5][5] = { 0 }, win,level=0,time;
void Reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500, 500,0);
	glMatrixMode(GL_MODELVIEW);
}
void check()
{
	int i, j,h,m,s;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (correctArr[level][i][j] != gameArr[i][j])
				break;
		}
		if (j != 5) break;
	}
	if (i == j && j == 5) {
		h = time / 3600;
		m = time / 60;
		s = time % 60;
		win = 1;
		printf("You Win! You do this griddler with %d:%d:%d\n",h,m,s);
	}
}
void Lines() {
	int i;
	glColor3f(0, 0, 0);
	glLineWidth(2);
	glBegin(GL_LINES);
	for (i = 0; i <= 5; i++)
	{
		glVertex2i(0,100*i);
		glVertex2i(500, 100 * i);
	}
	for (i = 0; i <= 5; i++)
	{
		glVertex2i(100*i, 0);
		glVertex2i(100*i, 500);
	}
	glEnd();
	glFlush();
}
void timer(int a)
{
	time++;
	glutTimerFunc(1000, timer, 0);
}
void Draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	Lines();
	win =time= 0;
	glutTimerFunc(1000, timer, 0);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; gameArr[i][j] = 0, j++);
	switch (level) {
	case 0:
		printf("Level 1 Aries:\n     2 3 2 3 2\n1 1\n2 2\n1 1\n  3\n  1\n");
		break;
	case 1:
		printf("Level 2 Taurus:\n         1\n     2 4 1 4 2\n1 1\n2 2\n  3\n1 1\n  3\n");
		break;
	case 2:
		printf("Level 3 Bunny:\n       2   1\n     2 2 3 1 1\n  1\n1 2\n  1\n  3\n  4\n");
		break;
	default:

		break;
	}
	glFlush();
}
void Mouse(int button, int state, int x, int y)
{
	int xx=x/100,yy=y/100;
	if (!win) {
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (gameArr[yy][xx] == 0)
			{
				glColor3f(0, 0, 0);
				glRectf(100 * xx, 100 * yy, 100 * xx + 100, 100 * yy + 100);
				gameArr[yy][xx] = 1;
			}
			else if (gameArr[yy][xx] == 1)
			{
				glColor3f(1, 1, 1);
				glRectf(100 * xx, 100 * yy, 100 * xx + 100, 100 * yy + 100);
				gameArr[yy][xx] = 0;
			}
		}
		check();
		Lines();
	}
	glFlush();
}
void Menu(int value)
{
	switch (value)
	{
	case 0:
		level = 0;
		Draw();
		break;
	case 1:
		if (level < 3) {
			level++;
			Draw();
		}
		else printf("No More Levels\n");
		break;
	case 2:
		exit(1);
		break;
	}
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(700, 100);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("Griddler Game");
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Draw);
	glutMouseFunc(Mouse);
	glClearColor(1, 1, 1, 0);
	glutCreateMenu(Menu);
	glutAddMenuEntry("New Game", 0);
	glutAddMenuEntry("Next Level", 1);
	glutAddMenuEntry("Exit", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
