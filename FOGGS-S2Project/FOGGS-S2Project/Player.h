#pragma once
#define PI 3.14159265

#include "SceneObject.h"

#include <math.h>
class Player : public SceneObject
{
private:
	float _flightSpeed;
	float _turnSpeed;
	float _rotateSpeed;
public:
	Player(Mesh* mesh, Material* material, float x, float y, float z);
	Player(TexturedMesh* mesh, Texture2D* texture, Material* material, float x, float y, float z);
	~Player() override;

	void Update() override;

	void Keyboard(unsigned char key, int x, int y);
};

