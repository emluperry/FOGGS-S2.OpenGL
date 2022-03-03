#include "StaticObject.h"

StaticObject::StaticObject(Mesh* mesh, float x, float y, float z) : SceneObject(mesh)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

StaticObject::StaticObject(TexturedMesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture)
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
	if (_mesh->vertices != nullptr && _mesh->colors != nullptr && _mesh->indices != nullptr)
	{
		if (_texMesh != nullptr)
		{
			glBindTexture(GL_TEXTURE_2D, _texture->GetId());
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		}
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->vertices);
		glColorPointer(3, GL_FLOAT, 0, _mesh->colors);

		if (_texMesh != nullptr)
		{
			glTexCoordPointer(2, GL_FLOAT, 0, _texMesh->texCoords);
		}

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);
		glDrawElements(GL_TRIANGLES, _mesh->indexCount, GL_UNSIGNED_SHORT, _mesh->indices);
		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		if (_texMesh != nullptr)
		{
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		}
	}
}

void StaticObject::Update()
{

}