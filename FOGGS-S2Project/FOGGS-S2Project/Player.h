#pragma once
#define PI 3.14159265

#include "SceneObject.h"

#include <math.h>
class Player : public SceneObject
{
private:
	Vector3 _position;
	Vector3 _direction;
	Vector3 _rotation;

	float _flightSpeed;
	float _turnSpeed;
	float _rotateSpeed;
public:
	Player(Mesh* mesh, Material* material, float x, float y, float z);
	Player(TexturedMesh* mesh, Texture2D* texture, Material* material, float x, float y, float z);
	~Player() override;
	void Draw() override;
	void Update() override;

	Vector3 GetPosition() { return _position; }
	Vector3 GetRotation() { return _rotation; }
	Vector3 GetDirection() { return _direction; }
	void Keyboard(unsigned char key, int x, int y);
};

