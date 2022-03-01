#include "StaticObject.h"

StaticObject::StaticObject(Mesh* mesh, float x, float y, float z) : SceneObject(mesh)
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
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->vertices);
		glColorPointer(3, GL_FLOAT, 0, _mesh->colors);

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);
		glDrawElements(GL_TRIANGLES, _mesh->indexCount, GL_UNSIGNED_SHORT, _mesh->indices);
		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
}

void StaticObject::Update()
{

}