#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"

#include "Structures.h"
#include "constants.h"

#include <string>

class ScoreHandler
{
private:
	int _score;
public:
	ScoreHandler();
	~ScoreHandler();

	void AddScore(int score);

	void Draw(Camera* cam, Vector3 direction);
};

