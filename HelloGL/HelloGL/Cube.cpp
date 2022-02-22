#include "Cube.h"
#include <iostream>

Vertex Cube::indexedVertices[] = {
	1,1,1, -1,1,1,
	-1,-1,1, 1,-1,1,
	1,-1,-1, 1,1,-1,
	-1,1,-1, -1,-1,-1
};

Color Cube::indexedColors[] = {
	1,1,1, 1,1,0,
	1,0,0, 1,0,1,
	0,0,1, 0,1,1,
	0,1,0, 0,0,0
};

GLushort Cube::indices[] = {
	0,1,2, 2,3,0,
	0,3,4, 4,5,0,
	0,5,6, 6,1,0,
	1,6,7, 7,2,1,
	7,4,3, 3,2,7,
	4,7,6, 6,5,4
};

Cube::Cube(float x, float y, float z)
{
	_rotation = 0;
	speed = 1;
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

Cube::~Cube()
{

}
void Cube::Draw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, indexedVertices);
	glColorPointer(3, GL_FLOAT, 0, indexedColors);

	glPushMatrix();
	glTranslatef(_position.x, _position.y, _position.z);
	glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, indices);
	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Cube::Update()
{
	_rotation += angle;
	_position.z += speed;
	if (_position.z > 1)
	{
		_position.z = -(rand() % 1000) / 10.0f + 20;
	}
}

void Cube::SetRotation(GLfloat rot)
{
	angle = rot;
}