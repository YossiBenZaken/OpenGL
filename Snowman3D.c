#include <stdlib.h>
#include <glut.h>

void myinit(void)
{

	float position[] = { -4.0, -4.0, 3.0, 0.0 };
	glEnable(GL_DEPTH_TEST);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Guf()
{

	float my_ambiant[] = { 0.5,0.5,0.5, 1 };
	float my_diffuse[] = { 0.5,0.5,0.5 ,1 };
	float my_specular[] = { 1,1,1, 1.0 };
	float my_shininess[] = { 100 }; // 0 t0 128
	float my_emission[] = { 0.2,0.2,0.2, 1 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, my_ambiant);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, my_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, my_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, my_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, my_emission);
	glPushMatrix();
	glTranslatef(0, -2, 0);
	glutSolidSphere(1.5, 30, 30);
	glPopMatrix();
	glutSolidSphere(1.0, 30, 30);
	glPushMatrix();
	glTranslatef(0, 1.3, 0);
	glutSolidSphere(0.5, 30, 30);
	glPopMatrix();
}
void Nose() {
	float my_ambiant[] = { 0.78,0.21,0,1 };
	float my_diffuse[] = { 0.78,0.21,0,1 };
	float my_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	float my_shininess[] = { 120 };
	float my_emission[] = { 0.2,0.2,0.2, 0.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, my_ambiant);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, my_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, my_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, my_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, my_emission);
	glPushMatrix();
	glTranslatef(0, 1.2, 2);
	glRotatef(60, 0, -15, 0);
	glutSolidCone(0.2, 0.5, 3, 2);
	glPopMatrix();
}
void Eyes()
{

	float my_ambiant[] = { 0,0,0,1 };
	float my_diffuse[] = { 0,0,0,1 };
	float my_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	float my_shininess[] = { 120 };
	float my_emission[] = { 0.2,0.2,0.2, 0.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, my_ambiant);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, my_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, my_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, my_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, my_emission);
	glPushMatrix();
	glTranslatef(0.20, 1.4, 1.5);
	glutSolidSphere(0.1, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.20, 1.4, 1.5);
	glutSolidSphere(0.1, 30, 30);
	glPopMatrix();
}
void Kova() {
	float my_ambiant[] = { 1,0,0,1 };
	float my_diffuse[] = { 1,0,0,1 };
	float my_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	float my_shininess[] = { 120 };
	float my_emission[] = { 0.2,0.2,0.2, 0.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, my_ambiant);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, my_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, my_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, my_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, my_emission);
	glPushMatrix();
	glTranslatef(0, 1.6, 0);
	glRotatef(180, 0, 0, 0);
	glutSolidTeapot(0.4);
	glPopMatrix();
}
void Buttons() {
	float my_ambiant[] = { 0,0,0,1 };
	float my_diffuse[] = { 0,0,0,1 };
	float my_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	float my_shininess[] = { 120 };
	float my_emission[] = { 0.2,0.2,0.2, 0.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, my_ambiant);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, my_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, my_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, my_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, my_emission);
	glPushMatrix();
	glTranslatef(0, 0.5, 2);
	glutSolidSphere(0.1, 30, 30);
	glTranslatef(0, -0.4, 0);
	glutSolidSphere(0.1, 30, 30);
	glTranslatef(0, -0.4, 0);
	glutSolidSphere(0.1, 30, 30);
	glPopMatrix();
}
void Hands() {
	float my_ambiant[] = { 0.4,0.26,0.12,1 };
	float my_diffuse[] = { 0.4,0.26,0.12,1 };
	float my_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	float my_shininess[] = { 120 };
	float my_emission[] = { 0.2,0.2,0.2, 0.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, my_ambiant);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, my_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, my_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, my_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, my_emission);
	glPushMatrix();
	glTranslatef(0.9, 0, 0);
	glRotatef(90, 0, 180, 0);
	glutSolidCone(0.2, 1, 3, 2);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.9, 0, 0);
	glRotatef(-90, 0, 180, 0);
	glutSolidCone(0.2, 1, 3, 2);
	glPopMatrix();
}
void draw(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Kova();
	Guf();
	Nose();
	Eyes();
	Hands();
	Buttons();
	glFlush();
}

void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-4, 4, -4, 4, -4, 4);
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow(argv[0]);
	myinit();
	glutReshapeFunc(myReshape);
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}