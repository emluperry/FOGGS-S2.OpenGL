#include "FlyingObject.h"
#include <iostream>

FlyingObject::FlyingObject(Mesh* mesh, float x, float y, float z, int rotation) : SceneObject(mesh)
{
	_rotation = rotation;
	speed = 1;
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

FlyingObject::FlyingObject(TexturedMesh* mesh, Texture2D* texture, float x, float y, float z, int rotation) : SceneObject(mesh, texture)
{
	_rotation = rotation;
	speed = 1;
	_position.x = x;
	_position.y = y;
	_position.z = z;

	_material = new Material();
	_material->ambient.x = 0.8;
	_material->ambient.y = 0.05;
	_material->ambient.z = 0.05;
	_material->ambient.w = 1.0;

	_material->diffuse.x = 0.8;
	_material->diffuse.y = 0.05;
	_material->diffuse.z = 0.05;
	_material->diffuse.w = 1.0;

	_material->specular.x = 1.0;
	_material->specular.y = 1.0;
	_material->specular.z = 1.0;
	_material->specular.w = 1.0;

	_material->shininess = 100.0f;
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