#include "HelloGL.h"

//CUBE
Vertex HelloGL::vertices[] = {
	1,1,1, -1,1,1, -1,-1,1,
	-1,-1,1, 1,-1,1, 1,1,1,

	1,1,1, 1,-1,1, 1,-1,-1,
	1,-1,-1, 1,1,-1, 1,1,1,

	1,1,1, 1,1,-1, -1,1,-1,
	-1,1,-1, -1,1,1, 1,1,1,

	-1,1,1, -1,1,-1, -1,-1,-1,
	-1,-1,-1, -1,-1,1, -1,1,1,

	-1,-1,-1, 1,-1,-1, 1,-1,1,
	1,-1,1, -1,-1,1, -1,-1,-1,

	1,-1,-1, -1,-1,-1, -1,1,-1,
	-1,1,-1, 1,1,-1, 1,-1,-1
};

Color HelloGL::colors[] = {
	1,1,1, 1,1,0, 1,0,0,
	1,0,0, 1,0,1, 1,1,1,

	1,1,1, 1,0,1, 0,0,1,
	0,0,1, 0,1,1, 1,1,1,

	1,1,1, 0,1,1, 0,1,0,
	0,1,0, 1,1,0, 1,1,1,

	1,1,0, 0,1,0, 0,0,0,
	0,0,0, 1,0,0, 1,1,0,

	0,0,0, 0,0,1, 1,0,1,
	1,0,1, 1,0,0, 0,0,0,

	0,0,1, 0,0,0, 0,1,0,
	0,1,0, 0,1,1, 0,0,1,

	1,1,1, 1,1,0, 1,0,0,
	1,0,0, 1,0,1, 1,1,1,

	1,1,1, 1,0,1, 0,0,1,
	0,0,1, 0,1,1, 1,1,1,

	1,1,1, 0,1,1, 0,1,0,
	0,1,0, 1,1,0, 1,1,1,

	1,1,0, 0,1,0, 0,0,0,
	0,0,0, 1,0,0, 1,1,0,

	0,0,0, 0,0,1, 1,0,1,
	1,0,1, 1,0,0, 0,0,0,

	0,0,1, 0,0,0, 0,1,0,
	0,1,0, 0,1,1, 0,0,1
};

Vertex HelloGL::indexedVertices[] = {
	1,1,1, -1,1,1,
	-1,-1,1, 1,-1,1,
	1,-1,-1, 1,1,-1,
	-1,1,-1, -1,-1,-1
};

Color HelloGL::indexedColors[] = {
	1,1,1, 1,1,0,
	1,0,0, 1,0,1,
	0,0,1, 0,1,1,
	0,1,0, 0,0,0
};

GLushort HelloGL::indices[] = {
	0,1,2, 2,3,0,
	0,3,4, 4,5,0,
	0,5,6, 6,1,0,
	1,6,7, 7,2,1,
	7,4,3, 3,2,7,
	4,7,6, 6,5,4
};

//PYRAMID
Vertex HelloGL::pyVertices[] = {
	1,1,1, -1,1,1, -1,-1,1,
	-1,-1,1, 1,-1,1, 1,1,1,

	1,1,1, 0,0,-1, -1,1,1,
	-1,1,1, 0,0,-1, -1,-1,1,

	-1,-1,1, 0,0,-1, 1,-1,1,
	1,-1,1, 0,0,-1, 1,1,1
};

//triangular prism
Vertex HelloGL::triPrVertices[] = {
	-1,-1,1, 1,-1,1, 0,1,1,

	0,1,1, 0,1,-1, -1,-1,-1,
	-1,-1,-1, -1,-1,1, 0,1,1,

	1,-1,1, 1,-1,-1, 0,1,1,
	0,1,1, 1,-1,-1, 0,1,-1,

	0,1,-1, 1,-1,-1, -1,-1,-1,

	1,-1,1, -1,-1,-1, 1,-1,-1,
	-1,-1,-1, 1,-1,1, -1,-1,1
};

