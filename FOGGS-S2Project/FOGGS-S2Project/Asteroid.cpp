#include "Asteroid.h"

Asteroid::Asteroid(TexturedMesh* mesh, Texture2D* texture, Material* material) : SceneObject(mesh, texture, material)
{
	_position.x = rand() % 100 - 50;
	_position.y = rand() % 100 - 50;
	_position.z = rand() % 100 - 50;

	_rotation.x = rand() % 360 - 180;
	_rotation.y = rand() % 360 - 180;
	_rotation.z = rand() % 360 - 180;

	_direction.x = rand() % 2 - 1;
	_direction.y = rand() % 2 - 1;
	_direction.z = rand() % 2 - 1;

	_scale = { 2, 2, 2 };

	_flightSpeed = 1;
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

	if (_position.x > LEVEL_DIMENSIONS)
	{
		_position.x = LEVEL_DIMENSIONS;
		_direction.x = -_direction.x;
	}
	else if (_position.x < -LEVEL_DIMENSIONS)
	{
		_position.x = -LEVEL_DIMENSIONS;
		_direction.x = -_direction.x;
	}

	if (_position.y > LEVEL_DIMENSIONS)
	{
		_position.y = LEVEL_DIMENSIONS;
		_direction.y = -_direction.y;
	}
	else if (_position.y < -LEVEL_DIMENSIONS)
	{
		_position.y = -LEVEL_DIMENSIONS;
		_direction.y = -_direction.y;
	}

	if (_position.z > LEVEL_DIMENSIONS)
	{
		_position.z = LEVEL_DIMENSIONS;
		_direction.z = -_direction.z;
	}
	else if (_position.z < -LEVEL_DIMENSIONS)
	{
		_position.z = -LEVEL_DIMENSIONS;
		_direction.z = -_direction.z;
	}
}