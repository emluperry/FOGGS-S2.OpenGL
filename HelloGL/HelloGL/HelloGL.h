#pragma once
#include <Windows.h> //required for opengl windows
#include <gl/GL.h> //opengl
#include <gl/GLU.h> //open gl util
#include "GL\freeglut.h" //freeglut lib
#include "GLUTCallbacks.h"
#include "Structures.h"

#define REFRESHRATE 16

class HelloGL
{
private:
	Camera* camera;
public:
	HelloGL(int argc, char* argv[]); //constructor
	~HelloGL(void); //destructor

	void Update();
	void Keyboard(unsigned char key, int x, int y);

	void Display();
};

