#include "GLUTCallbacks.h"
#include "HelloGL.h"

namespace GLUTCallbacks
{
	namespace //anon. namespace cannot be accessed by anything not in parent namespace
	{
		//init to null pointer
		HelloGL* helloGL = nullptr;
	}

	void Init(HelloGL* gl)
	{
		helloGL = gl;
	}

	void Display()
	{
		if (helloGL != nullptr)
		{
			helloGL->Display();
		}
	}

	void Keyboard(unsigned char key, int x, int y)
	{
		helloGL->Keyboard(key, x, y);
	}

	void Timer(int preferredRefresh)
	{
		int updateTime = glutGet(GLUT_ELAPSED_TIME);
		helloGL->Update();
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
		glutTimerFunc(preferredRefresh - updateTime, GLUTCallbacks::Timer, preferredRefresh);
	}
}