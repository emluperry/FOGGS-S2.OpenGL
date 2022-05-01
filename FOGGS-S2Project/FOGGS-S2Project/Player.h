#pragma once

#include "SceneObject.h"
#include "MeshLoader.h"
#include "Bullet.h"
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

	Bullet* bullets[3];

	void FireBullet();

public:
	Player(TexturedMesh* mesh, Texture2D* texture, Material* material, float x, float y, float z);
	~Player() override;

	void Update() override;
	void Draw() override;

	void Keyboard(unsigned char key, int x, int y);
};

