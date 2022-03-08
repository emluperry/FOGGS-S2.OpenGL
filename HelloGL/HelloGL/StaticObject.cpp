#include "StaticObject.h"

StaticObject::StaticObject(Mesh* mesh, Material* material, float x, float y, float z) : SceneObject(mesh, material)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

StaticObject::StaticObject(TexturedMesh* mesh, Texture2D* texture, Material* material, float x, float y, float z) : SceneObject(mesh, texture, material)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

StaticObject::~StaticObject()
{

}

void StaticObject::Draw()
{
	if (_mesh->vertices != nullptr && _mesh->indices != nullptr)
	{
		SetupDraw();

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);
		glDrawElements(GL_TRIANGLES, _mesh->indexCount, GL_UNSIGNED_SHORT, _mesh->indices);
		glPopMatrix();

		UndoDraw();
	}
}

void StaticObject::Update()
{

}

void StaticObject::MoveUp(float speed)
{
	_position.z -= speed;
}

void StaticObject::MoveDown(float speed)
{
	_position.z += speed;
}

void StaticObject::MoveLeft(float speed)
{
	_position.x -= speed;
}

void StaticObject::MoveRight(float speed)
{
	_position.x += speed;
}