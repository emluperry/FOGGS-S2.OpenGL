#include "SpaceShooterGame.h"

SpaceShooterGame::SpaceShooterGame(int argc, char* argv[])
{
	InitGL(argc, argv);
}

SpaceShooterGame::~SpaceShooterGame(void)
{

}

void SpaceShooterGame::InitGL(int argc, char* argv[])
{
	glutInit(&argc, argv);
}