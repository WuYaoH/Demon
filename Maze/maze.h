// --- Include system headers ---
#include <Windows.h>
#include <iostream>

//  Define M_PI in the case it's not defined in the math header file
#ifndef M_PI
#define M_PI  3.14159265358979323846
#endif

// --- Include OpenGL header files and helpers ---
#define GLEW_STATIC
#include <GL\glew.h>
#define FREEGLUT_STATIC
#include <GL\freeglut.h>


#ifdef _MSC_VER
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib,"glew32s.lib")
#pragma comment(lib,"freeglut_staticd.lib")
#endif
#include <GL/glut.h>
#include <stdio.h>
#include<stdlib.h>
#include <math.h>
extern int mapOut[12][12];
void drawMaze(int model);
void drawLittleMap();