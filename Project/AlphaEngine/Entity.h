#ifndef OBJECT_H
#define OBJECT_H

#define ENTITY_COUNT 2
#define ID_PLAYER 0
#define ID_BOSS 1

#define ENABLE_DEBUG_LINES 1

#include <string>

#include "AEEngine.h"
#include "Math.h"
#include "Input.h"
#include "Collider.h"
#include "GameObjects.h"

class InputManager;

class Entity {

protected:

	bool m_isDead = false;

	int m_frameCount = 1;

	float m_textureWidth = 60.0f;
	float m_textureHeight = 60.0f;
	float m_health = 25.0f;

	char *m_texturePath = "../../assets/";

	math::vec3 m_position = math::vec3(0.0f, 0.0f, 0.0f);
	math::vec3 m_velocity;

	std::vector<Entity *> *m_entityID;

	InputManager *m_input;
	Collider *m_collider;
	ColliderType m_ctype;
	
	AEGfxVertexList *m_mesh;
	AEGfxVertexList *m_debugMesh;

	AEGfxTexture *m_texture;
	AEGfxTexture *m_debugTexture;

public:
	int m_id = -1;

	std::string m_name = "Entity";

	Entity(std::vector<Entity *> *entityID, int id, char *texturePath, int frameCount = 1, ColliderType ctype = COLLIDER_NONE, float width = 0.0f, float height = 0.0f, float textureWidth = 60.0f, float textureHeight = 60.0f);
	~Entity();

	void SetWorldPosition(math::vec3 pos);
	void SetPosition(math::vec3 pos);
	void SetVelocity(math::vec3 vel);
	void SetHealth(float health);
	
	virtual void Update();
	virtual void Collide(Entity *other);

	math::vec3 GetPosition() const;
	math::vec3 GetVelocity() const;
	Collider *GetCollider() const;
	ColliderType GetColliderType() const;

	float GetPositionX() const;
	float GetPositionY() const;
	float GetPositionZ() const;

};

#endif
