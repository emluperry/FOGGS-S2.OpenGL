#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"

#include <fstream>
#include <iostream>
#include <sstream>

struct bmp_color
{
	unsigned char b, g, r;
};

class Texture2D
{
private:
	GLuint _ID;
	int _width, _height;
public:
	Texture2D();
	~Texture2D();

	bool Load(char* path, int width, int height);
	bool LoadBmp(char* path);
	bool LoadTga(char* path);

	GLuint GetId() const { return _ID; }
	int GetWidth() const { return _width; }
	int GetHeight() const { return _height; }
};

