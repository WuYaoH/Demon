
#include "Angel.h"
#include "Util.h"
#define SIZE 512    

#define DEBUG
//#define TIMER

#define HAIR 1  
#define FACE 2  
#define LEFTWHITEOFEYE 3
#define RIGHTWHITEOFEYE 4
#define LEFTBLACKOFEYE 5
#define RIGHTBLACKOFEYE 6
#define NOSE 7  
#define LEFTCHEEK 8
#define RIGHTCHEEK 9
#define MOUTH 10
#define LEFTEAR 11
#define RIGHTEAR 12
#define BALL 13

static int backgroud = 0;
static int hair = 1;
static int face = 2;
static int leftwhiteofeye = 3;
static int rightwhiteofeye = 4;
static int leftblackofeye = 5;
static int rightblackofeye = 6;
static int nose = 7;
static int leftcheek = 8;
static int rightcheek = 9;
static int mouth = 10;
static int leftear = 11;
static int rightear = 12;
static int coscolor = 13;


static GLfloat nose_x = 0;
static GLfloat nose_y = 0;
static GLfloat leftwhiteofeye_x = 0;
static GLfloat leftwhiteofeye_y = 0;
static GLfloat rightwhiteofeye_x = 0;
static GLfloat rightwhiteofeye_y = 0;
static GLfloat leftear_x = 0;
static GLfloat leftear_y = 0;
static GLfloat rightear_x = 0;
static GLfloat rightear_y = 0;
static GLfloat leftblackofeye_x = 0;
static GLfloat leftblackofeye_y = 0;
static GLfloat rightblackofeye_x = 0;
static GLfloat rightblackofeye_y = 0;
static GLfloat leftblackofeyex = -10;
static GLfloat rightblackofeyex = 18;
static GLfloat leftcheek_x = 0;
static GLfloat leftcheek_y = 0;
static GLfloat rightcheek_x = 0;
static GLfloat rightcheek_y = 0;
static GLfloat mouth_x = 0;
static GLfloat mouth_y = 0;
static GLfloat hair_x = 0;
static GLfloat hair_y = 0;
static GLfloat angel = 0;
static GLfloat bally = -70;
static GLfloat ball_x = 0;
static GLfloat ball_y = 0;

int select_part = 0;
static float o_x = 0;
static float o_y = 0;

static GLfloat WIN_WIDTH = 600.0f;
static GLfloat WIN_HEIGHT = 600.0f;
static GLfloat VIEW_WIDTH = 200.0f;
static GLfloat VIEW_HEIGHT = 200.0f;

static DWORD rgbCurrent;
static COLORREF acrCustClr[16];
const int N = 40;

static GLfloat colors[512][3] = {
	{ 0.60, 0.07, 0.07 },//0 background
	{ 0.0, 0.0, 0.0 },//1hair
	{ 0.96, 0.80, 0.59 }, //2face
	{ 1.0, 1.0, 1.0 },//3left eyewhite
	{ 1.0, 1.0, 1.0 },//4right eyewhite
	{ 0.03, 0.03, 0.03 },//5 left eyeblack
	{ 0.03, 0.03, 0.03 },//6 right eyeblack
	{ 0.90, 0.55, 0.10 },//7 nose
	{ 0.70, 0.43, 0.38 },//8 left cheek
	{ 0.70, 0.43, 0.38 },//9 right cheek
	{ 0.94, 0.03, 0.03 },//10 mouth
	{ 0.96, 0.80, 0.59 },//11 left ear
	{ 0.96, 0.80, 0.59 },//12 left ear
	{0.0,1.0,0.0}//13 all of this left is coscolor buffer
};
//draw nose 
void Demon_drawNose(){
	glPushMatrix();
	glTranslatef(nose_x, nose_y, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < N; ++i){
		glVertex2f(4 * cos(2 * M_PI / N*i), 6 + (5 * sin(2 * M_PI / N*i)));
	}

	glEnd();
	glPopMatrix();
}

