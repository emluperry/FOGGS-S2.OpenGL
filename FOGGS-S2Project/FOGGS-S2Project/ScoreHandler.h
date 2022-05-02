#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"

#include "Structures.h"
#include "Player.h"
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

	void Draw(Player* player);
};

