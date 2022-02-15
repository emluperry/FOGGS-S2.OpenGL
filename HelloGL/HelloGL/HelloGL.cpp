#include "HelloGL.h"

HelloGL::HelloGL(int argc, char* argv[])
{
	rotationRect = 0.0f;
	rotationSquare = 0.0f;
	rotationTriangle = 0.0f;

	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
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
	gluPerspective(45, 1, 0, 1000);

	glMatrixMode(GL_MODELVIEW);

	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	DrawPolygon();
	//DrawRight();
	//DrawAcute();
	//DrawIsosceles();
	//DrawObtuse();
	DrawScalene();
	//DrawEquilateral();
	//DrawPentagon();
	//DrawHexagon();
	DrawSquare();

	glFlush();
	glutSwapBuffers();
}

void HelloGL::Update()
{
	glLoadIdentity();

	rotationSquare += 1.0f;
	if (rotationSquare >= 360.0f)
		rotationSquare = 0.0f;
	rotationTriangle += 0.5f;
	if (rotationTriangle >= 360.0f)
		rotationTriangle = 0.0f;
	glutPostRedisplay();
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
	{
		rotationRect += 0.5f;
		if (rotationRect >= 360.0f)
			rotationRect = 0.0f;
	}
	if (key == 'a')
	{
		rotationRect -= 0.5f;
		if (rotationRect <= 0.0f)
			rotationRect = 360.0f;
	}
}

void HelloGL::DrawPolygon()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotationRect, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(-0.75, 0.5);
		glVertex2f(0.75, 0.5);
		glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(0.75, -0.5);
		glVertex2f(-0.75, -0.5);
		glEnd();
	}
	glPopMatrix();
}

void HelloGL::DrawSquare()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -2.0f);
	glRotatef(rotationSquare, -1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glVertex2f(-0.2, 0.2);
		glVertex2f(0.2, 0.2);
		glVertex2f(0.2, -0.2);
		glVertex2f(-0.2, -0.2);
		glEnd();
	}
	glPopMatrix();
}

void HelloGL::DrawScalene()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -4.0f);
	glRotatef(rotationTriangle, 0.0f, 0.0f, +1.0f);
	glBegin(GL_POLYGON);
	{
		glColor3f(0.0f, 0.1f, 0.2f);
		glVertex2f(-0.3, 0.5);
		glVertex2f(0.0f, 0.1f);
		glVertex2f(-0.20, -0.5f);
		glEnd();
	}
	glPopMatrix();
}

void HelloGL::DrawIsosceles()
{
	glBegin(GL_POLYGON);
	{
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(-0.5, 0.5);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(-0.50, -0.5f);
		glEnd();
	}
}

void HelloGL::DrawEquilateral()
{
	glBegin(GL_POLYGON);
	{
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex2f(-0.5, 0.35);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(-0.50, -0.35f);
		glEnd();
	}
}

void HelloGL::DrawAcute()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
		glVertex2f(-0.2, 0.5);
		glVertex2f(0.50, -0.5);
		glVertex2f(-0.50, -0.5);
		glEnd();
	}
}

void HelloGL::DrawRight()
{
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
		glVertex2f(-0.5, 0.5);
		glVertex2f(0.50, -0.5);
		glVertex2f(-0.50, -0.5);
		glEnd();
	}
}

void HelloGL::DrawObtuse()
{
	glBegin(GL_POLYGON);
	{
		glColor3f(0.5f, 1.0f, 1.0f);
		glVertex2f(-0.8, 0.5);
		glVertex2f(0.50, -0.5);
		glVertex2f(-0.50, -0.5);
		glEnd();
	}
}

void HelloGL::DrawPentagon()
{
	glBegin(GL_POLYGON);
	{
		glColor3f(0.0f, 0.5f, 0.5f);
		glVertex2f(0.0, 0.5);
		glVertex2f(0.5, 0.2);
		glVertex2f(0.3, -0.3);
		glVertex2f(-0.3, -0.3);
		glVertex2f(-0.5, 0.2);
		glEnd();
	}
}

void HelloGL::DrawHexagon()
{
	glBegin(GL_POLYGON);
	{
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.3, 0.2);
		glVertex2f(0.6, 0.0);
		glVertex2f(0.3, -0.2);
		glVertex2f(-0.3, -0.2);
		glVertex2f(-0.6, 0.0);
		glVertex2f(-0.3, 0.2);
		glEnd();
	}
}

HelloGL::~HelloGL(void)
{

}