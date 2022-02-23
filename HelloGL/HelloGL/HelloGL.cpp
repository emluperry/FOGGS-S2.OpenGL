#include "HelloGL.h"
#include <iostream>

HelloGL::HelloGL(int argc, char* argv[])
{
	srand(time(NULL));
	camera = new Camera();
	camera->eye.x = 0.0f;
	camera->eye.y = 0.0f;
	camera->eye.z = 1.0f;
	camera->center.x = 0.0f;
	camera->center.y = 0.0f;
	camera->center.z = 0.0f;
	camera->up.x = 0.0f;
	camera->up.y = 1.0f;
	camera->up.z = 0.0f;

	Cube::Load((char*)"cube.txt");

	for (int i = 0; i < 10; i++)
	{
		cubes[i] = new Cube(((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
		int direction = rand() % 2;
		if (direction == 0)
		{
			direction = 1;
		}
		else
		{
			direction = -1;
		}
		cubes[i]->SetRotation(((rand() % 10) / 10.0f)*direction);
	}

	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//set viewport to entire window
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 1, 10000);

	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i < 10; i++)
	{
		cubes[i]->Draw();
	}
	glFlush();
	glutSwapBuffers();
}

void HelloGL::Update()
{
	glLoadIdentity();
	for (int i = 0; i < 10; i++)
	{
		cubes[i]->Update();
	}
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	glutPostRedisplay();
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
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

HelloGL::~HelloGL(void)
{
	delete camera;
}