#ifndef OBJECT_H
#define OBJECT_H

#define ENTITY_COUNT 2

#include <string>

#include "Math.h"

class Entity {

protected:
	float m_width = 16;
	float m_height = 16;



	math::vec3 m_position = math::vec3(0.0f, 0.0f, 0.0f);

public:
	Entity();

	void SetWorldPosition(math::vec3 pos);
	void SetPosition(math::vec3 pos);

	math::vec3 GetPosition() const;

};

#endif