#ifndef COLLIDER_H
#define COLLIDER_H

class Entity;

enum ColliderType {COLLIDER_BOX, COLLIDER_CIRCLE};

class Collider {

protected:
	float m_width;

	virtual void BoxCollision(Entity *otherEntity);
	virtual void CircleCollision(Entity *otherEntity);
	void ResolveCollision(Entity *otherEntity);

public:
	void Update(Entity **entities, int entityNum, int currentEntity);
	float GetWidth();

};

class BoxCollider : public Collider {

protected:
	float m_height;

	void BoxCollision(Entity *otherEntity) override;
	void CircleCollision(Entity *otherEntity) override;

public:
	BoxCollider(float width, float height);
	float GetHeight();

};

class CircleCollider : public Collider {

protected:
	void BoxCollision(Entity *otherEntity) override;
	void CircleCollision(Entity *otherEntity) override;

public:
	CircleCollider(float width);

};

bool CollideBoxToBox(BoxCollider *box1, BoxCollider *box2);
bool CollideBoxToCircle(BoxCollider *box, CircleCollider *circle);
bool CollideCircleToCircle(CircleCollider *circle1, CircleCollider *circle2);

#endif