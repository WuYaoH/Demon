
#include "maze.h"
#include "TestMd2.h"
#include "tga.h"

//#define M_PI 3.141592
#define Maxsize  100
#include <stdlib.h>
extern int map[12][12];
int mapRoad[12][12];
int mapOut[12][12];
int sw, sh, ci, cj, ni, nj, di, dj;
GLint  viewport[4];



void Display(void)
{

	int times;
	times = 100;
	glClearColor(0.0, 0.0, 0.0, 1);
	glClearDepth(1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, 1.0f, 0.1, 1000.0);
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	if (view != 2)
		gluLookAt(xc, yc, zc, xc + lx, yc + ly, zc + lz, .0f, 1.0f, 0.0f);
	else
		gluLookAt(0, 0, 200, 0, 0, 0, .0f, 1.0f, 0.0f);


	glViewport(0, 0, sw, sh);

	glRotatef(x_angle, 1.0, 0.0, 0.0);
	glRotatef(y_angle, 0.0, 1.0, 0.0);

	if (show_frame)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, Decal_Texture);

	glColor3f(1, 1, 1);
	//����ģ��
	glPushMatrix();
	glTranslatef(des1, 0.0f, des2);

	glRotatef(angle * 180 / M_PI, 0, -1, 0);
	glScalef(0.4, 0.4, 0.4);
	glTranslatef(model_center[0] * (-1), minmax[2] * (-1), model_center[2] * (-1));//����ģ������ƽ�Ƶ���������ϵ����
	md2_drawModel(md2_model, current_frame, current_frame + 1, (float)current_subframe / times);//LOOP_FRAME_NUM);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	//�����Թ�
	glPushMatrix();
	if (show_frame)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glColor3f(1, 1, 1);
	drawMaze(view);
	glPopMatrix();


	//����֡����
	current_subframe++;
	if (current_subframe == times)//LOOP_FRAME_NUM)
	{
		current_subframe = 0;
		if (current_frame < MaxFrame)
			current_frame++;
		else {
			MaxFrame = 39;
			current_frame = MinFrame = 0;
		}
		if (current_frame == md2_model->header.numFrames - 1)
			current_frame = 0;

	}
	//����С��ͼ

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 11, 0, 11, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glViewport(screenwidth - 200, screenheight - 200, 200, 200);
	glPushMatrix();
	drawLittleMap();
	glPopMatrix();

	glutSwapBuffers();
}

