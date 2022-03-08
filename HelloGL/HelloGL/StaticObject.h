#pragma once
#include "SceneObject.h"

class StaticObject : public SceneObject
{
private:
	Vector3 _position;

public:
	StaticObject(Mesh* mesh, Material* material, float x, float y, float z);
	StaticObject(TexturedMesh* mesh, Texture2D* texture, Material* material, float x, float y, float z);
	~StaticObject() override;
	void Draw() override;
	void Update() override;
};

