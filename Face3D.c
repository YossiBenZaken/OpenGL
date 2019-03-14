#include <stdio.h>
#include <stdlib.h>
#include <glut.h>

int alfa = 0;

void reshape(int wid, int ht)
{
	glViewport(0, 0, wid, ht);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-4, 4, -4, 4, -4, 4);
	glMatrixMode(GL_MODELVIEW);


}

void init(void)
{
	float light_ambient[] = { 1,0,1, 1.0 },light_diffuse[] = { 1,0,1, 1.0 },light_specular[] = { 1,0,1, 1.0 },light_position[] = { 0,4,2, 1.0 };
	float light_ambient2[] = { 1,1,0, 1.0 }, light_diffuse2[] = { 1,1,0, 1.0 }, light_specular2[] = { 1,1,0, 1.0 }, light_position2[] = { 4,0,2, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient2);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse2);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular2);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position2);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);

}
void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();

	glRotatef(alfa, 1, 0, 0);
	glutSolidCube(2);
	glTranslatef(-0.5, 0.5, 1.1);
	glScalef(0.5, 0.5,0);
	glutSolidCube(1);
	glTranslatef(2, 0, 0);
	glutSolidCube(1);
	glTranslatef(-1, -1, 0);
	glutSolidTorus(0.3, 0, 20, 20);
	glTranslatef(0, -1, 0);
	glScalef(7, 0.5, 0);
	glutSolidSphere(0.2, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glRotatef(alfa, 1, 0, 0);
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0.5, 0, 0);
	glutSolidCone(0.5, 2, 30, 30);
	glTranslatef(-1, 0, 0);
	glutSolidCone(0.5, 2, 30, 30);
	glPopMatrix();
	glutSwapBuffers();
}


void MouseFunc(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON)
	{
		alfa = alfa + 10;
		glutPostRedisplay();
	}
}

void KeyFunc(unsigned char key, int x, int y)
{
	if (key == 27)
		alfa = alfa + 10;
}

int main(int argc, char* argv[])
{

	glutInit(&argc, argv);
	glutInitWindowSize(400, 400);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Demo");
	glutReshapeFunc(reshape);
	glutDisplayFunc(draw);
	glutKeyboardFunc(KeyFunc);

	glutMouseFunc(MouseFunc);
	glClearColor(0, 0, 0, 1);

	init();

	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
	return 0;
}