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

void ScoreHandler::Draw(Camera* cam, Vector3 direction)
{
	std::string text = "SCORE: " + std::to_string(_score);

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	glColor3f(1, 1, 1);
	glTranslatef((-60 * direction.x), 25 + (-30 * direction.y), (-60 * direction.z));
	glTranslatef(cam->center.x, cam->center.y, cam->center.z);
	glRasterPos2f(0.0f, 0.0f);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)(text.c_str()));

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	glPopMatrix();
}