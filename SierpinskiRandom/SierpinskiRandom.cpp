#include "Angel.h"

void display(void)
{
	/* A triangle */
	GLfloat vertices[3][2] = { { 0.0, 0.0 }, { 25.0, 50.0 }, { 50.0, 0.0 } };
	int i, j, k;
	GLfloat p[2] = { 0, 0 };  /* an arbitrary initial point inside traingle */
	glClear(GL_COLOR_BUFFER_BIT);  /* clear the window */
	glBegin(GL_POINTS);
	/* compute and plots 10000 new points */
	for (k = 0; k < 10000; k++)
	{
		j = rand() % 3; /* pick a vertex at random */
		/* Compute point halfway between selected vertex and old point */
		p[0] = (p[0] + vertices[j][0]) / 2.0;
		p[1] = (p[1] + vertices[j][1]) / 2.0;
		/* plot new point */
		glVertex2fv(p);
	}
	glEnd();
	glFlush(); /* clear buffers */
}


void init(void)
{
	/* attributes */
	glClearColor(1.0, 1.0, 1.0, 1.0); /* white background */
	glColor3f(0.0, 1.0, 0.0); /* draw in green */
	/* set up viewing */
	/* 50.0 ¡Á 50.0 camera coordinate window with origin lower left */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 50.0, 0.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
}

void main(int argc, char** argv)
{
	/* Standard GLUT initialization */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400); /* 500 ¡Á 500 pixel window */
	glutInitWindowPosition(220, 120); /* place window top left on display */
	glutCreateWindow("Sierpinski Gasket"); /* window title */
	glewInit();
	glutDisplayFunc(display);/* display callback invoked when window opened */
	init(); /* set attributes */
	glutMainLoop(); /* enter event loop */
}
