#include "DrawMethods.h"
//DRAW METHODS

//2D
void DrawPolygon()
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

void DrawSquare()
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

void DrawScalene()
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

void DrawIsosceles()
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

void DrawEquilateral()
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

void DrawAcute()
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

void DrawRight()
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

void DrawObtuse()
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

void DrawPentagon()
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

void DrawHexagon()
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

//3D

Color colors[] = {
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

//PYRAMID
Vertex pyVertices[] = {
	1,1,1, -1,1,1, -1,-1,1,
	-1,-1,1, 1,-1,1, 1,1,1,

	1,1,1, 0,0,-1, -1,1,1,
	-1,1,1, 0,0,-1, -1,-1,1,

	-1,-1,1, 0,0,-1, 1,-1,1,
	1,-1,1, 0,0,-1, 1,1,1
};

//triangular prism
Vertex triPrVertices[] = {
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
Vertex hexPrVertices[] = {
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

//dodecahedron
Vertex dodecaVertices[10] = {

};

void DrawPyramid()
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

void DrawTriangularPrism()
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

void DrawHexagonalPrism()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 60; i++)
	{
		glColor3fv(&colors[i].r);
		glVertex3fv(&hexPrVertices[i].x);
	}
	glEnd();

	glPopMatrix();
}