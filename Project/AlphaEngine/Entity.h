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
#include "Collider.h"
#include "Velocity.h"

class InputManager;

class Entity {

protected:

	int m_frameCount = 1;

	float m_size = 30.0f;
	float m_health = 25.0f;

	char *m_texturePath = "../../assets/";

	math::vec3 m_position = math::vec3(0.0f, 0.0f, 0.0f);

	InputManager *m_input;
	Collider *m_collider;
	ColliderType m_ctype;
	Velocity m_velocity;

	AEGfxVertexList *m_mesh;
	AEGfxTexture *m_texture;

public:
	Entity(char *texturePath, int frameCount = 1);
	~Entity();

	void SetWorldPosition(math::vec3 pos);
	void SetPosition(math::vec3 pos);
	
	virtual void Update();

	math::vec3 GetPosition() const;
	Collider *GetCollider() const;
	ColliderType GetColliderType() const;

	float GetPositionX() const;
	float GetPositionY() const;
	float GetPositionZ() const;

};

#endif