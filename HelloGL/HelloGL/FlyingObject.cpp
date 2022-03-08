#include "FlyingObject.h"
#include <iostream>

FlyingObject::FlyingObject(Mesh* mesh, Material* material, float x, float y, float z, int rotation) : SceneObject(mesh, material)
{
	_rotation = rotation;
	speed = 1;
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

FlyingObject::FlyingObject(TexturedMesh* mesh, Texture2D* texture, Material* material, float x, float y, float z, int rotation) : SceneObject(mesh, texture, material)
{
	_rotation = rotation;
	speed = 1;
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

FlyingObject::~FlyingObject()
{

}

void FlyingObject::Draw()
{
	if (_mesh->vertices != nullptr && _mesh->indices != nullptr)
	{
		SetupDraw();

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
		glDrawElements(GL_TRIANGLES, _mesh->indexCount, GL_UNSIGNED_SHORT, _mesh->indices);
		glPopMatrix();

		UndoDraw();
	}
}

void FlyingObject::Update()
{
	_rotation += angle;
	_position.z += speed;
	if (_position.z > 1)
	{
		_position.z = -(rand() % 1000) / 10.0f + 20;
	}
}

void FlyingObject::SetRotation(GLfloat rot)
{
	angle = rot;
}