void orientMe(double ang)
{
	lx = cos(ang);
	lz = sin(ang);
	//	olx=lx;
	//	olz=lz;
	if (view == 0)
	{
		xc = des1 - lx * 40, zc = des2 - lz * 40;
	}

}
void moveMeFlat(int direction)
{
	double a, b;
	xc = xc + direction*(lx);
	zc = zc + direction*(lz);

	if (view == 0)
	{
		a = xc + lx*40.0;
		b = zc + lz*40.0;
		if ((map[myround((110.0 + (a + direction*(lx)*6.4)) / 20.0)][myround((110.0 - (b + direction*(lz)*6.4)) / 20.0)] == 0) &&(map[myround((110.0 + (a + direction*(lz)*6.4)) / 20.0)][myround((110.0 - (b + direction*(lx)*6.4)) / 20.0)] == 0) && (map[myround((110.0 + (a + direction*(lz)*(-6.4))) / 20.0)][myround((110.0 - (b + direction*(lx)*(-6.4))) / 20.0)] == 0))
		{
			des1 = a;
			des2 = b;
			seeRoad();
			//printf("����1\n");
		}
		else
		{
			xc = xc - direction*(lx);
			zc = zc - direction*(lz);
			printf("������1\n");
		}

	}
	else
	{
		if ((map[myround((110.0 + (xc + direction*(lx)*6.4)) / 20.0)][myround((110.0 - (zc + direction*(lz)*6.4)) / 20.0)] == 0) && (map[myround((110.0 + (xc + direction*(lz)*6.4)) / 20.0)][myround((110.0 - (zc + direction*(lx)*6.4)) / 20.0)] == 0) && (map[myround((110.0 + (xc + direction*(lz)*(-6.4))) / 20.0)][myround((110.0 - (zc + direction*(lx)*(-6.4))) / 20.0)] == 0))
		{
			des1 = xc;
			des2 = zc;
			seeRoad();
			//printf("����2\n");
		}
		else
		{//printf("aaaaaaa %d %d \n",map[myround((110.0+(xc+direction*(lx)*6.4))/20.0)][myround((110.0-(zc+direction*(lz)*6.4))/20.0)],map[myround((110.0+(xc+direction*(lz)*6.4))/20.0)][myround((110.0-(zc+direction*(lx)*6.4))/20.0)]);
			xc = xc - direction*(lx);
			zc = zc - direction*(lz);

			printf("������2\n");
		}

	}
}
void Keyboard(unsigned char key, int x, int y)
{

	switch (key)
	{

	case 'w':
	{
		if (view != 2)
		{

			if (MinFrame != 40 && MaxFrame != 45)
			{
				current_frame = MinFrame = 40;
				MaxFrame = 45;
			}
			moveMeFlat(1);
		}

		break;
	}
	case 'a':
	{

		if (view != 2)
		{
			angle -= M_PI / 100.0;
			orientMe(angle);
		}
		break;
	}

	case 'd':
	{
		if (view != 2)
		{
			angle += M_PI / 100.0;
			orientMe(angle);
		}
		break;
	}
	case 's':
	{
		if (view != 2)
		{
			if (MinFrame != 40 && MaxFrame != 45)
			{
				current_frame = MinFrame = 40;
				MaxFrame = 45;
			}
			moveMeFlat(-1);
		}

		break;
	}
	case 'f':
	{
		show_frame = !show_frame;
		break;
	}
	case 'c':
	{
		view++;
		if (view == 1)

		{
			xc = des1; yc = minmax[3], zc = des2;
			//lx=olx;ly=oly;lz=olz;
			x_angle = 0.0f;
			y_angle = 0.0f;
			sw = screenwidth;
			sh = screenheight;


		}
		if (view == 2)
		{
			xc = des1; yc = minmax[3], zc = des2;
			//lx=olx;ly=oly;lz=olz;
			x_angle = 90.0f;
			y_angle = 0.0f;
			sw = screenwidth * 3 / 4;
			sh = screenheight * 3 / 4;

		}
		if (view == 3)

		{
			view = 0;
			xc = des1 - lx * 40, yc = minmax[3], zc = des2 - lz * 40;
			//lx=olx;ly=oly;lz=olz;
			x_angle = 0.0f;
			y_angle = 0.0f;
			sw = screenwidth;
			sh = screenheight;
		}
		break;
	}
	case 32:
	{
		autoRun = false;
		break;
	}
	case 'q':
	{
		exit(0);
		break;
	}
	case '1'://standing
	{
		current_frame = MinFrame = 0;
		MaxFrame = 39;
		break;
	}
	case '2'://running
	{
		if (MinFrame != 40 && MaxFrame != 45)
		{
			current_frame = MinFrame = 40;
			MaxFrame = 45;
		}
		break;
	}
	case '3'://attacking
	{
		if (MinFrame != 46 && MaxFrame != 53)
		{
			current_frame = MinFrame = 46;
			MaxFrame = 53;
		}
		break;
	}
	case '4'://pain
	{
		if (MinFrame != 54 && MaxFrame != 65)
		{
			current_frame = MinFrame = 54;
			MaxFrame = 65;
		}
		break;
	}
	case '5'://jumping
	{
		if (MinFrame != 66 && MaxFrame != 71)
		{
			current_frame = MinFrame = 66;
			MaxFrame = 71;
		}
		break;
	}
	case '6'://fliping
	{
		if (MinFrame != 72 && MaxFrame != 83)
		{
			current_frame = MinFrame = 72;
			MaxFrame = 83;
		}
		break;
	}
	case '7'://attacking
	{
		if (MinFrame != 46 && MaxFrame != 53)
		{
			current_frame = MinFrame = 46;
			MaxFrame = 53;
		}
		break;
	}
	case '8'://salute
	{
		if (MinFrame != 84 && MaxFrame != 94)
		{
			current_frame = MinFrame = 84;
			MaxFrame = 94;
		}
		break;
	}
	case '9'://taunt
	{
		if (MinFrame != 95 && MaxFrame != 111)
		{
			current_frame = MinFrame = 95;
			MaxFrame = 111;
		}
		break;
	}
	case '0'://wave
	{
		if (MinFrame != 112 && MaxFrame != 122)
		{
			current_frame = MinFrame = 112;
			MaxFrame = 122;
		}
		break;
	}

	}
}

