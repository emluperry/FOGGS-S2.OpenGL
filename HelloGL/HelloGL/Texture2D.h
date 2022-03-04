#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"

#include <fstream>
#include <iostream>
#include <sstream>

struct bmpFile_type
{
	unsigned char magic[2];
};

struct bmpFile_header
{
	uint32_t filesz;
	uint16_t creator1;
	uint16_t creator2;
	uint32_t bmp_offset;
};

struct bmp_infoheader
{
	uint32_t header_sz;
	int32_t width;
	int32_t height;
	uint16_t nplanes;
	uint16_t bitspp;
	uint32_t compress_type;
	uint32_t bmp_bytesz;
	int32_t hres;
	int32_t vres;
	uint32_t ncolors;
	uint32_t nimpcolors;
};

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
	bool LoadBmp(char* path, int width, int height);

	GLuint GetId() const { return _ID; }
	int GetWidth() const { return _width; }
	int GetHeight() const { return _height; }
};

