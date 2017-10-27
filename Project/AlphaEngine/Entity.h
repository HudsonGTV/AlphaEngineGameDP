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

class InputManager;

class Entity {

protected:

	int m_frameCount = 1;

	float m_size = 30.0f;
	float m_health = 25.0f;

	char *m_texturePath = "../../assets/";

	math::vec3 m_position = math::vec3(0.0f, 0.0f, 0.0f);
	math::vec3 m_velocity;

	InputManager *m_input;
	Collider *m_collider;
	ColliderType m_ctype;
	
	AEGfxVertexList *m_mesh;
	AEGfxTexture *m_texture;

public:
	Entity(char *texturePath, int frameCount = 1, ColliderType ctype = COLLIDER_NONE, float width = 0, float height = 0);
	~Entity();

	void SetWorldPosition(math::vec3 pos);
	void SetPosition(math::vec3 pos);
	void SetVelocity(math::vec3 vel);
	
	virtual void Update();

	math::vec3 GetPosition() const;
	math::vec3 GetVelocity() const;
	Collider *GetCollider() const;
	ColliderType GetColliderType() const;

	float GetPositionX() const;
	float GetPositionY() const;
	float GetPositionZ() const;

};

#endif