//draw face
void Demon_drawFace(){
	glBegin(GL_POLYGON);
	for (int i = 0; i < N; ++i){
		glVertex2f(40 * cos(2 * M_PI / N * i), 6 + (40 * sin(2 * M_PI / N * i)));
	}

	glEnd();
}
//draw left white of eye
void Demon_drawLeftWhiteOfEye(){
	glPushMatrix();
	glTranslatef(leftwhiteofeye_x, leftwhiteofeye_y, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < N; ++i){
		glVertex2f(-(14 + (8 * cos(2 * M_PI / N * i))), 26 + (14 * sin(2 * M_PI / N * i)));
	}
	glEnd();
	glPopMatrix();

}
//draw right white of eye
void Demon_drawRightWhiteOfEye(){
	glPushMatrix();
	glTranslatef(rightwhiteofeye_x, rightwhiteofeye_y, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < N; ++i){
		glVertex2f(14 + (8 * cos(2 * M_PI / N * i)), 26 + (14 * sin(2 * M_PI / N * i)));
	}

	glEnd();
	glPopMatrix();

}

//draw left black of eye
void Demon_drawLeftBlackOfEye(){
	glPushMatrix();
	glTranslatef(leftblackofeye_x, leftblackofeye_y, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < N; ++i){
		glVertex2f(leftblackofeyex - (3 * cos(2 * M_PI / N * i)), 26 + (3 * sin(2 * M_PI / N * i)));
	}

	glEnd();
	glPopMatrix();

}
//draw right black of eye
void Demon_drawRightBlackOfEye(){
	glPushMatrix();
	glTranslatef(rightblackofeye_x, rightblackofeye_y, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < N; ++i){
		glVertex2f(rightblackofeyex + (3 * cos(2 * M_PI / N * i)), 26 + (3 * sin(2 * M_PI / N * i)));
	}

	glEnd();
	glPopMatrix();

}
// draw left ear
void Demon_drawLeftEar(){
	glPushMatrix();
	glTranslatef(leftear_x, leftear_y, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(34, 20);
	for (int i = 0; i < N; ++i){
		if ((0.8*sin(2 * M_PI / N*i)) < 0){
			break;
		}
		glVertex2f(40 + 6 * sin(2 * M_PI / N*i), 14 + 6 * cos(2 * M_PI / N*i));
	}
	glVertex2f(40, 8);
	glVertex2f(34, 8);
	glEnd();
	glPopMatrix();
}
// draw right ear
void Demon_drawRightEar(){
	glPushMatrix();
	glTranslatef(rightear_x, rightear_y, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-34, 20);
	for (int i = 0; i < N; ++i){
		if ((0.8*sin(2 * M_PI / N*i)) < 0){
			break;
		}
		glVertex2f(-(40 + 6 * sin(2 * M_PI / N*i)), 14 + 6 * cos(2 * M_PI / N*i));
	}
	glVertex2f(-40, 8);
	glVertex2f(-34, 8);
	glEnd();
	glPopMatrix();
}

//draw mouth
void Demon_drawMouth(){


	glPushMatrix();
	glTranslatef(mouth_x, mouth_y, 0);
	glBegin(GL_POLYGON);//mouth
	for (int i = 0; i < N; ++i){
		if ((sin(2 * M_PI / N*i)) > 0){
			continue;
		}
		glVertex2f(18 * cos(2 * M_PI / N*i), 18 * sin(2 * M_PI / N*i));
	}
	glEnd();
	glPopMatrix();

}

//draw leftcheek
void Demon_drawLeftCheek(){
	glPushMatrix();
	glTranslatef(leftcheek_x, leftcheek_y, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < N; ++i){
		glVertex2f(-24 + (3 * cos(2 * M_PI / N * i)), 8 + (3 * sin(2 * M_PI / N * i)));
	}

	glEnd();
	glPopMatrix();

}
//draw right cheek
void Demon_drawRightCheek(){
	glPushMatrix();
	glTranslatef(rightcheek_x, rightcheek_y, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < N; ++i){
		glVertex2f(24 + (3 * cos(2 * M_PI / N * i)), 8 + (3 * sin(2 * M_PI / N * i)));
	}

	glEnd();
	glPopMatrix();

}
//draw hair
void Demon_drawHair(){
	glPushMatrix();
	glTranslatef(hair_x, hair_y, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0, 58);
	glVertex2f(22, 64);
	glVertex2f(18, 52);
	glVertex2f(40, 38);
	glVertex2f(28, 42);
	glVertex2f(32, 36);
	glVertex2f(0, 46);
	glVertex2f(-32, 36);
	glVertex2f(-28, 42);
	glVertex2f(-40, 38);
	glVertex2f(-18, 52);
	glVertex2f(-22, 64);
	glEnd();
	glPopMatrix();

}

//draw ball  ok! just like ball
void Demon_drawBall(){
	glPushMatrix();
	glTranslatef(ball_x, ball_y, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < N; ++i){
		glVertex2f(90+3 * cos(2 * M_PI / N*i), bally + (3 * sin(2 * M_PI / N*i)));
	}
	glEnd();
	glPopMatrix();
}




//»æÖÆº¯Êý  
void drawObjects(GLenum mode)

{
	glPushMatrix();
	glScalef(1.0, 1.0, 1.0);//Ëõ·Å
	glTranslatef(0, 0, 0);


	if (mode == GL_SELECT)
		glLoadName(LEFTEAR);
	glColor3f(colors[leftear][0], colors[leftear][1], colors[leftear][2]);
	Demon_drawLeftEar();
	if (mode == GL_SELECT)
		glLoadName(RIGHTEAR);
	glColor3f(colors[rightear][0], colors[rightear][1], colors[rightear][2]);
	Demon_drawRightEar();
	if (mode == GL_SELECT)
		glLoadName(FACE);
	glColor3f(colors[face][0], colors[face][1], colors[face][2]);
	Demon_drawFace();
	if (mode == GL_SELECT)
		glLoadName(NOSE);
	glColor3f(colors[nose][0], colors[nose][1], colors[nose][2]);
	Demon_drawNose();
	if (mode == GL_SELECT)
		glLoadName(MOUTH);
	glColor3f(colors[mouth][0], colors[mouth][1], colors[mouth][2]);
	Demon_drawMouth();
	if (mode == GL_SELECT)
		glLoadName(LEFTWHITEOFEYE);
	glColor3f(colors[leftwhiteofeye][0], colors[leftwhiteofeye][1], colors[leftwhiteofeye][2]);
	Demon_drawLeftWhiteOfEye();
	if (mode == GL_SELECT)
		glLoadName(RIGHTWHITEOFEYE);
	glColor3f(colors[rightwhiteofeye][0], colors[rightwhiteofeye][1], colors[rightwhiteofeye][2]);
	Demon_drawRightWhiteOfEye();
	if (mode == GL_SELECT)
		glLoadName(LEFTBLACKOFEYE);
	glColor3f(colors[leftblackofeye][0], colors[leftblackofeye][1], colors[leftblackofeye][2]);
	Demon_drawLeftBlackOfEye();
	if (mode == GL_SELECT)
		glLoadName(RIGHTBLACKOFEYE);
	glColor3f(colors[rightblackofeye][0], colors[rightblackofeye][1], colors[rightblackofeye][2]);
	Demon_drawRightBlackOfEye();
	if (mode == GL_SELECT)
		glLoadName(LEFTCHEEK);
	glColor3f(colors[leftcheek][0], colors[leftcheek][1], colors[leftcheek][2]);
	Demon_drawLeftCheek();
	if (mode == GL_SELECT)
		glLoadName(RIGHTCHEEK);
	glColor3f(colors[rightcheek][0], colors[rightcheek][1], colors[rightcheek][2]);
	Demon_drawRightCheek();
	if (mode == GL_SELECT)
		glLoadName(HAIR);
	glColor3f(colors[hair][0], colors[hair][1], colors[hair][2]);
	Demon_drawHair();
	if (mode == GL_SELECT)
		glLoadName(BALL);
	glColor3f(0.0, 1.0, 0.0);
	Demon_drawBall();

	

	glPopMatrix();
	
}

void myDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(angel, 0.0, 0.0, 1.0);
	drawObjects(GL_RENDER);

	glutSwapBuffers();
}

