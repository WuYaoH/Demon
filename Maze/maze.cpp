#include "maze.h"
#define M_PI 3.14159
extern float des1, des2;
GLuint Decal_Texture5, Decal_Texture4, Decal_Texture3, Decal_Texture2, Decal_Texture1;

int	map[12][12] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
	{ 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1 },
	{ 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1 },
	{ 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1 },
	{ 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1 },
	{ 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

void drawMaze(int model)
{
	//绘制地面		
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Decal_Texture1);
	glBegin(GL_QUADS);

	glTexCoord2i(0, 1); glVertex3f(-100.0f, 0, 100.0f);
	glTexCoord2i(1, 1); glVertex3f(-100.0f, 0, -100.0f);
	glTexCoord2i(1, 0); glVertex3f(100.0f, 0, -100.0f);
	glTexCoord2i(0, 0); glVertex3f(100.0f, 0, 100.0f);


	glEnd();
	glDisable(GL_TEXTURE_2D);

	if (model == 2)
	{
		float x, z;
		//绘制网格
		glColor3d(1, 0, 0);
		glBegin(GL_LINES);

		for (x = -100; x <= 100; x += 20){

			glVertex3f(x, 1, -100);
			glVertex3f(x, 1, 100);
		}
		for (z = -100; z <= 100; z += 20){

			glVertex3f(-100, 1, z);
			glVertex3f(100, 1, z);
		}
		glEnd();
	}

	//绘制障碍物
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Decal_Texture2);
	glColor3d(1, 1, 1);
	int x, z;
	for (x = 1; x<11; x++)
	{
		for (z = 1; z<11; z++)
		{
			if (map[x][z] == 1)
			{
				glPushMatrix();
				glTranslatef(20.0*x - 110.0, 10.0f, 110.0 - 20.0*z);
				//glutSolidCube(20.0);
				glBegin(GL_QUADS);
				//面一
				glTexCoord2i(0, 0); glVertex3f(-10, -10, 10);
				glTexCoord2i(0, 1); glVertex3f(-10, 10, 10);
				glTexCoord2i(1, 1); glVertex3f(10, 10, 10);
				glTexCoord2i(1, 0); glVertex3f(10, -10, 10);
				//面二
				glTexCoord2i(0, 1); glVertex3f(10, -10, 10);
				glTexCoord2i(1, 1); glVertex3f(10, 10, 10);
				glTexCoord2i(1, 0); glVertex3f(10, 10, -10);
				glTexCoord2i(0, 0); glVertex3f(10, -10, -10);
				//面三
				glTexCoord2i(0, 0); glVertex3f(10, -10, -10);
				glTexCoord2i(0, 1); glVertex3f(10, 10, -10);
				glTexCoord2i(1, 1); glVertex3f(-10, 10, -10);
				glTexCoord2i(1, 0); glVertex3f(-10, -10, -10);
				//面四
				glTexCoord2i(0, 0); glVertex3f(-10, -10, -10);
				glTexCoord2i(0, 1); glVertex3f(-10, 10, -10);
				glTexCoord2i(1, 1); glVertex3f(-10, 10, 10);
				glTexCoord2i(1, 0); glVertex3f(-10, -10, 10);
				//面五
				glTexCoord2i(0, 0); glVertex3f(-10, 10, 10);
				glTexCoord2i(0, 1); glVertex3f(-10, 10, -10);
				glTexCoord2i(1, 1); glVertex3f(10, 10, -10);
				glTexCoord2i(1, 0); glVertex3f(10, 10, 10);
				//面六
				glTexCoord2i(0, 0); glVertex3f(-10, -10, 10);
				glTexCoord2i(0, 1); glVertex3f(10, -10, 10);
				glTexCoord2i(1, 1); glVertex3f(10, -10, -10);
				glTexCoord2i(1, 0); glVertex3f(-10, -10, -10);
				glEnd();
				glPopMatrix();
			}
		}
	}

	//绘制终点
	glColor3d(1, 1, 1);
	glPushMatrix();
	glTranslatef(90, 10, -90);
	glBindTexture(GL_TEXTURE_2D, Decal_Texture4);
	//glutSolidCube(20.0);
	glBegin(GL_QUADS);
	//面一
	glTexCoord2i(1, 1); glVertex3f(-10, -10, 10);
	glTexCoord2i(1, 0); glVertex3f(-10, 10, 10);
	glTexCoord2i(0, 0); glVertex3f(10, 10, 10);
	glTexCoord2i(0, 1); glVertex3f(10, -10, 10);
	//面二
	glTexCoord2i(1, 1); glVertex3f(10, -10, 10);
	glTexCoord2i(1, 0); glVertex3f(10, 10, 10);
	glTexCoord2i(0, 0); glVertex3f(10, 10, -10);
	glTexCoord2i(0, 1); glVertex3f(10, -10, -10);
	//面三
	glTexCoord2i(1, 1); glVertex3f(10, -10, -10);
	glTexCoord2i(1, 0); glVertex3f(10, 10, -10);
	glTexCoord2i(0, 0); glVertex3f(-10, 10, -10);
	glTexCoord2i(0, 1); glVertex3f(-10, -10, -10);
	//面四
	glTexCoord2i(1, 1); glVertex3f(-10, -10, -10);
	glTexCoord2i(1, 0); glVertex3f(-10, 10, -10);
	glTexCoord2i(0, 0); glVertex3f(-10, 10, 10);
	glTexCoord2i(0, 1); glVertex3f(-10, -10, 10);
	//面五
	glTexCoord2i(0, 1); glVertex3f(-10, 10, 10);
	glTexCoord2i(1, 1); glVertex3f(-10, 10, -10);
	glTexCoord2i(1, 0); glVertex3f(10, 10, -10);
	glTexCoord2i(0, 0); glVertex3f(10, 10, 10);
	//面六
	glTexCoord2i(0, 0); glVertex3f(-10, -10, 10);
	glTexCoord2i(0, 1); glVertex3f(10, -10, 10);
	glTexCoord2i(1, 1); glVertex3f(10, -10, -10);
	glTexCoord2i(1, 0); glVertex3f(-10, -10, -10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();


}

