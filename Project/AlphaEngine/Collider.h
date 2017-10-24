#ifndef COLLIDER_H
#define COLLIDER_H

#include "Entity.h"

class Collider {

protected:
	float m_width;

	void ResolveCollision(Entity *otherEntity);

public:
	void Update(Entity **entities);

};

class BoxCollider : public Collider {

protected:
	float m_height;

public:
	BoxCollider(float width, float height);

};

class CircleCollider : public Collider {

protected:

public:
	CircleCollider(float width);

};

#endif