#include "Player.h"

Player::Player(TexturedMesh* mesh, Texture2D* texture, Material* material, float x, float y, float z) : SceneObject(mesh, texture, material)
{
	_position = { x, y, z };
	_direction = { 1, 0, 0 };
	_rotation = { 0,0,0 };
	_scale = { 1,1,1 };

	_flightSpeed = 0.2;
	_turnSpeed = 0.05;
	_rotateSpeed = 4.5;

	bulletMesh = MeshLoader::LoadObj((char*)"Models/bullet.obj");
	bulletTexture = new Texture2D();
	bulletTexture->LoadTexture("Models/Bullet.bmp");
	bulletMaterial = new Material();
	bulletMaterial = MeshLoader::LoadMaterial((char*)"Models/bullet.mtl");
}

Player::~Player()
{
	SceneObject::DeleteComponents();
	for (int i = 0; i < 3; i++)
	{
		delete bullets[i];
		bullets[i] = nullptr;
	}
}

void Player::Update()
{
	_direction.x = cos((_rotation.y * PI) / 180);
	_direction.y = sin((_rotation.z * PI) / 180);
	_direction.z = -sin((_rotation.y * PI) / 180);
	float squareSumDirection = (_direction.x * _direction.x) + (_direction.y * _direction.y) + (_direction.z * _direction.z);
	float multiplier = std::sqrt((_flightSpeed * _flightSpeed) / squareSumDirection);

	_position.x += multiplier * _direction.x;
	_position.y += multiplier * _direction.y;
	_position.z += multiplier * _direction.z;

	if (_position.x > LEVEL_DIMENSIONS)
		_position.x = LEVEL_DIMENSIONS;
	else if (_position.x < -LEVEL_DIMENSIONS)
		_position.x = -LEVEL_DIMENSIONS;

	if (_position.y > LEVEL_DIMENSIONS)
		_position.y = LEVEL_DIMENSIONS;
	else if (_position.y < -LEVEL_DIMENSIONS)
		_position.y = -LEVEL_DIMENSIONS;

	if (_position.z > LEVEL_DIMENSIONS)
		_position.z = LEVEL_DIMENSIONS;
	else if (_position.z < -LEVEL_DIMENSIONS)
		_position.z = -LEVEL_DIMENSIONS;

	for (int i = 0; i < 3; i++)
	{
		if (bullets[i])
		{
			bullets[i]->Update();
			if (bullets[i]->GetPosition().x > LEVEL_DIMENSIONS || bullets[i]->GetPosition().x < -LEVEL_DIMENSIONS || bullets[i]->GetPosition().y > LEVEL_DIMENSIONS || bullets[i]->GetPosition().y < -LEVEL_DIMENSIONS || bullets[i]->GetPosition().z > LEVEL_DIMENSIONS || bullets[i]->GetPosition().z < -LEVEL_DIMENSIONS)
			{
				delete bullets[i];
				bullets[i] = nullptr;
			}
		}
	}
}

void Player::Draw()
{
	SceneObject::Draw();

	for (int i = 0; i < 3; i++)
	{
		if (bullets[i])
			bullets[i]->Draw();
	}
}

void Player::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'a')
	{
		_rotation.y += _rotateSpeed;
	}
	if (key == 'd')
	{
		_rotation.y -= _rotateSpeed;
	}
	if (key == 'w')
	{
		_rotation.z += _rotateSpeed;
		if (_rotation.z > 90)
			_rotation.z = 90;

	}
	if (key == 's')
	{
		_rotation.z -= _rotateSpeed;
		if (_rotation.z < -90)
			_rotation.z = -90;
	}
	if (key == ' ')
	{
		FireBullet();
	}
}

void Player::FireBullet()
{
	for (int i = 0; i < 3; i++)
	{
		if (!bullets[i])
		{
			bullets[i] = new Bullet(bulletMesh, bulletTexture, bulletMaterial, _position, _direction);
			break;
		}
	}
}