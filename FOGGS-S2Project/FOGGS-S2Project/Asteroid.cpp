#include "Asteroid.h"

Asteroid::Asteroid(TexturedMesh* mesh, Texture2D* texture, Material* material) : SceneObject(mesh, texture, material)
{
	_direction.x = rand() % 2 - 1;
	_direction.y = rand() % 2 - 1;
	_direction.z = rand() % 2 - 1;

	_flightSpeed = 2;
}

Asteroid::~Asteroid()
{

}

void Asteroid::Update()
{
	float squareSumDirection = (_direction.x * _direction.x) + (_direction.y * _direction.y) + (_direction.z * _direction.z);
	float multiplier = std::sqrt((_flightSpeed * _flightSpeed) / squareSumDirection);

	_position.x += multiplier * _direction.x;
	_position.y += multiplier * _direction.y;
	_position.z += multiplier * _direction.z;
}