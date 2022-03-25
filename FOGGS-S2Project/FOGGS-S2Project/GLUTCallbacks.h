#pragma once
class SpaceShooterGame;

namespace GLUTCallbacks
{
	void Init(SpaceShooterGame* gl);
	void Display();
	void Keyboard(unsigned char key, int x, int y);
	void SpecialInput(int key, int x, int y);
	void Timer(int preferredRefresh);
}