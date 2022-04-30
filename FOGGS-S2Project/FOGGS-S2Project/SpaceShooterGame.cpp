#include "SpaceShooterGame.h"
#include <iostream>

SpaceShooterGame::SpaceShooterGame(int argc, char* argv[])
{
	srand(time(NULL));

	InitGL(argc, argv);
	InitObjects();
	InitLighting();
	glutMainLoop();
}

SpaceShooterGame::~SpaceShooterGame(void)
{
	delete camera;
	delete player;
}

void SpaceShooterGame::InitGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("3D Space Shooter");

	glutDisplayFunc(GLUTCallbacks::Display);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutSpecialFunc(GLUTCallbacks::SpecialInput);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 1, 10000);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}

void SpaceShooterGame::InitLighting()
{
	_lightPosition = new Vector4();
	_lightPosition->x = 0.0;
	_lightPosition->y = 0.0;
	_lightPosition->z = 1.0;
	_lightPosition->w = 1.0;

	_lightData = new Lighting();
	_lightData->ambient = { 0.2, 0.2, 0.2, 1.0 };
	_lightData->diffuse = { 0.8, 0.8, 0.8, 1.0 };
	_lightData->specular = { 0.2, 0.2, 0.2, 1.0 };
}

void SpaceShooterGame::InitObjects()
{
	camera = new Camera();
	camera->eye = { 0, 20, 0 };
	camera->center = { 0, 0, 0 };
	camera->up = { 0, 1.0 ,0 };

	TexturedMesh* playerMesh = MeshLoader::LoadObj((char*)"Models/spaceship.obj");
	Texture2D* playerTexture = new Texture2D();
	playerTexture->LoadTexture("Models/spaceship.bmp");
	Material* playerMaterial = new Material();
	playerMaterial = MeshLoader::LoadMaterial((char*)"Models/spaceship.mtl");

	TexturedMesh* skyMesh = MeshLoader::LoadObj((char*)"Models/skybox.obj");
	Texture2D* skyboxTexture = new Texture2D();
	skyboxTexture->LoadTexture("Models/stars.bmp");
	Material* skyboxMaterial = new Material();
	skyboxMaterial = MeshLoader::LoadMaterial((char*)"Models/cube.mtl");

	player = new Player(playerMesh, playerTexture, playerMaterial, 0, 0, 0);
	objects[1] = player;

	Skybox* skybox = new Skybox(skyMesh, skyboxTexture, skyboxMaterial, player);
	objects[0] = skybox;

	TexturedMesh* asteroidMesh = MeshLoader::LoadObj((char*)"Models/testrock.obj");
	Texture2D* asteroidTexture = new Texture2D();
	asteroidTexture->LoadTexture("Models/asteroid.bmp");
	Material* asteroidMaterial = new Material();
	asteroidMaterial = MeshLoader::LoadMaterial((char*)"Models/testrock.mtl");

	for (int i = 2; i < 7; i++)
	{
		objects[i] = new Asteroid(asteroidMesh, asteroidTexture, asteroidMaterial);
	}
}

void SpaceShooterGame::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (int i = 0; i < 40; i++)
	{
		if (objects[i] == nullptr)
			break;
		objects[i]->Draw();
	}
	glutWireCube(0.1);

	glFlush();
	glutSwapBuffers();
}

void SpaceShooterGame::Update()
{
	glLoadIdentity();

	//update objects
	for (int i = 0; i < 40; i++)
	{
		if (objects[i] == nullptr)
			break;
		objects[i]->Update();
	}

	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->diffuse.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->specular.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));

	//vec3(20*cos(carAngle), 10,20*sin(carAngle))
	camera->eye = player->GetPosition();
	camera->eye.x += (-40 * player->GetDirection().x);
	camera->eye.y += 30;
	camera->eye.z += (40 * -player->GetDirection().z);
	camera->center = player->GetPosition();

	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	glutPostRedisplay();
}

void SpaceShooterGame::Keyboard(unsigned char key, int x, int y)
{
	player->Keyboard(key, x, y);
}

void SpaceShooterGame::SpecialInput(int key, int x, int y)
{
	//special keyboard inputs and what they do go here
}