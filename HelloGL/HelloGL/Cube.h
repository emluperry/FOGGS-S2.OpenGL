#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"

class Cube
{
private:
	static Vertex indexedVertices[];
	static Color indexedColors[];
	static GLushort indices[];

	GLfloat _rotation;
	float angle;
	Vector3 _position;
	float speed;

public:
	Cube(float x, float y, float z);
	~Cube();
	void Draw();
	void Update();
	void SetRotation(GLfloat rot);
};

