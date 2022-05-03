#include "GLUTCallbacks.h"
#include "SpaceShooterGame.h"

namespace GLUTCallbacks
{
	namespace //anon. cannot be accessed by anything other than glutcallbacks
	{
		SpaceShooterGame* game = nullptr;
		int width;
		int height;
	}

	void Init(SpaceShooterGame* gl)
	{
		game = gl;
	}

	void Display()
	{
		if (game != nullptr)
		{
			game->Display();
		}
	}

	void Timer(int preferredRefresh)
	{
		int updateTime = glutGet(GLUT_ELAPSED_TIME);
		game->Update();
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
		glutTimerFunc(preferredRefresh - updateTime, GLUTCallbacks::Timer, preferredRefresh);
	}

	void Keyboard(unsigned char key, int x, int y)
	{
		game->Keyboard(key, x, y);
	}

	void SpecialInput(int key, int x, int y)
	{
		game->SpecialInput(key, x, y);
	}
}