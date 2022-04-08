#include "SpaceShooterGame.h"
#include <iostream>

SpaceShooterGame::SpaceShooterGame(int argc, char* argv[])
{
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
	camera->eye = { -4, 7, -4 };
	camera->center = { 0, 0, 0 };
	camera->up = { 0, 1.0 ,0 };

	TexturedMesh* cubeMesh = MeshLoader::LoadObj((char*)"Models/spaceship.obj");
	Texture2D* playerTexture = new Texture2D();
	playerTexture->LoadBmp((char*)"Models/spaceship.bmp");
	Material* playerMaterial = new Material();
	playerMaterial = MeshLoader::LoadMaterial((char*)"Models/spaceship.mtl");

	player = new Player(cubeMesh, playerTexture, playerMaterial, 1, 1, 1);
	objects[0] = player;
}

void SpaceShooterGame::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	player->Draw();
	glutWireCube(0.1);

	glFlush();
	glutSwapBuffers();
}

void SpaceShooterGame::Update()
{
	glLoadIdentity();

	//update objects
	player->Update();

	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->diffuse.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->specular.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));

	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, player->GetPosition().x, player->GetPosition().y, player->GetPosition().z, camera->up.x, camera->up.y, camera->up.z);
	glutPostRedisplay();
}

void SpaceShooterGame::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
	{
		camera->eye.x += 0.1;
	}
	if (key == 'a')
	{
		camera->eye.x -= 0.1;
	}
	if (key == 'q')
	{
		camera->eye.z -= 0.1;
	}
	if (key == 'e')
	{
		camera->eye.z += 0.1;
	}
	if (key == 'w')
	{
		camera->eye.y += 0.1;
	}
	if (key == 's')
	{
		camera->eye.y -= 0.1;
	}
}

void SpaceShooterGame::SpecialInput(int key, int x, int y)
{
	//special keyboard inputs and what they do go here
}