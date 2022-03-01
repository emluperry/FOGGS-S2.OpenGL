#pragma once
#include "SceneObject.h"
#include <fstream>

class FlyingObject : public SceneObject
{
private:
	GLfloat _rotation;
	float angle;
	Vector3 _position;
	float speed;

public:
	FlyingObject(Mesh* mesh, float x, float y, float z);
	~FlyingObject() override;
	void Draw() override;
	void Update() override;
	void SetRotation(GLfloat rot);
};

