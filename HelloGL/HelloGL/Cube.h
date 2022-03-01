#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include <fstream>

class Cube
{
private:
	Mesh* _mesh;

	GLfloat _rotation;
	float angle;
	Vector3 _position;
	float speed;

public:
	Cube(Mesh* mesh, float x, float y, float z);
	~Cube();
	void Draw();
	void Update();
	void SetRotation(GLfloat rot);
};

