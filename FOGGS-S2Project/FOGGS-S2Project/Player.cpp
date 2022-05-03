#include "Player.h"

Player::Player(TexturedMesh* mesh, Texture2D* texture, Material* material, Vector3 position, Asteroid** arr, int* asteroidMax, ScoreHandler* scoreHandler) : SceneObject(mesh, texture, material)
{
	_position = position;
	_direction = { 1, 0, 0 };
	_rotation = { 0,0,0 };
	_scale = { 1,1,1 };

	asteroids = arr;
	currentAsteroidMax = asteroidMax;

	_scoreHandler = scoreHandler;
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
	_direction.x = cos((_rotation.y * PI) / 180) * cos((_rotation.z * PI) / 180);
	if (fabs(_direction.x) < 1e-7)
		_direction.x = 0;
	_direction.y = sin((_rotation.z * PI) / 180);
	if (fabs(_direction.y) < 1e-7)
		_direction.y = 0;
	_direction.z = -sin((_rotation.y * PI) / 180) * cos((_rotation.z * PI) / 180);
	if (fabs(_direction.z) < 1e-7)
		_direction.z = 0;

	std::cout << _direction.x << " " << _direction.y << " " << _direction.z << std::endl;

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
		if (bullets[i] != nullptr)
		{
			bullets[i]->Update();
			if (bullets[i]->GetPosition().x > LEVEL_DIMENSIONS || bullets[i]->GetPosition().x < -LEVEL_DIMENSIONS || bullets[i]->GetPosition().y > LEVEL_DIMENSIONS || bullets[i]->GetPosition().y < -LEVEL_DIMENSIONS || bullets[i]->GetPosition().z > LEVEL_DIMENSIONS || bullets[i]->GetPosition().z < -LEVEL_DIMENSIONS)
			{
				delete bullets[i];
				bullets[i] = nullptr;
				continue;
			}

			for (int j = 0; j < *currentAsteroidMax; j++)
			{
				if (asteroids[j] != nullptr)
				{
					//check collision
					//find dist between objects
					float a = std::abs(asteroids[j]->GetPosition().x - bullets[i]->GetPosition().x);
					float b = std::abs(asteroids[j]->GetPosition().y - bullets[i]->GetPosition().y);
					float c = std::abs(asteroids[j]->GetPosition().z - bullets[i]->GetPosition().z);
					float squareDist = a * a + b * b + c * c;
					//find sum of radiuses
					float radiusSum = asteroids[j]->GetRadius() + bullets[i]->GetRadius();
					//if dist < radi: destroy both
					if (squareDist < radiusSum * radiusSum)
					{
						_scoreHandler->AddScore(100);
						//destroy both
						delete bullets[i];
						bullets[i] = nullptr;

						delete asteroids[j];
						asteroids[j] = nullptr;
						break;
					}
				}
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
		if (_rotation.z > 85.5)
			_rotation.z = 85.5;

	}
	if (key == 's')
	{
		_rotation.z -= _rotateSpeed;
		if (_rotation.z < -85.5)
			_rotation.z = -85.5;
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