void drawLittleMap()
{
	float x, z, m, n;
	//绘制地图
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Decal_Texture1);
	glColor3d(1, 1, 1);
	glBegin(GL_QUADS);
	glTexCoord2i(0, 1); glVertex3f(0.5, 0.5, 0);
	glTexCoord2i(1, 1); glVertex3f(0.5, 10.5, 0);
	glTexCoord2i(1, 0); glVertex3f(10.5, 10.5, 0);
	glTexCoord2i(0, 0); glVertex3f(10.5, 0.5, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//绘制网格
	glColor3d(1, 0, 0);
	glBegin(GL_LINES);

	for (x = 0.5; x <= 10.5; x += 1){
		glVertex3f(x, 0.5, 0.5);
		glVertex3f(x, 10.5, 0.5);
	}
	for (z = 0.5; z <= 10.5; z += 1){
		glVertex3f(0.5, z, 0.5);
		glVertex3f(10.5, z, 0.5);
	}
	glEnd();
	//绘制障碍物
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Decal_Texture3);
	glColor3d(0.5, 0.5, .5);
	int p, q;
	for (p = 1; p<11; p++)
	{
		for (q = 1; q<11; q++)
		{
			if (map[p][q] == 1 && mapOut[p][q] == 1)
			{
				glPushMatrix();
				glTranslatef(p, q, 1);
				//glutSolidCube(1.0);
				glBegin(GL_QUADS);
				//面一
				glTexCoord2i(0, 0); glVertex3f(-0.5, -0.5, 0.5);
				glTexCoord2i(0, 1); glVertex3f(-0.5, 0.5, 0.5);
				glTexCoord2i(1, 1); glVertex3f(0.5, 0.5, 0.5);
				glTexCoord2i(1, 0); glVertex3f(0.5, -0.5, 0.5);
				//面二
				glTexCoord2i(0, 0); glVertex3f(0.5, -0.5, 0.5);
				glTexCoord2i(0, 1); glVertex3f(0.5, 0.5, 0.5);
				glTexCoord2i(1, 1); glVertex3f(0.5, 0.5, -0.5);
				glTexCoord2i(1, 0); glVertex3f(0.5, -0.5, -0.5);
				//面三
				glTexCoord2i(0, 0); glVertex3f(0.5, -0.5, -0.5);
				glTexCoord2i(0, 1); glVertex3f(0.5, 0.5, -0.5);
				glTexCoord2i(1, 1); glVertex3f(-0.5, 0.5, -0.5);
				glTexCoord2i(1, 0); glVertex3f(-0.5, -0.5, -0.5);
				//面四
				glTexCoord2i(0, 0); glVertex3f(-0.5, -0.5, -0.5);
				glTexCoord2i(0, 1); glVertex3f(-0.5, 0.5, -0.5);
				glTexCoord2i(1, 1); glVertex3f(-0.5, 0.5, 0.5);
				glTexCoord2i(1, 0); glVertex3f(-0.5, -0.5, 0.5);
				//面五
				glTexCoord2i(0, 0); glVertex3f(-0.5, 0.5, 0.5);
				glTexCoord2i(0, 1); glVertex3f(-0.5, 0.5, -0.5);
				glTexCoord2i(1, 1); glVertex3f(0.5, 0.5, -0.5);
				glTexCoord2i(1, 0); glVertex3f(0.5, 0.5, 0.5);
				//面六
				glTexCoord2i(0, 0); glVertex3f(-0.5, -0.5, 0.5);
				glTexCoord2i(0, 1); glVertex3f(0.5, -0.5, 0.5);
				glTexCoord2i(1, 1); glVertex3f(0.5, -0.5, -0.5);
				glTexCoord2i(1, 0); glVertex3f(-0.5, -0.5, -0.5);
				glEnd();
				glPopMatrix();
			}
		}
	}

	//绘制终点
	glBindTexture(GL_TEXTURE_2D, Decal_Texture5);
	if (mapOut[10][10] == 1)
	{
		glColor3d(1, 1, 1);
		glPushMatrix();
		glTranslatef(10, 10, 0);
		//glutSolidCube(1.0);
		glBegin(GL_QUADS);
		//面一
		glTexCoord2i(0, 0); glVertex3f(-0.5, -0.5, 0.5);
		glTexCoord2i(0, 1); glVertex3f(-0.5, 0.5, 0.5);
		glTexCoord2i(1, 1); glVertex3f(0.5, 0.5, 0.5);
		glTexCoord2i(1, 0); glVertex3f(0.5, -0.5, 0.5);
		//面二
		glTexCoord2i(0, 0); glVertex3f(0.5, -0.5, 0.5);
		glTexCoord2i(0, 1); glVertex3f(0.5, 0.5, 0.5);
		glTexCoord2i(1, 1); glVertex3f(0.5, 0.5, -0.5);
		glTexCoord2i(1, 0); glVertex3f(0.5, -0.5, -0.5);
		//面三
		glTexCoord2i(0, 0); glVertex3f(0.5, -0.5, -0.5);
		glTexCoord2i(0, 1); glVertex3f(0.5, 0.5, -0.5);
		glTexCoord2i(1, 1); glVertex3f(-0.5, 0.5, -0.5);
		glTexCoord2i(1, 0); glVertex3f(-0.5, -0.5, -0.5);
		//面四
		glTexCoord2i(0, 0); glVertex3f(-0.5, -0.5, -0.5);
		glTexCoord2i(0, 1); glVertex3f(-0.5, 0.5, -0.5);
		glTexCoord2i(1, 1); glVertex3f(-0.5, 0.5, 0.5);
		glTexCoord2i(1, 0); glVertex3f(-0.5, -0.5, 0.5);
		//面五
		glTexCoord2i(1, 1); glVertex3f(-0.5, 0.5, 0.5);
		glTexCoord2i(1, 0); glVertex3f(-0.5, 0.5, -0.5);
		glTexCoord2i(0, 0); glVertex3f(0.5, 0.5, -0.5);
		glTexCoord2i(0, 1); glVertex3f(0.5, 0.5, 0.5);
		//面六
		glTexCoord2i(0, 0); glVertex3f(-0.5, -0.5, 0.5);
		glTexCoord2i(0, 1); glVertex3f(0.5, -0.5, 0.5);
		glTexCoord2i(1, 1); glVertex3f(0.5, -0.5, -0.5);
		glTexCoord2i(1, 0); glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		glPopMatrix();
	}
	glDisable(GL_TEXTURE_2D);


	//绘制位置
	glColor3d(1, 1, 1);
	float R = 0.4;
	glTranslatef((110.0 + des1) / 20.0, (110.0 - des2) / 20.0, 2.0f);
	glBegin(GL_POLYGON);
	for (float d = 0; d <= 2 * M_PI; d += 0.1)
	{
		m = R*cos(d);
		n = R*sin(d);
		glVertex3f(m, n, 1);
	}
	glEnd();
}