//hexagonal prism
Vertex HelloGL::hexPrVertices[] = {
	0.5,1,1, 0.5,-1,1, 1,0,1,
	0.5,1,1, -0.5,1,1, 0.5,-1,1,
	0.5,-1,1, -0.5,1,1, -0.5,-1,1,
	-0.5,1,1, -1,0,1, -0.5,-1,1,

	0.5,1,-1, -0.5,1,1, 0.5,1,1,
	-0.5,1,1, 0.5,1,-1, -0.5,1,-1,

	0.5,1,1, 1,0,1, 0.5,1,-1,
	1,0,1, 1,0,-1, 0.5,1,-1,

	1,0,1, 0.5,-1,-1, 1,0,-1,
	0.5,-1,1, 0.5,-1,-1, 1,0,1,

	0.5,-1,-1, 0.5,-1,1, -0.5,-1,1,
	-0.5,-1,1, -0.5,-1,-1, 0.5,-1,-1,

	-1,0,1, -1,0,-1, -0.5,-1,-1,
	-0.5,-1,1, -1,0,1, -0.5,-1,-1,

	-0.5,1,1, -0.5,1,-1, -1,0,1,
	-1,0,1, -0.5,1,-1, -1,0,-1,

	0.5,1,-1, 1,0,-1, 0.5,-1,-1,
	0.5,1,-1, 0.5,-1,-1, -0.5,1,-1,
	0.5,-1,-1, -0.5,-1,-1, -0.5,1,-1,
	-0.5,1,-1, -0.5,-1,-1, -1,0,-1
};

HelloGL::HelloGL(int argc, char* argv[])
{
	rotationRect = 0.0f;
	rotationSquare = 0.0f;
	rotationTriangle = 0.0f;
	camera = new Camera();
	camera->eye.x = 5.0f;
	camera->eye.y = 5.0f;
	camera->eye.z = -5.0f;
	camera->center.x = 0.0f;
	camera->center.y = 0.0f;
	camera->center.z = 0.0f;
	camera->up.x = 0.0f;
	camera->up.y = 1.0f;
	camera->up.z = 0.0f;

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
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//glPushMatrix();
	//glRotatef(rotationSquare, 1.0f, 0.0f, 0.0f);
	//glutWireTeapot(0.2);
	//glPopMatrix();

	//DrawCube();
	DrawCubeArray();
	//DrawIndexedCube();
	//DrawCubeArrayAlt();
	//DrawIndexedCubeAlt();

	DrawPyramid();
	DrawTriangularPrism();
	DrawHexagonalPrism();

	glFlush();
	glutSwapBuffers();
}

void HelloGL::Update()
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);

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

void HelloGL::DrawPyramid()
{
	glPushMatrix();
	glTranslatef(0.0f, -5.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 18; i++)
	{
		glColor3fv(&colors[i].r);
		glVertex3fv(&pyVertices[i].x);
	}
	glEnd();

	glPopMatrix();
}

void HelloGL::DrawTriangularPrism()
{
	glPushMatrix();
	glTranslatef(0.0f, 5.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 24; i++)
	{
		glColor3fv(&colors[i].r);
		glVertex3fv(&triPrVertices[i].x);
	}
	glEnd();

	glPopMatrix();
}

void HelloGL::DrawHexagonalPrism()
{
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 60; i++)
	{
		glColor3fv(&colors[i].r);
		glVertex3fv(&hexPrVertices[i].x);
	}
	glEnd();

	glPopMatrix();
}

void HelloGL::DrawCubeArrayAlt()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glColorPointer(3, GL_FLOAT, 0, colors);

	glPushMatrix();
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void HelloGL::DrawIndexedCubeAlt()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, indexedVertices);
	glColorPointer(3, GL_FLOAT, 0, indexedColors);

	glPushMatrix();
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, indices);
	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void HelloGL::DrawIndexedCube()
{
	glPushMatrix();
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++)
	{
		glColor3f(indexedColors[indices[i]].r, indexedColors[indices[i]].g, indexedColors[indices[i]].b);
		glVertex3f(indexedVertices[indices[i]].x, indexedVertices[indices[i]].y, indexedVertices[indices[i]].z);
	}
	glEnd();
	glPopMatrix();
}

void HelloGL::DrawCubeArray()
{
	glPushMatrix();
	glTranslatef(-5.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++)
	{
		//glColor3f(colors[i].r, colors[i].g, colors[i].b);
		//glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
		glColor3fv(&colors[i].r);
		glVertex3fv(&vertices[i].x);
	}
	glEnd();

	glPopMatrix();
}

void HelloGL::DrawCube()
{
	glBegin(GL_TRIANGLES);
	//face v0-v1-v2
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	//face v2-v3-v0
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	//face v0-v3-v4
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	//face v4-v5-v0
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	//face v0-v5-v6
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	//face v6-v1-v0
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	//face v1-v6-v7
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	//face v7-v2-v1
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	//face v7-v4-v3
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	//face v3-v2-v7
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	//face v4-v7-v6
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	//face v6-v5-v4
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glEnd();
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
	delete camera;
}