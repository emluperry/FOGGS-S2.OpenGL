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
}

FlyingObject::~FlyingObject()
{

}

void FlyingObject::Draw()
{
	if (_mesh->vertices != nullptr && _mesh->colors != nullptr && _mesh->indices != nullptr)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		if (_texMesh != nullptr)
		{
			glBindTexture(GL_TEXTURE_2D, _texture->GetId());
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		}
		glVertexPointer(3, GL_FLOAT, 0, _mesh->vertices);
		glColorPointer(3, GL_FLOAT, 0, _mesh->colors);

		if (_texMesh != nullptr)
		{
			glTexCoordPointer(2, GL_FLOAT, 0, _texMesh->texCoords);
		}

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
		glDrawElements(GL_TRIANGLES, _mesh->indexCount, GL_UNSIGNED_SHORT, _mesh->indices);
		glPopMatrix();

		if (_texMesh != nullptr)
		{
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		}
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
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