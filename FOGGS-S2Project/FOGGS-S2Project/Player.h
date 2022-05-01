#pragma once
#define PI 3.14159265

#include "SceneObject.h"
#include "MeshLoader.h"
#include <math.h>

class Player : public SceneObject
{
private:
	float _flightSpeed;
	float _turnSpeed;
	float _rotateSpeed;

	TexturedMesh* bulletMesh;
	Texture2D* bulletTexture;
	Material* bulletMaterial;

	SceneObject* bullets[3];

	void FireBullet();

public:
	Player(TexturedMesh* mesh, Texture2D* texture, Material* material, float x, float y, float z);
	~Player() override;

	void Update() override;
	void Draw() override;

	void Keyboard(unsigned char key, int x, int y);
};

