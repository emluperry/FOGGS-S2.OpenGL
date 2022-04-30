#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"

#include "Structures.h"
#include "Texture2D.h"

class SceneObject
{
protected:
	Mesh* _mesh;
	TexturedMesh* _texMesh;
	Texture2D* _texture;
	Material* _material;

	Vector3 _position;
	Vector3 _rotation;
	Vector3 _scale;

	Vector3 _direction;

	void SetupDraw();
	void SetdownDraw();
public:
	SceneObject(Mesh* mesh, Material* material);
	SceneObject(TexturedMesh* mesh, Texture2D* texture, Material* material);
	virtual ~SceneObject();

	virtual void Update();
	virtual void Draw();

	Vector3 GetPosition() { return _position; }
	Vector3 GetRotation() { return _rotation; }
	Vector3 GetDirection() { return _direction; }
};

