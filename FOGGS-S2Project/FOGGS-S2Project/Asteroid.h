#pragma once
#include "SceneObject.h"
class Asteroid : public SceneObject
{
private:
	float _flightSpeed;
	float _radius;
public:
	Asteroid(TexturedMesh* mesh, Texture2D* texture, Material* material);
	~Asteroid();

	void Update() override;
	float GetRadius() { return _radius; }
};

