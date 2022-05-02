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

void ScoreHandler::Draw(Player* player)
{

	std::string text = "SCORE: " + std::to_string(_score);

	glPushMatrix();
	glDisable(GL_LIGHTING);

	glTranslatef((-60 * player->GetDirection().x), 25 + (-30 * player->GetDirection().y), (-60 * player->GetDirection().z));
	glTranslatef(player->GetPosition().x, player->GetPosition().y, player->GetPosition().z);
	glRasterPos2f(0.0f, 0.0f);
	glColor3f(1, 1, 1);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)(text.c_str()));

	glEnable(GL_LIGHTING);
	glPopMatrix();
}