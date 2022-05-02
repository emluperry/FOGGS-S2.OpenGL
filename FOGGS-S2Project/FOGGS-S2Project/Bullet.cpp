#include "Bullet.h"

Bullet::Bullet(TexturedMesh* mesh, Texture2D* texture, Material* material, Vector3 position, Vector3 direction) : SceneObject(mesh, texture, material)
{
	_position = position;
	_direction = direction;

	_radius = 0.9;
	_flightSpeed = 3;

	_rotationIncrements.x = (180.0 * asin(_direction.z)) / (3 * PI);
	_rotationIncrements.z = (180.0 * asin(_direction.x)) / (3 * PI);

	std::cout << _direction.x << " " << _direction.y << " " << _direction.z << std::endl;
	std::cout << _rotationIncrements.x << " " << _rotationIncrements.y << " " << _rotationIncrements.z << std::endl;

	float squareSumDirection = (_direction.x * _direction.x) + (_direction.y * _direction.y) + (_direction.z * _direction.z);
	float multiplier = std::sqrt((_flightSpeed * _flightSpeed) / squareSumDirection);

	_movementIncrements.x = multiplier * _direction.x;
	_movementIncrements.y = multiplier * _direction.y;
	_movementIncrements.z = multiplier * _direction.z;
}

Bullet::~Bullet()
{

}

void Bullet::Update()
{
	_position.x += _movementIncrements.x;
	_position.y += _movementIncrements.y;
	_position.z += _movementIncrements.z;

	_rotation.x += _rotationIncrements.x;
	_rotation.z += _rotationIncrements.z;
}