void myInit(){
	
	glClearColor(0.6, 0.07, 0.07, 1.0);
	glClear(GL_DEPTH_BUFFER_BIT);
	
}

void myRreshape(int w, int h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		gluOrtho2D(-VIEW_WIDTH / 2, VIEW_WIDTH / 2, -VIEW_HEIGHT / 2 * (GLfloat)h / (GLfloat)w,
		VIEW_HEIGHT / 2 * (GLfloat)h / (GLfloat)w);
	else
		gluOrtho2D(-VIEW_WIDTH / 2 * (GLfloat)w / (GLfloat)h, VIEW_WIDTH / 2 *
		(GLfloat)w / (GLfloat)h, -VIEW_HEIGHT / 2, VIEW_HEIGHT / 2);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_BLEND);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_POLYGON_SMOOTH);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
}

void processHits(GLint hits, GLuint buffer[])
{
	unsigned int i, j;
	GLuint names, *ptr;
#ifdef DEBUG
	printf("click total number :%d \n", hits);
#endif // DEBUG	
	ptr = (GLuint *)buffer;
	for (i = 0; i < hits; i++) {
		//  for each hit 
		names = *ptr;
		printf("hit number %d \n", i);
		printf("name stack count is %d\n", *ptr); ptr++;
		printf("min z value is %g \n", (float)*ptr / 0x7FFFFFFF); ptr++;
		printf("max z value is %g \n", (float)*ptr / 0x7FFFFFFF); ptr++;
		for (j = 0; j < names; j++)
		{
			//  for each name
			if (*ptr == 1){
#ifdef DEBUG
				printf("hair\n");
#endif // DEBUG
				select_part = HAIR;
			}
			else if (*ptr == 2){
#ifdef DEBUG
				printf("face\n");
#endif // DEBUG
				select_part = FACE;

			}
			else if (*ptr == 3){
#ifdef DEBUG
				printf("leftwhiteofeye\n");
#endif //DEBUG
				select_part = LEFTWHITEOFEYE;
			}
			else if (*ptr == 4){
#ifdef DEBUG
				printf("rightwhiteofeye\n");
#endif //DEBUG
				select_part = RIGHTWHITEOFEYE;
			}
			else if (*ptr == 5){
#ifdef DEBUG
				printf("leftblackofeye\n");
#endif //DEBUG
				select_part = LEFTBLACKOFEYE;
			}
			else if (*ptr == 6){
#ifdef DEBUG
				printf("rightblackofeye\n");
#endif //DEBUG
				select_part = RIGHTBLACKOFEYE;
			}
			else if (*ptr == 7){
#ifdef DEBUG
				printf("nose\n");
#endif //DEBUG
				select_part = NOSE;
			}
			else if (*ptr == 8){
#ifdef DEBUG
				printf("leftcheek\n");
#endif //DEBUG
				select_part = LEFTCHEEK;
			}
			else if (*ptr == 9){
#ifdef DEBUG
				printf("rightcheek\n");
#endif //DEBUG
				select_part = RIGHTCHEEK;
			}
			else if (*ptr == 10){
#ifdef DEBUG
				printf("mouth\n");
#endif //DEBUG
				select_part = MOUTH;
			}

			else if (*ptr == 11){
#ifdef DEBUG
				printf("leftear\n");
#endif //DEBUG
				select_part = LEFTEAR;
			}
			else if (*ptr == 12){
#ifdef DEBUG
				printf("rightear\n");
#endif //DEBUG
				select_part = RIGHTEAR;
			}
			else if (*ptr == 13){
#ifdef DEBUG
				printf("ball\n");
#endif //DEBUG
				select_part = BALL;
			}
			ptr++;
		}
	}
#ifdef DEBUG
	printf("select_part:%d \n", select_part);
#endif //DEBUG
}

