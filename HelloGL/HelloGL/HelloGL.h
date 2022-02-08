#pragma once
#include <Windows.h> //required for opengl windows
#include <gl/GL.h> //opengl
#include <gl/GLU.h> //open gl util
#include "GL\freeglut.h" //freeglut lib
#include "GLUTCallbacks.h"

#define REFRESHRATE 16

class HelloGL
{
private:
	float rotation;
public:
	HelloGL(int argc, char* argv[]); //constructor
	~HelloGL(void); //destructor

	void Update();

	void Display();
	void DrawPolygon();
	void DrawScalene();
	void DrawIsosceles();
	void DrawEquilateral();
	void DrawAcute();
	void DrawRight();
	void DrawObtuse();
	void DrawPentagon();
	void DrawHexagon();
};

