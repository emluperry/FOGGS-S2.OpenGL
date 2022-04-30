#pragma once
#include "SceneObject.h"
class Asteroid : public SceneObject
{
private:
	float _flightSpeed;
public:
	Asteroid(TexturedMesh* mesh, Texture2D* texture, Material* material);
	~Asteroid();

	void Update() override;
};

