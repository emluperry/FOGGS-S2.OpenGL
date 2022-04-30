#include "Skybox.h"

Skybox::Skybox(TexturedMesh* mesh, Texture2D* texture, Material* material, Player* player) : SceneObject(mesh, texture, material)
{
	_player = player;
	_scale = { 40, 40, 40 };
	_rotation = { 0,0,0 };
}

Skybox::~Skybox()
{
	_player = nullptr;
}

void Skybox::Draw()
{
	if (_mesh->vertices != nullptr && _mesh->indices != nullptr)
	{
		GLint OldCullFaceMode;
		glGetIntegerv(GL_CULL_FACE_MODE, &OldCullFaceMode);
		GLint OldDepthFuncMode;
		glGetIntegerv(GL_DEPTH_FUNC, &OldDepthFuncMode);

		glCullFace(GL_FRONT);
		glDepthFunc(GL_LEQUAL);

		SetupDraw();

		glPushMatrix();
		glTranslatef(_player->GetPosition().x, _player->GetPosition().y, _player->GetPosition().z);
		glRotatef(_rotation.x, 1.0f, 0.0f, 0.0f);
		glRotatef(_rotation.y, 0.0f, 1.0f, 0.0f);
		glRotatef(_rotation.z, 0.0f, 0.0f, 1.0f);
		glScalef(_scale.x, _scale.y, _scale.z);
		glDrawElements(GL_TRIANGLES, _mesh->indexCount, GL_UNSIGNED_SHORT, _mesh->indices);
		glPopMatrix();

		SetdownDraw();

		glCullFace(OldCullFaceMode);
		glDepthFunc(OldDepthFuncMode);
	}
}

void Skybox::Update()
{

}