#include "SceneObject.h"

SceneObject::SceneObject(Mesh* mesh)
{
	_mesh = mesh;
	_texMesh = nullptr;
	_texture = nullptr;
	_material = nullptr;
}

SceneObject::SceneObject(TexturedMesh* mesh, Texture2D* texture)
{
	_texMesh = mesh;
	_mesh = mesh->mesh;
	_texture = texture;
	_material = nullptr;
}

SceneObject::~SceneObject()
{

}

void SceneObject::Update()
{

}

void SceneObject::Draw()
{

}

void SceneObject::SetupDraw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	if (_mesh->colors != nullptr)
	{
		glEnableClientState(GL_COLOR_ARRAY);
	}
	if (_texMesh != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, _texture->GetId());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	}
	if (_mesh->normals != nullptr)
	{
		glEnableClientState(GL_NORMAL_ARRAY);
	}

	glVertexPointer(3, GL_FLOAT, 0, _mesh->vertices);
	if (_mesh->colors != nullptr)
	{
		glColorPointer(3, GL_FLOAT, 0, _mesh->colors);
	}
	if (_mesh->normals != nullptr)
	{
		glNormalPointer(GL_FLOAT, 0, _mesh->normals);
	}
	if (_texMesh != nullptr)
	{
		glTexCoordPointer(2, GL_FLOAT, 0, _texMesh->texCoords);
	}
	if (_material != nullptr)
	{
		glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->ambient.x));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->diffuse.x));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->specular.x));
		glMaterialf(GL_FRONT, GL_SHININESS, _material->shininess);
	}
}

void SceneObject::UndoDraw()
{
	if (_mesh->normals != nullptr)
	{
		glDisableClientState(GL_NORMAL_ARRAY);
	}
	if (_texMesh != nullptr)
	{
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
	if (_mesh->colors != nullptr)
	{
		glDisableClientState(GL_COLOR_ARRAY);
	}
	glDisableClientState(GL_VERTEX_ARRAY);
}