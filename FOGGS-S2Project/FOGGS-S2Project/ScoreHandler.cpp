#include "ScoreHandler.h"

ScoreHandler::ScoreHandler()
{
	_score = 0;
}

ScoreHandler::~ScoreHandler()
{
}

void ScoreHandler::AddScore(int points)
{
	_score += points;
}

void ScoreHandler::Draw(Vector3 position, Vector3 rotation)
{
	std::string text = "SCORE: " + std::to_string(_score);

	glPushMatrix();
	glDisable(GL_LIGHTING);

	glTranslatef(position.x - 3, position.y + 3, position.z - 3);
	glRasterPos2f(0.0f, 0.0f);
	glColor3f(1, 1, 1);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)(text.c_str()));

	glEnable(GL_LIGHTING);
	glPopMatrix();
}