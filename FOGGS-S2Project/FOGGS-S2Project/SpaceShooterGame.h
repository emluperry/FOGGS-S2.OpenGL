#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.h"

#include "Structures.h"

#include "Texture2D.h"
#include "MeshLoader.h"

#define REFRESHRATE 16

class SpaceShooterGame
{
private:
	void InitGL(int argc, char* argv[]);
public:
	SpaceShooterGame(int argc, char* argv[]);
	~SpaceShooterGame(void);

	void Update();
	void Keyboard(unsigned char key, int x, int y);
	void SpecialInput(int key, int x, int y);
	void Display();
};

