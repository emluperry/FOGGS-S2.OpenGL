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

	void SetupDraw();
	void UndoDraw();
public:
	SceneObject(Mesh* mesh);
	SceneObject(TexturedMesh* mesh, Texture2D* texture);
	virtual ~SceneObject();

	virtual void Update();
	virtual void Draw();
};