void SpecialKeys(int key, int x, int y)
{

	if (view == 2)
	{
		switch (key)
		{
		case GLUT_KEY_LEFT:
		{
			y_angle -= DELTA_ANGLE;
			//glRotatef(DELTA_ANGLE, 0.0, 1.0, 0.0);
			break;
		}
		case GLUT_KEY_RIGHT:
		{
			y_angle += DELTA_ANGLE;
			//glRotatef(-DELTA_ANGLE, 0.0, 1.0, 0.0);
			break;
		}
		case GLUT_KEY_UP:
		{
			x_angle -= DELTA_ANGLE;
			//glRotatef(-DELTA_ANGLE, 1.0, 0.0, 0.0);
			break;
		}
		case GLUT_KEY_DOWN:
		{
			x_angle += DELTA_ANGLE;
			//glRotatef(DELTA_ANGLE, 1.0, 0.0, 0.0);
			break;
		}
		}
	}
}
bool LoadTexture(char *TexName, GLuint TexHandle)
{
	TGAImg Img;        // Image loader

	// Load our Texture
	if (Img.Load(TexName) != IMG_OK)
		return false;

	glBindTexture(GL_TEXTURE_2D, TexHandle); // Set our Tex handle as current

	// Create the texture
	if (Img.GetBPP() == 24)
		glTexImage2D(GL_TEXTURE_2D, 0, 3, Img.GetWidth(), Img.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, Img.GetImg());
	else if (Img.GetBPP() == 32)
		glTexImage2D(GL_TEXTURE_2D, 0, 4, Img.GetWidth(), Img.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, Img.GetImg());
	else
		return false;

	// Specify filtering and edge actions
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	return true;
}


void LoadModel()
{
	// load 3D information of the model knight.md2
	md2_model = md2_readModel("..\\data\\Knight.md2");

	md2_getBoundingBox(md2_model, minmax);

	model_center[0] = (minmax[0] + minmax[1]) / 2.0f;
	model_center[1] = (minmax[2] + minmax[3]) / 2.0f;
	model_center[2] = (minmax[4] + minmax[5]) / 2.0f;
	model_radius = sqrt((minmax[0] - minmax[1]) * (minmax[0] - minmax[1]) +
		(minmax[2] - minmax[3]) * (minmax[2] - minmax[3]) +
		(minmax[4] - minmax[5]) * (minmax[4] - minmax[5])) / 2.0;

	Decal_Texture = 2;
	LoadTexture("..\\data\\GenericMech.TGA", Decal_Texture);
	Decal_Texture1 = 1;
	LoadTexture("..\\data\\war3mapmap.TGA", Decal_Texture1);
	Decal_Texture2 = 3;
	LoadTexture("..\\data\\brick.TGA", Decal_Texture2);
	Decal_Texture3 = 4;
	LoadTexture("..\\data\\littlebrick.TGA", Decal_Texture3);
	Decal_Texture4 = 5;
	LoadTexture("..\\data\\01.TGA", Decal_Texture4);
	Decal_Texture5 = 6;
	LoadTexture("..\\data\\001.TGA", Decal_Texture5);

	des1 = -90.0;
	des2 = 90.0;
	//olx=1;oly=0;olz=0;
	seeRoad();
	current_subframe = 0;
	xc = des1; yc = minmax[3], zc = des2;
	//lx=olx;ly=oly;lz=olz;
	lx = 1; ly = 0; lz = 0;


}
void changeSize(int w, int h)
{
	if (w>h)
		screenwidth = screenheight = h;
	else
		screenwidth = screenheight = w;
	sw = screenwidth * 3 / 4;
	sh = screenheight * 3 / 4;
	glViewport(0, 0, sw, sh);
}

