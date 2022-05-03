#include "SpaceShooterGame.h"
#include <iostream>

SpaceShooterGame::SpaceShooterGame(int argc, char* argv[])
{
	srand(time(NULL));

	InitGL(argc, argv);

	InitObjects();
	InitLighting();

	_gameState = STATE::MAIN_MENU;

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
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("3D Space Shooter");

	glutDisplayFunc(GLUTCallbacks::Display);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutSpecialFunc(GLUTCallbacks::SpecialInput);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
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
	_lightPosition->y = 1.0;
	_lightPosition->z = 0.0;
	_lightPosition->w = 1.0;

	_lightData = new Lighting();
	_lightData->ambient = { 0.9, 0.2, 0.7, 1.0 };
	_lightData->diffuse = { 0.8, 0.8, 0.8, 1.0 };
	_lightData->specular = { 1.0, 1.0, 1.0, 1.0 };
	_lightData->emissive = { 0.3, 0.0, 0.0, 1.0 };
}

void SpaceShooterGame::InitObjects()
{
	camera = new Camera();
	camera->eye = { 0, 20, 0 };
	camera->center = { 0, 0, 0 };
	camera->up = { 0, 1.0 ,0 };

	scoreHandler = new ScoreHandler();

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

	player = new Player(playerMesh, playerTexture, playerMaterial, Vector3(0,0,0), &(asteroids)[0], &currentMax, scoreHandler);
	keyObjects[1] = player;

	Skybox* skybox = new Skybox(skyMesh, skyboxTexture, skyboxMaterial, player);
	keyObjects[0] = skybox;

	asteroidMesh = MeshLoader::LoadObj((char*)"Models/asteroid.obj");
	asteroidTexture = new Texture2D();
	asteroidTexture->LoadTexture("Models/asteroid.bmp");
	asteroidMaterial = new Material();
	asteroidMaterial = MeshLoader::LoadMaterial((char*)"Models/asteroid.mtl");

	for (currentMax = 0; currentMax < 7; currentMax++)
	{
		asteroids[currentMax] = new Asteroid(asteroidMesh, asteroidTexture, asteroidMaterial);
	}
}

void SpaceShooterGame::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	switch (_gameState)
	{
	case STATE::MAIN_MENU:
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		glColor3f(1, 1, 1);
		glTranslatef(0, 0, 0);
		glRasterPos3f(0.0f, 0.0f, 0.0f);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)("Press Enter to Start!\n\n(Pause with Escape!)"));

		glEnable(GL_TEXTURE_2D);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		break;
	case STATE::PLAYING:
		keyObjects[0]->Draw();
		keyObjects[1]->Draw();
		for (int i = 0; i < currentMax; i++)
		{
			if (asteroids[i] == nullptr)
				continue;
			asteroids[i]->Draw();
		}

		scoreHandler->Draw(camera, player->GetDirection());
		break;
	case STATE::PAUSED:
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		glColor3f(1, 1, 1);
		glTranslatef((-60 * player->GetDirection().x), 25 + (-30 * player->GetDirection().y), (-60 * player->GetDirection().z));
		glTranslatef(camera->center.x, camera->center.y, camera->center.z);
		glRasterPos2f(0.0f, 0.0f);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)("        PAUSED: \nPress Escape to Unpause!"));

		glEnable(GL_TEXTURE_2D);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		break;
	case STATE::GAME_OVER:
	{
		std::string scoreText = "Game over!\n\nFinal score: " + std::to_string(scoreHandler->GetScore()) + "\nEnter to return to main menu.";
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		glColor3f(1, 1, 1);
		glTranslatef(0, 0, 0);
		glRasterPos3f(0.0f, 0.0f, 0.0f);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)(scoreText.c_str()));

		glEnable(GL_TEXTURE_2D);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		break;
	}
	default:
		break;
	}

	glFlush();
	glutSwapBuffers();
}

void SpaceShooterGame::Update()
{
	glLoadIdentity();
	std::cout << _gameState << std::endl;
	int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	int deltaTime = timeSinceStart - softwareElapsedTime;
	softwareElapsedTime = timeSinceStart;

	switch (_gameState)
	{
	case STATE::MAIN_MENU:
		break;
	case STATE::PLAYING:
		spawnDelay += deltaTime;
		_levelTime += deltaTime;
		if (spawnDelay >= 6000 && currentMax < 39)
		{
			SpawnAsteroid();
		}

		//update objects
		keyObjects[0]->Update();
		keyObjects[1]->Update();
		for (int i = 0; i < currentMax; i++)
		{
			if (asteroids[i] == nullptr)
				continue;
			asteroids[i]->Update();
		}

		glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->ambient.x));
		glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->diffuse.x));
		glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->specular.x));
		glLightfv(GL_LIGHT0, GL_EMISSION, &(_lightData->emissive.x));
		glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));

		camera->eye = player->GetPosition();
		camera->eye.x += (-80 * player->GetDirection().x);
		camera->eye.y += 30 + (-40 * player->GetDirection().y);
		camera->eye.z += (80 * -player->GetDirection().z);
		camera->center = player->GetPosition();

		if (_levelTime >= 60000)
			_gameState = STATE::GAME_OVER;
		break;
	case STATE::PAUSED:
		break;
	case STATE::GAME_OVER:
		break;
	default:
		break;
	}
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	glutPostRedisplay();
}

void SpaceShooterGame::Keyboard(unsigned char key, int x, int y)
{
	switch (_gameState)
	{
	case STATE::MAIN_MENU:
		if (key == 13)
		{
			_levelTime = 0;
			_gameState = STATE::PLAYING;
		}
		break;
	case STATE::PLAYING:
		if (key == 27)
		{
			_gameState = STATE::PAUSED;
		}
		else
			player->Keyboard(key, x, y);
		break;
	case STATE::PAUSED:
		if (key == 27)
		{
			_gameState = STATE::PLAYING;
		}
		break;
	case STATE::GAME_OVER:
		if (key == 13)
		{
			_gameState = STATE::MAIN_MENU;
		}
		break;
	default:
		break;
	}
}

void SpaceShooterGame::SpecialInput(int key, int x, int y)
{
	//special keyboard inputs and what they do go here
}

void SpaceShooterGame::SpawnAsteroid()
{
	spawnDelay = 0;
	for (int i = 0; i < currentMax; i++)
	{
		if (!asteroids[i])
		{
			asteroids[i] = new Asteroid(asteroidMesh, asteroidTexture, asteroidMaterial);
			return;
		}
	}
	currentMax++;
	if (currentMax > 40)
	{
		currentMax = 40;
		return;
	}
	else
	{
		asteroids[currentMax] = new Asteroid(asteroidMesh, asteroidTexture, asteroidMaterial);
	}
}