#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.h"

#include "Structures.h"

#include "Texture2D.h"
#include "MeshLoader.h"

#include "SceneObject.h"
#include "Player.h"
#include "Skybox.h"
#include "Asteroid.h"

#define REFRESHRATE 16

class SpaceShooterGame
{
private:
	Camera* camera;
	Skybox* skybox;
	Player* player;

	TexturedMesh* asteroidMesh;
	Texture2D* asteroidTexture;
	Material* asteroidMaterial;

	int softwareElapsedTime;

	SceneObject* keyObjects[2];
	Asteroid* asteroids[40];
	int currentMax = 0;
	int spawnDelay = 0;

	Vector4* _lightPosition;
	Lighting* _lightData;

	void InitGL(int argc, char* argv[]);
	void InitObjects();
	void InitLighting();

	void SpawnAsteroid();
public:
	SpaceShooterGame(int argc, char* argv[]);
	~SpaceShooterGame(void);

	void Update();
	void Keyboard(unsigned char key, int x, int y);
	void SpecialInput(int key, int x, int y);
	void Display();
};

