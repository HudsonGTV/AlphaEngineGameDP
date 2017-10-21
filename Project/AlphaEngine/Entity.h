#ifndef OBJECT_H
#define OBJECT_H

#define ENTITY_COUNT 2
#define ID_PLAYER 0
#define ID_BOSS 1

#include <string>

#include "AEEngine.h"
#include "Math.h"
#include "Input.h"

class InputManager;

class Entity {

protected:
	float m_width = 16;
	float m_height = 16;

	math::vec3 m_position = math::vec3(0.0f, 0.0f, 0.0f);

	InputManager *m_input;

public:
	Entity();
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