static bool left_down = false;
void myMouseMove(int x, int y){
	if (left_down){
		switch (select_part){
		case MOUTH:
		{ GLfloat m_x = (x - o_x)*VIEW_WIDTH / WIN_WIDTH;
		GLfloat m_y = (o_y - y) *VIEW_WIDTH / WIN_WIDTH;
		mouth_x += m_x*cos(- M_PI*angel / 180) - m_y*sin(-  M_PI*angel / 180);
		mouth_y += m_x*sin(- M_PI*angel / 180) + m_y*cos(- M_PI*angel / 180);
#ifdef DEBUG
		printf("×ì°Í: %f , %f \n", mouth_x, mouth_y);
#endif // DEBUG
		o_x = x;
		o_y = y; }
		break;
		case LEFTWHITEOFEYE:
		{ GLfloat lwe_x = (x - o_x) * VIEW_WIDTH / WIN_WIDTH;
		GLfloat lwe_y = (o_y - y) *VIEW_WIDTH / WIN_WIDTH;
		leftwhiteofeye_x += lwe_x*cos(-2 * M_PI*angel / 360) - lwe_y*sin(-2 * M_PI*angel / 360);
		leftwhiteofeye_y += lwe_x*sin(-2 * M_PI*angel / 360) + lwe_y*cos(-2 * M_PI*angel / 360);
#ifdef DEBUG
		printf("×óÑÛ°×: %f , %f \n", leftwhiteofeye_x, leftwhiteofeye_y);
#endif // DEBUG
		o_x = x;
		o_y = y; }
		break;
		case RIGHTWHITEOFEYE:
		{ GLfloat rwe_x = (x - o_x) *VIEW_WIDTH / WIN_WIDTH;
		GLfloat rwe_y = (o_y - y) * VIEW_WIDTH / WIN_WIDTH;
		rightwhiteofeye_x += rwe_x*cos(-2 * M_PI*angel / 360) - rwe_y*sin(-2 * M_PI*angel / 360);
		rightwhiteofeye_y += rwe_x*sin(-2 * M_PI*angel / 360) + rwe_y*cos(-2 * M_PI*angel / 360);
#ifdef DEBUG
		printf("ÓÒÑÛ°×: %f , %f \n", rightwhiteofeye_x, rightwhiteofeye_y);
#endif // DEBUG
		o_x = x;
		o_y = y; }
		break;
		case LEFTBLACKOFEYE:
		{ GLfloat lbe_x = (x - o_x) *VIEW_WIDTH / WIN_WIDTH;
		GLfloat lbe_y = (o_y - y) *VIEW_WIDTH / WIN_WIDTH;
		leftblackofeye_x += lbe_x*cos(-2 * M_PI*angel / 360) - lbe_y*sin(-2 * M_PI*angel / 360);
		leftblackofeye_y += lbe_x*sin(-2 * M_PI*angel / 360) + lbe_y*cos(-2 * M_PI*angel / 360);
#ifdef DEBUG
		printf("×óÑÛ: %f , %f \n", leftblackofeye_x, leftblackofeye_y);
#endif // DEBUG
		o_x = x;
		o_y = y; }
		break;
		case RIGHTBLACKOFEYE:
		{ GLfloat rbe_x = (x - o_x) *VIEW_WIDTH / WIN_WIDTH;
		GLfloat rbe_y = (o_y - y) * VIEW_WIDTH / WIN_WIDTH;
		rightblackofeye_x += rbe_x*cos(-2 * M_PI*angel / 360) - rbe_y*sin(-2 * M_PI*angel / 360);
		rightblackofeye_y += rbe_x*sin(-2 * M_PI*angel / 360) + rbe_y*cos(-2 * M_PI*angel / 360);
#ifdef DEBUG
		printf("ÓÒÑÛ: %f , %f \n", rightblackofeye_x, rightblackofeye_y);
#endif // DEBUG
		o_x = x;
		o_y = y; }
		break;
		case NOSE:
		{ GLfloat n_x = (x - o_x) *VIEW_WIDTH / WIN_WIDTH;
		GLfloat n_y = (o_y - y) *VIEW_WIDTH / WIN_WIDTH;
		nose_x += n_x*cos(-2 * M_PI*angel / 360) - n_y*sin(-2 * M_PI*angel / 360);
		nose_y += n_x*sin(-2 * M_PI*angel / 360) + n_y*cos(-2 * M_PI*angel / 360);
#ifdef DEBUG
		printf("±Ç×Ó: %f , %f \n", nose_x, nose_y);
#endif // DEBUG
		o_x = x;
		o_y = y; }
		break;
		case LEFTCHEEK:
		{ GLfloat lc_x = (x - o_x) * VIEW_WIDTH / WIN_WIDTH;
		GLfloat lc_y = (o_y - y) *VIEW_WIDTH / WIN_WIDTH;
		leftcheek_x += lc_x*cos(-2 * M_PI*angel / 360) - lc_y*sin(-2 * M_PI*angel / 360);
		leftcheek_y += lc_x*sin(-2 * M_PI*angel / 360) + lc_y*cos(-2 * M_PI*angel / 360);
#ifdef DEBUG
		printf("×óÁ³¼Õ: %f , %f \n", leftcheek_x, leftcheek_y);
#endif // DEBUG
		o_x = x;
		o_y = y; }
		break;
		case RIGHTCHEEK:
		{ GLfloat rc_x = (x - o_x) * VIEW_WIDTH / WIN_WIDTH;
		GLfloat rc_y = (o_y - y) * VIEW_WIDTH / WIN_WIDTH;
		rightcheek_x += rc_x*cos(-2 * M_PI*angel / 360) - rc_y*sin(-2 * M_PI*angel / 360);
		rightcheek_y += rc_x*sin(-2 * M_PI*angel / 360) + rc_y*cos(-2 * M_PI*angel / 360);
#ifdef DEBUG
		printf("ÓÒÁ³¼Õ: %f , %f \n", rightcheek_x, rightcheek_y);
#endif // DEBUG
		o_x = x;
		o_y = y; }
		break;
		case LEFTEAR:
		{ GLfloat le_x = (x - o_x) *VIEW_WIDTH / WIN_WIDTH;
		GLfloat le_y = (o_y - y) * VIEW_WIDTH / WIN_WIDTH;
		leftear_x += le_x*cos(-2 * M_PI*angel / 360) - le_y*sin(-2 * M_PI*angel / 360);
		leftear_y += le_x*sin(-2 * M_PI*angel / 360) + le_y*cos(-2 * M_PI*angel / 360);
#ifdef DEBUG
		printf("×ó¶ú: %f , %f \n", leftear_x, leftear_y);
#endif // DEBUG
		o_x = x;
		o_y = y; }
		break;
		case RIGHTEAR:
		{ GLfloat re_x = (x - o_x) * VIEW_WIDTH / WIN_WIDTH;
		GLfloat re_y = (o_y - y) * VIEW_WIDTH / WIN_WIDTH;
		rightear_x += re_x*cos(-2 * M_PI*angel / 360) - re_y*sin(-2 * M_PI*angel / 360);
		rightear_y += re_x*sin(-2 * M_PI*angel / 360) + re_y*cos(-2 * M_PI*angel / 360);
#ifdef DEBUG
		printf("ÓÒ¶ú: %f , %f \n", rightear_x, rightear_y);
#endif // DEBUG
		o_x = x;
		o_y = y; }
		break;
		case HAIR:
		{ GLfloat h_x = (x - o_x) *VIEW_WIDTH / WIN_WIDTH;
		GLfloat h_y = (o_y - y) *VIEW_WIDTH / WIN_WIDTH;
		hair_x += h_x*cos(-2 * M_PI*angel / 360) - h_y*sin(-2 * M_PI*angel / 360);
		hair_y += h_x*sin(-2 * M_PI*angel / 360) + h_y*cos(-2 * M_PI*angel / 360);
#ifdef DEBUG
		printf("Í··¢: %f , %f \n", hair_x, hair_y);
#endif // DEBUG
		o_x = x;
		o_y = y; }
		break;
		case BALL:
		{ GLfloat b_x = (x - o_x) *VIEW_WIDTH / WIN_WIDTH;
		GLfloat b_y = (o_y - y) * VIEW_WIDTH / WIN_WIDTH;
		ball_x += b_x*cos(-2 * M_PI*angel / 360) - b_y*sin(-2 * M_PI*angel / 360);
		ball_y += b_x*sin(-2 * M_PI*angel / 360) + b_y*cos(-2 * M_PI*angel / 360);
#ifdef DEBUG
		printf("Í··¢: %f , %f \n", hair_x, hair_y);
#endif // DEBUG
		o_x = x;
		o_y = y; }
		break;
		}
		glutPostRedisplay();
	}
}

