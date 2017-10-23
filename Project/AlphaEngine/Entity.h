#ifndef OBJECT_H
#define OBJECT_H

#define ENTITY_COUNT 3
#define ID_PLAYER 0
#define ID_BOSS 1
#define ID_BULLET 2

#include <string>

#include "AEEngine.h"
#include "Math.h"
#include "Input.h"

class InputManager;

class Entity {

protected:

	int m_frameCount = 1;

	float m_size = 30.0f;
	float m_health = 25.0f;

	char *m_texturePath = "../../assets/";

	math::vec3 m_position = math::vec3(0.0f, 0.0f, 0.0f);

	InputManager *m_input;

	AEGfxVertexList *m_mesh;
	AEGfxTexture *m_texture;

public:
	Entity(char *texturePath, int frameCount = 1);
	~Entity();

	void SetWorldPosition(math::vec3 pos);
	void SetPosition(math::vec3 pos);
	
	virtual void Update();

	math::vec3 GetPosition() const;

	float GetPositionX() const;
	float GetPositionY() const;
	float GetPositionZ() const;

};

#endif