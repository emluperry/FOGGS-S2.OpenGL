#pragma once

#include "SceneObject.h"
#include "MeshLoader.h"
#include "ScoreHandler.h"
#include "Bullet.h"
#include "Asteroid.h"
#include <math.h>

class Player : public SceneObject
{
private:
	ScoreHandler* _scoreHandler;

	float _flightSpeed;
	float _turnSpeed;
	float _rotateSpeed;

	TexturedMesh* bulletMesh;
	Texture2D* bulletTexture;
	Material* bulletMaterial;

	Asteroid** asteroids;
	int* currentAsteroidMax;
	Bullet* bullets[3];

	void FireBullet();

public:
	Player(TexturedMesh* mesh, Texture2D* texture, Material* material, Vector3 position, Asteroid** arr, int* asteroidMax, ScoreHandler* scoreHandler);
	~Player() override;

	void Update() override;
	void Draw() override;

	void Keyboard(unsigned char key, int x, int y);
};

