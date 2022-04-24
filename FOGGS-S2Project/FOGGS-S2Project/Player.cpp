#include "Player.h"

Player::Player(Mesh* mesh, Material* material, float x, float y, float z) : SceneObject(mesh, material)
{
	_position = { x, y, z };

	_rotation = { 0,0,0 };

	_flightSpeed = 0.1;
	_turnSpeed = 2;
}

Player::Player(TexturedMesh* mesh, Texture2D* texture, Material* material, float x, float y, float z) : SceneObject(mesh, texture, material)
{
	_position = { x, y, z };

	_rotation = { 0,0,0 };

	_flightSpeed = 0.1;
	_turnSpeed = 2;
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
		glRotatef(_rotation.z, 0.0f, 0.0f, 1.0f);
		glDrawElements(GL_TRIANGLES, _mesh->indexCount, GL_UNSIGNED_SHORT, _mesh->indices);
		glPopMatrix();

		SetdownDraw();
	}
}

void Player::Update()
{
	_position.x += _flightSpeed;
}

void Player::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'a')
	{
		_rotation.x -= _turnSpeed;
	}
	if (key == 'd')
	{
		_rotation.x += _turnSpeed;
	}
	if (key == 'w')
	{
		_rotation.z += _turnSpeed;
	}
	if (key == 's')
	{
		_rotation.z -= _turnSpeed;
	}
}