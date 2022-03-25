#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.h"

#define REFRESHRATE 16

class SpaceShooterGame
{
private:
	void InitGL(int argc, char* argv[]);
public:
	SpaceShooterGame(int argc, char* argv[]);
	~SpaceShooterGame(void);
};

