#pragma once
#include "SceneObject.h"

class FlyingObject : public SceneObject
{
private:
	GLfloat _rotation;
	float angle;
	Vector3 _position;
	float speed;

public:
	FlyingObject(Mesh* mesh, float x, float y, float z, int rotation);
	FlyingObject(TexturedMesh* mesh, Texture2D* texture, float x, float y, float z, int rotation);
	~FlyingObject() override;
	void Draw() override;
	void Update() override;
	void SetRotation(GLfloat rot);
};