void myMouse(int button, int state, int x, int y){
	GLuint selectBuf[SIZE];
	GLint hits;
	GLint viewport[4];
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		left_down = true;
		o_x = x;
		o_y = y;
		glGetIntegerv(GL_VIEWPORT, viewport);
		glSelectBuffer(SIZE, selectBuf);
		glRenderMode(GL_SELECT);
		glInitNames();
		glPushName(0);
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluPickMatrix((GLdouble)x, (GLdouble)(viewport[3] - y), 2.0, 2.0, viewport);
		gluOrtho2D(-VIEW_WIDTH / 2, VIEW_WIDTH / 2, -VIEW_HEIGHT / 2, VIEW_HEIGHT / 2);
		drawObjects(GL_SELECT);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		hits = glRenderMode(GL_RENDER);
		processHits(hits, selectBuf);
		glutPostRedisplay();
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		left_down = false;
		glGetIntegerv(GL_VIEWPORT, viewport);
		glSelectBuffer(SIZE, selectBuf);
		glRenderMode(GL_SELECT);
		glInitNames();
		glPushName(0);
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluPickMatrix((GLdouble)x, (GLdouble)(viewport[3] - y), 3.0, 3.0, viewport);
		gluOrtho2D(-VIEW_WIDTH / 2, VIEW_WIDTH / 2, -VIEW_HEIGHT / 2, VIEW_HEIGHT / 2);
		drawObjects(GL_SELECT);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		hits = glRenderMode(GL_RENDER);
		processHits(hits, selectBuf);
		glutPostRedisplay();
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		HWND hwnd=GetActiveWindow();
		CHOOSECOLOR cc;
		memset(&cc, 0, sizeof(cc));
		cc.lStructSize = sizeof(cc);
		cc.hwndOwner = hwnd;
		cc.hInstance = NULL;
		cc.lCustData = NULL;
		cc.lpCustColors = acrCustClr;
		cc.Flags = CC_FULLOPEN | CC_RGBINIT;
		cc.rgbResult = rgbCurrent;
		if (ChooseColor(&cc)){
			rgbCurrent = cc.rgbResult;
			GLfloat red = GLfloat(GetRValue(rgbCurrent))/ 255;
			GLfloat green = GLfloat(GetGValue(rgbCurrent)) / 255;
			GLfloat blue = GLfloat(GetBValue(rgbCurrent)) / 255;
			colors[coscolor][0] = red;
			colors[coscolor][1] = green;
			colors[coscolor][2] = blue;
		}
		switch (select_part) {
		case HAIR:
			hair = coscolor;
			break;
		case FACE:
			face = coscolor;
			break;
		case LEFTWHITEOFEYE:
			leftwhiteofeye = coscolor;
			break;
		case RIGHTWHITEOFEYE:
			rightwhiteofeye = coscolor;
			break;
		case LEFTBLACKOFEYE:
			leftblackofeye = coscolor;
			break;
		case RIGHTBLACKOFEYE:
			rightblackofeye = coscolor;
			break;
		case NOSE:
			nose = coscolor;
			break;
		case LEFTCHEEK:
			leftcheek = coscolor;
			break;
		case RIGHTCHEEK:
			rightcheek = coscolor;
			break;
		case MOUTH:
			mouth = coscolor;
			break;
		case LEFTEAR:
			leftear = coscolor;
			break;
		case RIGHTEAR:
			rightear = coscolor;
			break;
		}
		glutPostRedisplay();
		if (coscolor < 512)
		{
			coscolor++;
		}
		else
		{
			coscolor = 13;
		}
	}
}

