#pragma once
#include "SceneObject.h"

class StaticObject : public SceneObject
{
private:
	Vector3 _position;

public:
	StaticObject(Mesh* mesh, float x, float y, float z);
	StaticObject(TexturedMesh* mesh, Texture2D* texture, float x, float y, float z);
	~StaticObject() override;
	void Draw() override;
	void Update() override;
};

