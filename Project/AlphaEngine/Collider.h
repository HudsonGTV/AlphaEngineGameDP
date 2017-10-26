#ifndef COLLIDER_H
#define COLLIDER_H

class Entity;

enum ColliderType {COLLIDER_BOX, COLLIDER_CIRCLE};

class Collider {

protected:
	float m_width;

	virtual void BoxCollision(Entity *thisEntity, Entity *otherEntity);
	virtual void CircleCollision(Entity *thisEntity, Entity *otherEntity);
	void ResolveCollision(Entity *thisEntity, Entity *otherEntity);

public:
	void Update(Entity **entities, int entityNum, int currentEntity);
	float GetWidth();

};

class BoxCollider : public Collider {

protected:
	float m_height;

	void BoxCollision(Entity *thisEntity, Entity *otherEntity) override;
	void CircleCollision(Entity *thisEntity, Entity *otherEntity) override;

public:
	BoxCollider(float width, float height);
	float GetHeight();

};

class CircleCollider : public Collider {

protected:
	void BoxCollision(Entity *thisEntity, Entity *otherEntity) override;
	void CircleCollision(Entity *thisEntity, Entity *otherEntity) override;

public:
	CircleCollider(float width);

};

bool CollideBoxToBox(Entity *boxEntity1, Entity *boxEntity2);
bool CollideBoxToCircle(Entity *boxEntity, Entity *circleEntity);
bool CollideCircleToCircle(Entity *circleEntity1, Entity *circleEntity2);

#endif