void myMouse(int btn, int state, int x, int y)
{
	int i, j;

	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN && view == 2)
	{
		GLdouble modelview[16];
		GLdouble projection[16];
		GLfloat  winX, winY, winZ;
		GLdouble posX, posY, posZ;

		glPushMatrix();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(70, 1.0f, 0.1, 1000.0);
		glMatrixMode(GL_MODELVIEW);

		glLoadIdentity();

		gluLookAt(0, 0, 200, 0, 0, 0, .0f, 1.0f, 0.0f);
		glViewport(0, 0, sw, sh);
		glRotatef(x_angle, 1.0, 0.0, 0.0);
		glRotatef(y_angle, 0.0, 1.0, 0.0);
		glGetIntegerv(GL_VIEWPORT, viewport);
		glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
		glGetDoublev(GL_PROJECTION_MATRIX, projection);

		glPopMatrix();

		winX = x;
		winY = screenheight - y;
		if ((winX>sw) || (winY>sh))
			return;
		glReadPixels((int)winX, (int)winY, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
		gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);
		i = myround((110.0 + posX) / 20.0);
		j = myround((110.0 - posZ) / 20.0);

		int mod;
		mod = glutGetModifiers();
		if (mod == GLUT_ACTIVE_CTRL)
		{

			if (((i == myround((110.0 + des1) / 20.0)) && (j == myround((110.0 - des2) / 20.0))) || ((i == 10) && (j == 10)))
				return;

			if (map[i][j] == 0)
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
		else
		{
			//����ij�Զ�Ѱ·			
			autoRun = true;
			moveTo(i, j);
		}
	}
}
void moveTo(int i, int j)
{

	if (i<1 || i>10 || j<1 || j>10)
	{
		printf("�����߽� \n");
		return;
	}
	di = i;
	dj = j;
	ci = myround((110.0 + des1) / 20.0);
	cj = myround((110.0 - des2) / 20.0);
	getRoad(ci, cj, di, dj);
	if (ni != -1 && nj != -1)
	{
		if (view == 0)
		{
			des1 = ci*20.0 - 110.0;//������cell����
			des2 = 110.0 - cj*20.0;
			xc = des1 - lx*40.0;
			zc = des2 - lz*40.0;
		}
		else
		{
			des1 = xc = ci*20.0 - 110.0;//������cell����
			des2 = zc = 110.0 - cj*20.0;
		}

		move(1);
	}
}
STACK Stack[Maxsize], Path[Maxsize];

