#ifndef OBJECT_H
#define OBJECT_H

#include <string>

#include "AEEngine.h"
#include "Math.h"
#include "ObjectManager.h"
#include "GraphicsEngine.h"

class Object {

protected:
	std::string m_texturePath = "misc/missing.png";

	bool m_loopAnimation = true;

	float m_textureWidth = 60.0f;
	float m_textureHeight = 60.0f;
	float m_zOrder = 1.0f;
	float m_opacity = 1.0f;

	int m_currFrame = 0;
	int m_frameCount = 1;

	math::vec2 m_position = math::vec2(0.0f);
	math::vec2 m_scale = math::vec2(0.0f);

	AEGfxVertexList *m_mesh;
	AEGfxTexture *m_texture;

public:

	Object(math::vec2 pos, std::string path = "misc/missing.png", float zOrder = 1.0f, int frameCount = 1, bool loopAnimation = true, unsigned int currFrame = 0, float opacity = 1.0f, math::vec2 size = math::vec2(50.0f), math::vec2 scale = math::vec2(1.0f));
	~Object();

	void SetWorldPosition(math::vec2 pos);

	virtual void Update();

};

#endif
