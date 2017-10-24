#include "Bullet.h"
#include "GraphicsEngine.h"

Bullet::Bullet(char *texturePath, int frameCount) : Entity(texturePath, frameCount) {

	m_texturePath = texturePath;
	m_frameCount = frameCount;

	Graphics::CreateMesh(this, &m_mesh, &m_texture, m_texturePath, m_frameCount);

	m_input = new InputManager();

}

void Bullet::Update() {

	Graphics::DrawMesh(this, &m_mesh, &m_texture, m_frameCount);

	m_input->Update(this, false, 0.0f);

}
