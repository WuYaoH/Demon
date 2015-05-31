#include <iostream>
#include <exception>

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include "md2.h"


#define DELTA_ANGLE 1.0f
float minmax[6];
int screenwidth, screenheight, view;
float x_angle, y_angle, des1, des2;
static GLuint* pIndices = 0;
static GLfloat* pVertex
;
static GLvoid* pPixels;//pixel data
float height_map[128][128];//height map
static GLsizei count;
static GLuint terrainTexture;
float width, height;
bool show_frame, autoRun;
double xc, yc, zc, angle;
double lx, ly, lz;
//,olx,oly,olz;

GLuint Decal_Texture;
extern GLuint Decal_Texture5, Decal_Texture4, Decal_Texture3, Decal_Texture2, Decal_Texture1;
md2_model_t* md2_model;
md2_model_t* md2_model_2;
float model_center[3], model_radius;
int current_frame, current_subframe, MaxFrame = 39, MinFrame = 1;
int knight1 = 95, knight2 = 85;
typedef struct stack{
	int i;//x×ø±ê
	int j;//y×ø±ê
	int ddi;
}STACK;


int myround(double m);
void Initialize();
void Display(void);
void Keyboard(unsigned char key, int x, int y);
bool LoadTexture(char *TexName, GLuint TexHandle);
void LoadModel();
inline void seeRoad();
void getRoad(int x1, int y1, int x2, int y2);
void moveTo(int i, int j);
void move(int value);