void recovery(){
	backgroud = 0;
	hair = 1;
	face = 2;
	leftwhiteofeye = 3;
	rightwhiteofeye = 4;
	leftblackofeye = 5;
	rightblackofeye = 6;
	nose = 7;
	leftcheek = 8;
	rightcheek = 9;
	mouth = 10;
	leftear = 11;
	rightear = 12;
	coscolor = 13;
	nose_x = 0;
	nose_y = 0;
	leftwhiteofeye_x = 0;
	leftwhiteofeye_y = 0;
	rightwhiteofeye_x = 0;
	rightwhiteofeye_y = 0;
	leftear_x = 0;
	leftear_y = 0;
	rightear_x = 0;
	rightear_y = 0;
	leftblackofeye_x = 0;
	leftblackofeye_y = 0;
	rightblackofeye_x = 0;
	rightblackofeye_y = 0;
	leftblackofeyex = -10;
	rightblackofeyex = 18;
	leftcheek_x = 0;
	leftcheek_y = 0;
	rightcheek_x = 0;
	rightcheek_y = 0;
	mouth_x = 0;
	mouth_y = 0;
	hair_x = 0;
	hair_y = 0;
	ball_x = 0;
	ball_y = 0;
	bally = -70;
	angel = 0;
	select_part = 0;
	o_x = 0;
	o_y = 0;
}
void mySpecial(int key, int x, int y){
	switch (key)
	{
	case GLUT_KEY_UP:
		angel = (angel + 8);
#ifdef DEBUG
		printf("angel:%f \n", angel);
#endif // DEBUG
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		angel = (angel - 8);
#ifdef DEBUG
		printf("angel:%f \n", angel);
#endif // DEBUG
		glutPostRedisplay();
		break;
	}
}

