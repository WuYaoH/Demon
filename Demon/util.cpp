#include "Angel.h"
#include "Util.h"

Util::Util()
{
}

Util::~Util()
{
}


//get info about opengl version and GLSL version
void  Util::getInfo(){

	const GLubyte* byteGlVersion = glGetString(GL_VERSION);
	const GLubyte* byteGlVendor = glGetString(GL_VENDOR);
	const GLubyte* byteGlRenderer = glGetString(GL_RENDERER);
	const GLubyte* byteSLVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
	printf("****OpenGL version: %s\n", byteGlVersion);
	printf("****Gl_VENDER: %s\n", byteGlVendor);
	printf("****Gl_RENDERER: %s\n", byteGlRenderer);
	printf("****GLSL_version: %s\n", byteSLVersion);

}
GLchar* Util::readMap(const char* mapFile){

	FILE* fp;
	fopen_s(&fp, mapFile, "r+");
	if (fp == NULL) { return NULL; }
	fseek(fp, 0L, SEEK_END);
	long size = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	char* buf = new char[size + 1];
	fread(buf, 1, size, fp);
	buf[size] = '\0';

	fclose(fp);
	return buf;
}
int Util::saveMap(char mapData[], const char* mapFile){

	FILE* fp;
	fopen_s(&fp, mapFile, "w+");

	if (fp == NULL) {
		return NULL;
	}
	long size = strlen(mapData);
	fwrite(mapData, 1, size, fp);
	fseek(fp, 0L, SEEK_SET);
	char* buf = new char[size + 1];
	fread(buf, 1, size, fp);
	buf[size] = '\0';
	fclose(fp);
	return 0;
}