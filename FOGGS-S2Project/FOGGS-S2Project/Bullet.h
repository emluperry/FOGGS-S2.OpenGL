#pragma once
#include "SceneObject.h"
class Bullet : public SceneObject
{
private:
	float _radius;
	float _flightSpeed;
	Vector3 _movementIncrements;
	Vector3 _rotationIncrements;
public:
	Bullet(TexturedMesh* mesh, Texture2D* texture, Material* material, Vector3 position, Vector3 direction);
	~Bullet();

	void Update() override;
	float GetRadius() { return _radius; }
};