void myKeyboard(unsigned char key, int x, int y){
	switch (key)
	{
	case 033:
		exit(EXIT_SUCCESS);
		break;
	case 'i':case'I':
		printf("i");
		recovery();
		glutPostRedisplay();
		break;
	}
}
static bool bottom=false;
static bool top=true;
static bool temptb; 
static bool left = false;
static bool right = true;
static bool templt;
static int timer = 0;
void timeFunc(int id){


	timer = timer +50;
	timer = timer % 2000;
	if (!left&&right){
		leftblackofeyex --;
		rightblackofeyex --;
	}
	if (rightblackofeyex == 10|rightblackofeyex==18)
		{
			templt = left;
			left = right;
			right = templt;
		}
	if (left&&!right){
		leftblackofeyex ++;
		rightblackofeyex ++;
	}
	
	if (!bottom&&top)
		bally = bally -timer*timer/1000/1000;
	if (timer ==0)
	{
		temptb = bottom;
		bottom = top;
		top = temptb;
	}
	if (bottom&&!top)
		bally = bally +  (2000 - timer)*(2000 - timer) / 1000 / 1000;
	
	glutPostRedisplay();
#ifdef TIMER
	printf("bally : %f \n",bally);
	printf("timer : %d \n", timer);
	printf("leftblackofeyex : %f \n", leftblackofeyex);
	printf("rightblackofeyex : %f \n", rightblackofeyex);
#endif // TIMER
	glutTimerFunc(60, timeFunc, id);
}


void main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GL_MULTISAMPLE);
	glutInitWindowSize(WIN_HEIGHT, WIN_WIDTH);
	glutInitWindowPosition(300, 50);
	glutCreateWindow("Íú×Ð");
	glewInit();
	myInit();

	Util::getInfo();

	glutReshapeFunc(myRreshape);
	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);
	glutKeyboardFunc(myKeyboard);
	glutSpecialFunc(mySpecial);
	glutMotionFunc(myMouseMove);
	glutTimerFunc(60, timeFunc, 1);
	glutMainLoop();
}