//////////////////////////////////////////////////////////////////////////////
//  --- Angel.h ---
//   The main header file for all examples from Angel 6th Edition
//////////////////////////////////////////////////////////////////////////////

#ifndef __ANGEL_H__
#define __ANGEL_H__
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

#define Print(x)  do { std::cerr << #x " = " << (x) << std::endl; } while(0)
#endif // __ANGEL_H__