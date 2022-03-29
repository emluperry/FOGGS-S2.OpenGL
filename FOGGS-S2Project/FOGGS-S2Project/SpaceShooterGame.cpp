#include "SpaceShooterGame.h"
#include <iostream>

SpaceShooterGame::SpaceShooterGame(int argc, char* argv[])
{
	InitGL(argc, argv);
	InitObjects();
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

void SpaceShooterGame::InitObjects()
{
	camera = new Camera();
	camera->eye = { -4, 7, -4 };
	camera->center = { 0, 0, 0 };
	camera->up = { 0, 1.0 ,0 };

	TexturedMesh* cubeMesh = MeshLoader::LoadTextured((char*)"Models/cube.txt", true);
	Texture2D* playerTexture = new Texture2D();
	playerTexture->LoadBmp((char*)"Models/test.bmp");
	Material* playerMaterial = new Material();
	playerMaterial->ambient = { 0.2, 0.2, 0.2, 1.0 };
	playerMaterial->diffuse = { 0.7, 0.05, 0.3, 1.0 };
	playerMaterial->specular = { 1.0, 1.0, 1.0, 1.0 };
	playerMaterial->shininess = 50.0f;

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
	//update light
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, player->GetPosition().x, player->GetPosition().y, player->GetPosition().z, camera->up.x, camera->up.y, camera->up.z);
	std::cout << camera->eye << std::endl;
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