void getRoad(int x1, int y1, int x2, int y2)
{
	for (int p = 0; p<12; p++)
	{
		for (int q = 0; q<12; q++)
		{
			mapRoad[p][q] = map[p][q];
		}
	}
	if ((x1 == x2&&y1 == y2) || mapRoad[x2][y2] == 1)
	{
		ni = -1;
		nj = -1;
		return;
	}
	Path[1].i = -1;
	Path[1].j = -1;

	int top = -1;//ջ��ָ�븳ֵ
	//int count=1;//·������
	int Minlength = Maxsize;//�ȳ�ʼ�����ȣ��ڳ������޸�
	int i, j, ddi, find;
	top++;//ָ��ջ��Ԫ����һ��
	Stack[top].i = x1;
	Stack[top].j = y1;
	Stack[top].ddi = -1;//��һ�����ߵ�·��ջԪ��
	mapRoad[x1][y1] = -1;//���·��

	while (top>-1)//ջ����
	{
		i = Stack[top].i;
		j = Stack[top].j;
		ddi = Stack[top].ddi;//��ǰ��λ�ã���ʱtopָ��ջ��Ԫ��
		if (i == x2&&j == y2)//������ʱ
		{
			if (top + 1<Minlength)//���������·��ʱ,�����ҵ���·����ŵ�Path������
			{
				for (int k = 0; k <= top; k++)
				{
					Path[k] = Stack[k];
					Minlength = top + 1;//�޸���̳��ȵ�ֵ
				}
				mapRoad[Stack[top].i][Stack[top].j] = 0;//Ϊ������·����ԭ�õ�
				top--;//��ջ
				i = Stack[top].i;//�¸���ǰλ��
				j = Stack[top].j;
				ddi = Stack[top].ddi;
			}
		}//�˳�ifʱ��ʼ���¸�·��
		find = 0;//��ʼ������ǰԪ���Ѿ���ջ�����¸�Ԫ��
		while (ddi<4 && find == 0)
		{
			ddi++;
			switch (ddi)
			{
			case 0:i = Stack[top].i - 1; j = Stack[top].j;   break;//��
			case 1:i = Stack[top].i; j = Stack[top].j + 1; break;//��
			case 2:i = Stack[top].i + 1; j = Stack[top].j;   break;//��
			case 3:i = Stack[top].i; j = Stack[top].j - 1; break;//��
			}
			if (mapRoad[i][j] == 0) find = 1;//·����
		}
		if (find == 1)//·����ʱ
		{
			Stack[top].ddi = ddi;//�޸ĸĵ����һ��Ѱ�ҵĿ�ʼ����Ϊ�Ժ������
			top++;//�ÿ��ߵ�·��ջ
			Stack[top].i = i;
			Stack[top].j = j;
			Stack[top].ddi = -1;//�����ͷ��ʼ
			mapRoad[i][j] = -1;//���·����
		}
		else//δ�ҵ�·,��ջ
		{
			mapRoad[Stack[top].i][Stack[top].j] = 0;//�õ�ǰ��ջ��·������·������,di�Ѿ��ı䣬�����ظ���
			top--;//��ջ
		}
	}
	ni = Path[1].i;
	nj = Path[1].j;
}
void move(int value)
{

	if (value == 1)
	{
		if ((lx*(cj - nj) + lz*(ci - ni))>0)
		{
			angle += M_PI / 100.0;
		}
		if ((lx*(cj - nj) + lz*(ci - ni))<0)
			angle -= M_PI / 100.0;
		if ((lx*(cj - nj) + lz*(ci - ni)) == 0)
		{
			if (lx*(ni - ci) + lz*(cj - nj)<0)

				angle -= M_PI / 100.0;
		}
		orientMe(angle);
		printf("�Ƕ� %f %f %f %f %f \n", lx, lz, double(ni - ci), double(cj - nj), angle);

		if (fabs(lx - double(ni - ci))>0.0001 || fabs(lz - double(cj - nj))>0.0001)
		{
			glutTimerFunc(25, move, 1);
		}
		else
		{
			lx = double(ni - ci);//�����Ƕ�
			lz = double(cj - nj);
			//olx=lx;
			//olz=lz;
			if (lx == 0 && lz == 1)
				angle = M_PI / 2;
			if (lx == 0 && lz == -1)
				angle = -M_PI / 2;
			if (lx == 1 && lz == 0)
				angle = 0.0;
			if (lx == -1 && lz == 0)
				angle = M_PI;
			printf("���� %f %f %d %d %f \n", lx, lz, ni - ci, cj - nj, angle);
			if (view == 0)
			{
				xc = des1 - lx * 40, zc = des2 - lz * 40;
			}
			move(2);
		}
	}
	if (value == 2)
	{
		if (MinFrame != 40 && MaxFrame != 45)
		{
			current_frame = MinFrame = 40;
			MaxFrame = 45;
		}
		moveMeFlat(1);
		if (des1 != (20 * ni - 110) || des2 != (110 - 20 * nj))
		{
			glutTimerFunc(50, move, 2);
		}
		else
		{
			ci = ni;
			cj = nj;

			getRoad(ci, cj, di, dj);
			printf("%d %d %d %d %d %d \n", ci, cj, ni, nj, di, dj);
			if ((ci != di || cj != dj) && autoRun&&ni != -1 && nj != -1)
			{
				move(1);
			}
			else
				printf("�Զ�Ѱ·����\n");
		}
	}


}
void Initialize()
{

	x_angle = 90.0f;
	y_angle = 0.0f;
	view = 2;
	angle = 0.0f;

	sw = screenwidth * 3 / 4;
	sh = screenheight * 3 / 4;
}
int myround(double m)
{
	int a;
	a = (m - int(m)<0.5) ? int(m) : int(m) + 1;
	return a;
}
inline void seeRoad()
{
	int a, b;
	a = myround((110.0 + des1) / 20.0);
	b = myround((110.0 - des2) / 20.0);
	mapOut[a - 1][b - 1] = mapOut[a - 1][b] = mapOut[a - 1][b + 1] = mapOut[a][b - 1] = mapOut[a][b] = mapOut[a][b + 1] = mapOut[a + 1][b - 1] = mapOut[a + 1][b] = mapOut[a + 1][b + 1] = 1;
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	screenwidth = screenheight = 600;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	Initialize();
	glutInitWindowSize(screenwidth, screenheight);
	glutCreateWindow("MAZE");
	glutDisplayFunc(Display);

	glutReshapeFunc(changeSize);
	glutIdleFunc(Display);
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(myMouse);
	glutSpecialFunc(SpecialKeys);
	show_frame = false;
	LoadModel();
	glutMainLoop();

	return 0;
}
