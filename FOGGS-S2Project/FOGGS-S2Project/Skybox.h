#pragma once
#include "SceneObject.h"
#include "Player.h"
class Skybox : public SceneObject
{
private:
	Player* _player;

public:
	Skybox(TexturedMesh* mesh, Texture2D* texture, Material* material, Player* player);
	~Skybox();

	void Draw() override;
};

