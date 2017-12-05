
#include "Entity.h"
#include "Collider.h"
#include "Math.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

void Collider::BoxCollision(Entity *thisEntity, Entity *otherEntity, double dt) {
	std::cout << "BoxCollision called on standard Collider object.\n";
}

void Collider::CircleCollision(Entity *thisEntity, Entity *otherEntity, double dt) {
	std::cout << "CircleCollision called on standard Collider object.\n";
}

void Collider::Update(std::vector<Entity *> *entities, int currentEntity, double dt) {
	for (int i = currentEntity; i < entities->size(); ++i) {
		ResolveCollision((*entities)[currentEntity], (*entities)[i], dt);
	}
}

float Collider::GetWidth() const {
	return m_width;
}

void BoxCollider::BoxCollision(Entity *thisEntity, Entity *otherEntity, double dt) {

	if(CollideBoxToBox(thisEntity, otherEntity)) {
		thisEntity->Collide(otherEntity, dt);
	}

}

void BoxCollider::CircleCollision(Entity *thisEntity, Entity *otherEntity, double dt) {

	if(CollideBoxToCircle(thisEntity, otherEntity)) {
		thisEntity->Collide(otherEntity, dt);
	}
}

BoxCollider::BoxCollider(float width, float height) {
	m_width = width;
	m_height = height;
}

float BoxCollider::GetHeight() const {
	return m_height;
}

void Collider::ResolveCollision(Entity *thisEntity, Entity *otherEntity, double dt) {

	switch(otherEntity->GetColliderType()) {
	case COLLIDER_BOX:
		this->BoxCollision(thisEntity, otherEntity, dt);
		break;
	case COLLIDER_CIRCLE:
		this->CircleCollision(thisEntity, otherEntity, dt);
		break;
	}

}

void CircleCollider::BoxCollision(Entity *thisEntity, Entity *otherEntity, double dt) {

	if(CollideBoxToCircle(otherEntity, thisEntity)) {
		thisEntity->Collide(otherEntity, dt);
	}

}

void CircleCollider::CircleCollision(Entity *thisEntity, Entity *otherEntity, double dt) {

	if(CollideCircleToCircle(thisEntity, otherEntity)) {
		thisEntity->Collide(otherEntity, dt);
	}

}

CircleCollider::CircleCollider(float width) {
	m_width = width;
}

bool CollideBoxToBox(Entity *boxEntity1, Entity *boxEntity2) {

	if(boxEntity1 == boxEntity2) {
		return false;
	}

	BoxCollider *box1 = dynamic_cast<BoxCollider *>(boxEntity1->GetCollider());
	BoxCollider *box2 = dynamic_cast<BoxCollider *>(boxEntity2->GetCollider());

	float maxX = (box1->GetWidth() + box2->GetWidth()) / 2;
	float maxY = (box1->GetHeight() + box2->GetHeight()) / 2;
	float distX = abs(boxEntity1->GetPositionX() - boxEntity2->GetPositionX());
	float distY = abs(boxEntity1->GetPositionY() - boxEntity2->GetPositionY());

	return (distX < maxX) && (distY < maxY);

}

bool CollideBoxToCircle(Entity *boxEntity, Entity *circleEntity) {

	CircleCollider *circle = dynamic_cast<CircleCollider *>(circleEntity->GetCollider());
	BoxCollider *box = dynamic_cast<BoxCollider *>(boxEntity->GetCollider());

	math::vec2 closestPoint;

	bool horizontalSide = abs(circleEntity->GetPositionX() - boxEntity->GetPositionX()) < (box->GetWidth() / 2);
	bool verticalSide = abs(circleEntity->GetPositionY() - boxEntity->GetPositionY()) < (box->GetHeight() / 2);

	if(verticalSide && horizontalSide) {
		return true;
	} else if(horizontalSide) { //horizontal size

		if(circleEntity->GetPositionY() < boxEntity->GetPositionY()) {
			closestPoint = math::vec2(circleEntity->GetPositionX(), boxEntity->GetPositionY() - (box->GetHeight() / 2));
		} else {
			closestPoint = math::vec2(circleEntity->GetPositionX(), boxEntity->GetPositionY() + (box->GetHeight() / 2));
		}

	} else if(verticalSide) { //vertical side

		if(circleEntity->GetPositionX() < boxEntity->GetPositionX()) {
			closestPoint = math::vec2(boxEntity->GetPositionX() - (box->GetWidth() / 2), circleEntity->GetPositionY());
		} else {
			closestPoint = math::vec2(boxEntity->GetPositionX() + (box->GetWidth() / 2), circleEntity->GetPositionY());
		}

	} else {

		if(circleEntity->GetPositionX() < boxEntity->GetPositionX()) { //horizontal corner
			closestPoint.y = boxEntity->GetPositionY() - (box->GetWidth() / 2);
		} else {
			closestPoint.y = boxEntity->GetPositionY() + (box->GetWidth() / 2);
		}

		if(circleEntity->GetPositionY() < boxEntity->GetPositionY()) { //vertical corner
			closestPoint.x = boxEntity->GetPositionX() - (box->GetWidth() / 2);
		} else {
			closestPoint.x = boxEntity->GetPositionX() + (box->GetWidth() / 2);
		}

	}

	float dist = sqrt(
		pow(circleEntity->GetPositionX() - closestPoint.x, 2) +
		pow(circleEntity->GetPositionY() - closestPoint.y, 2)
	);

	return dist < circle->GetWidth() / 2;

}

bool CollideCircleToCircle(Entity *circleEntity1, Entity *circleEntity2) {

	if(circleEntity1 == circleEntity2) {
		return false;
	}

	CircleCollider *circle1 = dynamic_cast<CircleCollider *>(circleEntity1->GetCollider());
	CircleCollider *circle2 = dynamic_cast<CircleCollider *>(circleEntity2->GetCollider());

	float max = (circle1->GetWidth() + circle2->GetWidth()) / 2;
	float dist = sqrt(
		// Just a note from Jeffrey: This is EXTREMELY inefficient!
		// It would be better to do this in two steps:
		//   1. Calculate the subtraction
		//   2. Do a simple multiplication (the pow() call is EXTREME overkill)
		pow(circleEntity1->GetPositionX() - circleEntity2->GetPositionX(), 2) +
		pow(circleEntity1->GetPositionY() - circleEntity2->GetPositionY(), 2)
	);
	
	return dist < max;

}