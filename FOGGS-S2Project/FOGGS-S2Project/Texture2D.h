#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GL\glext.h"

#include <fstream>
#include <iostream>
#include <sstream>

class Texture2D
{
private:
	GLuint _ID;
	int _width, _height;

	char* LoadRaw(char* path, int width, int height);
	char* LoadBmp(char* path);
	char* LoadTga(char* path, char &mode);
public:
	Texture2D();
	~Texture2D();

	bool LoadTexture(std::string path, int width = -1, int height = -1);
	bool LoadSkybox(std::string path, int width = -1, int height = -1);

	GLuint GetId() const { return _ID; }
	int GetWidth() const { return _width; }
	int GetHeight() const { return _height; }
};

