#include "Cube.h"
#include <iostream>

Cube::Cube(Mesh* mesh, float x, float y, float z)
{
	_mesh = mesh;
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
	if (_mesh->vertices != nullptr && _mesh->colors != nullptr && _mesh->indices != nullptr)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->vertices);
		glColorPointer(3, GL_FLOAT, 0, _mesh->colors);

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _mesh->indices);
		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
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