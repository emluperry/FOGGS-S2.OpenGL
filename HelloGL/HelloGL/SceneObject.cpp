#include "SceneObject.h"

SceneObject::SceneObject(Mesh* mesh)
{
	_mesh = mesh;
	_texMesh = nullptr;
	_texture = nullptr;
}

SceneObject::SceneObject(TexturedMesh* mesh, Texture2D* texture)
{
	_texMesh = mesh;
	_mesh = mesh->mesh;
	_texture = texture;
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