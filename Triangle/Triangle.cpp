#include "Angle.h"
GLint W = 400;
GLint H = 300;


void  Display()  {

	glClear(GL_COLOR_BUFFER_BIT);  // Clear the frame buffer

	glColor3f(0.0, 1.0, 0.0);     // Set current color to green

	glBegin(GL_POLYGON);            // Draw the triangle
	glVertex2f(-0.7, -0.7);
	glVertex2f(0.7, -0.7);
	glVertex2f(0, 0.7);
	glEnd();

	glFlush();   // Force to display the new drawings immediately
}

void  Init()  {
	glClearColor(0.0, 0.0, 0.0, 0.0);   // Set the clear color to black

	// Specify the boundaries of the viewing region
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // The para are: (left, right, bottom, top)

	glMatrixMode(GL_MODELVIEW);
}

void Reshape(int w, int h){
	glViewport(0, 0, w, h);
	Print(w);
	Print(h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		gluOrtho2D(-2.0, 2.0, -2.0 * (GLfloat)h / (GLfloat)w,
		2.0 * (GLfloat)h / (GLfloat)w);
	else
		gluOrtho2D(-2.0 * (GLfloat)w / (GLfloat)h, 2.0 *
		(GLfloat)w / (GLfloat)h, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_BLEND);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_POLYGON_SMOOTH);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
}
void Menu(int id){
	switch (id)
	{
	case 1:
		exit(EXIT_SUCCESS);
		break;
	default:
		break;
	}
}



int  main(int  argc, char  **argv)  {
	glutInit(&argc, argv);          // Initialize GLUT function callings
	//set the mode
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GL_MULTISAMPLE);

	// Set window size (width, height) in number of pixels  
	glutInitWindowSize( W, H);
	
	// Set window position, from the left-top of the screen,
	glutInitWindowPosition(200, 100);        // in numbers of pixels 

	// Specify a window creation event 
	glutCreateWindow("A Green Triangle");
	glewInit;
	Init();// Invoke this function for initialization

	//Reshape
	glutReshapeFunc(Reshape);


	// Specify the drawing function that is called when the window 
	glutDisplayFunc(Display);         // is created or re-drew

	//Menu
	glutCreateMenu(Menu);
	glutAddMenuEntry("Exit",1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();           // Enter the event processing loop

	return 0;                     // Indicate normal termination 
	// (Required by ANSI C)
}
