#include "SceneObject.h"

SceneObject::SceneObject(Mesh* mesh, Material* material)
{
	_mesh = mesh;
	_material = material;
	_texMesh = nullptr;
	_texture = nullptr;
}

SceneObject::SceneObject(TexturedMesh* mesh, Texture2D* texture, Material* material)
{
	_texMesh = mesh;
	_mesh = mesh->mesh;
	_texture = texture;
	_material = material;
}

SceneObject::~SceneObject()
{

}

void SceneObject::SetupDraw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, _mesh->vertices);

	if (_mesh->colors != nullptr)
	{
		glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(3, GL_FLOAT, 0, _mesh->colors);
	}

	if (_texMesh != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, _texture->GetId());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, 0, _texMesh->texCoords);
	}

	if (_mesh->normals != nullptr)
	{
		glEnableClientState(GL_NORMAL_ARRAY);
		glNormalPointer(GL_FLOAT, 0, _mesh->normals);
	}

	if (_material != nullptr)
	{
		glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->ambient.x));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->diffuse.x));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->specular.x));
		glMaterialf(GL_FRONT, GL_SHININESS, _material->shininess);
	}
}

void SceneObject::Draw()
{
	if (_mesh->vertices != nullptr && _mesh->indices != nullptr)
	{
		SetupDraw();

		glPushMatrix();
		glDrawElements(GL_TRIANGLES, _mesh->indexCount, GL_UNSIGNED_SHORT, _mesh->indices);
		glPopMatrix();

		SetdownDraw();
	}
}

void SceneObject::SetdownDraw()
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

void SceneObject::Update()
{

}