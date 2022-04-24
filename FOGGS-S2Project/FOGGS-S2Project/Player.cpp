#include "Player.h"

Player::Player(Mesh* mesh, Material* material, float x, float y, float z) : SceneObject(mesh, material)
{
	_position = { x, y, z };
	_direction = { 1, 0, 0 };
	_rotation = { 0,0,0 };

	_flightSpeed = 0.1;
	_turnSpeed = 0.05;
	_rotateSpeed = 2;
}

Player::Player(TexturedMesh* mesh, Texture2D* texture, Material* material, float x, float y, float z) : SceneObject(mesh, texture, material)
{
	_position = { x, y, z };
	_direction = { 1, 0, 0 };
	_rotation = { 0,0,0 };

	_flightSpeed = 0.1;
	_turnSpeed = 0.05;
	_rotateSpeed = 2;
}

Player::~Player()
{

}

void Player::Draw()
{
	if (_mesh->vertices != nullptr && _mesh->indices != nullptr)
	{
		SetupDraw();

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation.x, 1.0f, 0.0f, 0.0f);
		glRotatef(_rotation.y, 0.0f, 1.0f, 0.0f);
		glRotatef(_rotation.z, 0.0f, 0.0f, 1.0f);
		glDrawElements(GL_TRIANGLES, _mesh->indexCount, GL_UNSIGNED_SHORT, _mesh->indices);
		glPopMatrix();

		SetdownDraw();
	}
}

void Player::Update()
{
	float squareSumDirection = (_direction.x * _direction.x) + (_direction.y * _direction.y) + (_direction.z * _direction.z);
	float multiplier = std::sqrt((_flightSpeed * _flightSpeed) / squareSumDirection);
	_position.x += multiplier * _direction.x;
	_position.y += multiplier * _direction.y;
	_position.z += multiplier * _direction.z;
}

void Player::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'a')
	{
		_rotation.x -= _rotateSpeed;
		_rotation.y += _rotateSpeed;
	}
	if (key == 'd')
	{
		_rotation.x += _rotateSpeed;
		_rotation.y -= _rotateSpeed;
	}
	if (key == 'w')
	{
		_rotation.z += _rotateSpeed;
		if (_rotation.z > 90)
			_rotation.z = 90;
		_direction.y += _turnSpeed;
		if (_direction.y > 0.5)
			_direction.y = 0.5;

	}
	if (key == 's')
	{
		_rotation.z -= _rotateSpeed;
		if (_rotation.z < -90)
			_rotation.z = -90;
		_direction.y -= _turnSpeed;
		if (_direction.y > -0.5)
			_direction.y = -0.5;
	}
}