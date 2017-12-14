#include "Object.h"

Object::Object(math::vec2 pos, std::string path, float zOrder, int frameCount, bool loopAnimation, unsigned int currFrame, float opacity, math::vec2 size, math::vec2 scale) {
	
	m_position = pos;
	m_texturePath = path;
	m_zOrder = zOrder;
	m_frameCount = frameCount;
	m_loopAnimation = loopAnimation;
	m_currFrame = currFrame;
	m_opacity = opacity;
	m_scale = scale;

	Graphics::CreateMesh(&m_mesh, &m_texture, path, m_frameCount, size);

}

Object::~Object() {

	AEGfxMeshFree(m_mesh);
	AEGfxTextureUnload(m_texture);

}

void Object::SetWorldPosition(math::vec2 pos) {
	m_position = pos;
}

void Object::Update() {

	Graphics::DrawMesh(m_position, &m_mesh, &m_texture, m_zOrder, m_frameCount, m_loopAnimation, m_currFrame, m_opacity, m_scale);

}
