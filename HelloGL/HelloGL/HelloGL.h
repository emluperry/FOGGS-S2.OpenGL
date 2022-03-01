#pragma once
#include <Windows.h> //required for opengl windows
#include <gl/GL.h> //opengl
#include <gl/GLU.h> //open gl util
#include "GL\freeglut.h" //freeglut lib
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "MeshLoader.h"
#include "SceneObject.h"
#include "FlyingObject.h"
#include "StaticObject.h"

#define REFRESHRATE 16

class HelloGL
{
private:
	Camera* camera;
	SceneObject* objects[20];
public:
	HelloGL(int argc, char* argv[]); //constructor
	~HelloGL(void); //destructor

	void InitObjects();
	void InitGL(int argc, char* argv[]);

	void Update();
	void Keyboard(unsigned char key, int x, int y);

	void Display();
};

