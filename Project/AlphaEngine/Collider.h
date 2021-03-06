#ifndef COLLIDER_H
#define COLLIDER_H

class Entity;

enum ColliderType {COLLIDER_BOX, COLLIDER_CIRCLE, COLLIDER_NONE};

class Collider {

protected:
	float m_width;

	virtual void BoxCollision(Entity *thisEntity, Entity *otherEntity, double dt);
	virtual void CircleCollision(Entity *thisEntity, Entity *otherEntity, double dt);

	void ResolveCollision(Entity *thisEntity, Entity *otherEntity, double dt);

public:
	void Update(std::vector<Entity *> *entities, int currentEntity, double dt);

	float GetWidth() const;

};

class BoxCollider : public Collider {

protected:
	float m_height;

	void BoxCollision(Entity *thisEntity, Entity *otherEntity, double dt) override;
	void CircleCollision(Entity *thisEntity, Entity *otherEntity, double dt) override;

public:
	BoxCollider(float width, float height);
	float GetHeight() const;

};

class CircleCollider : public Collider {

protected:
	void BoxCollision(Entity *thisEntity, Entity *otherEntity, double dt) override;
	void CircleCollision(Entity *thisEntity, Entity *otherEntity, double dt) override;

public:
	CircleCollider(float width);

};

bool CollideBoxToBox(Entity *boxEntity1, Entity *boxEntity2);
bool CollideBoxToCircle(Entity *boxEntity, Entity *circleEntity);
bool CollideCircleToCircle(Entity *circleEntity1, Entity *circleEntity2);

#endif