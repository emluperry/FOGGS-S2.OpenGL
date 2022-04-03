#include "Player.h"

Player::Player(Mesh* mesh, Material* material, float x, float y, float z) : SceneObject(mesh, material)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

Player::Player(TexturedMesh* mesh, Texture2D* texture, Material* material, float x, float y, float z) : SceneObject(mesh, texture, material)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
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
		glDrawElements(GL_TRIANGLES, _mesh->indexCount, GL_UNSIGNED_SHORT, _mesh->indices);
		glPopMatrix();

		SetdownDraw();
	}
}

void Player::Update()
{
	_material->shininess += 100;
}