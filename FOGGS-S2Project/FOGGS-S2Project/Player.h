#pragma once
#include "SceneObject.h"
class Player : public SceneObject
{
private:
	Vector3 _position;
public:
	Player(Mesh* mesh, Material* material, float x, float y, float z);
	Player(TexturedMesh* mesh, Texture2D* texture, Material* material, float x, float y, float z);
	~Player() override;
	void Draw() override;
	void Update() override;

	Vector3 GetPosition() { return _position; }
};

