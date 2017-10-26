#include "Collider.h"
#include "Entity.h"
#include "Math.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

void Collider::BoxCollision(Entity *thisEntity, Entity *otherEntity) {
	std::cout << "BoxCollision called on standard Collider object.\n";
}

void Collider::CircleCollision(Entity *thisEntity, Entity *otherEntity) {
	std::cout << "CircleCollision called on standard Collider object.\n";
}

void Collider::Update(Entity **entities, int entityNum, int currentEntity) {
	for (int i = currentEntity; i < entityNum; ++i) {
		ResolveCollision(entities[currentEntity], entities[i]);
	}
}

float Collider::GetWidth() {
	return m_width;
}

void BoxCollider::BoxCollision(Entity *thisEntity, Entity *otherEntity) {
	if (CollideBoxToBox(thisEntity, otherEntity)) {
		std::cout << "Box collision!\n";
	}
}

void BoxCollider::CircleCollision(Entity *thisEntity, Entity *otherEntity) {
	if (CollideBoxToCircle(thisEntity, otherEntity)) {
		std::cout << "Box-Circle collision!\n";
	}
}

BoxCollider::BoxCollider(float width, float height) {
	m_width = width;
	m_height = height;
}

float BoxCollider::GetHeight() {
	return m_height;
}

void Collider::ResolveCollision(Entity *thisEntity, Entity *otherEntity) {
	switch (otherEntity->GetColliderType())
	{
	case COLLIDER_BOX:
		this->BoxCollision(thisEntity, otherEntity);
		break;
	case COLLIDER_CIRCLE:
		this->CircleCollision(thisEntity, otherEntity);
		break;
	}
}

void CircleCollider::BoxCollision(Entity *thisEntity, Entity *otherEntity) {
	if (CollideBoxToCircle(otherEntity, thisEntity)) {
		std::cout << "Box-Circle collision!\n";
	}
}

void CircleCollider::CircleCollision(Entity *thisEntity, Entity *otherEntity) {
	if (CollideCircleToCircle(thisEntity, otherEntity)) {
		std::cout << "Box-Circle collision!\n";
	}
}

CircleCollider::CircleCollider(float width) {
	m_width = width;
}

bool CollideBoxToBox(Entity *boxEntity1, Entity *boxEntity2) {
	BoxCollider *box1 = dynamic_cast<BoxCollider *>(boxEntity1->GetCollider());
	BoxCollider *box2 = dynamic_cast<BoxCollider *>(boxEntity2->GetCollider());
	//\
	Pseudocode for Box-Box detection: \
	max x distance = the sum of both their widths divided by 2 \
	max y distance is basically the same but with height \
	get the x and y distances between the 2 \
	if both of them are in range, return true, otherwise false

	float maxX = (box1->GetWidth() + box2->GetWidth()) / 2;
	float maxY = (box1->GetHeight() + box2->GetHeight()) / 2;
	float distX = abs(boxEntity1->GetPositionX() - boxEntity2->GetPositionX());
	float distY = abs(boxEntity1->GetPositionY() - boxEntity2->GetPositionY());

	return (distX < maxX) && (distY < maxY);
}

bool CollideBoxToCircle(Entity *boxEntity, Entity *circleEntity) {
	CircleCollider *circle = dynamic_cast<CircleCollider *>(circleEntity->GetCollider());
	BoxCollider *box = dynamic_cast<BoxCollider *>(boxEntity->GetCollider());
	//\
	Pseudocode for Box-Circle detection: \
	ok so first we need to find the point on the box that's closest to the circle \
	so is the circle's midpoint within the same x and/or y range as the box? \
	if it's in both the x and the y ranges, return true, obviously \
	if it's in the same x range, then find which side of the box it's on (up/down) \
	then, find the point on that side with the same x coordinate as the circle \
	that will give you the closest point \
	you can do the same for y \
	find the distance between that closest point and the center of the circle \
	if the distance is less than the radius of the circle, return true \
	otherwise, return false

	math::vec2 closestPoint;
	bool horizontalSide = abs(circleEntity->GetPositionX() - boxEntity->GetPositionX()) < box->GetWidth() / 2;
	bool verticalSide = abs(circleEntity->GetPositionY() - boxEntity->GetPositionY()) < box->GetHeight() / 2;
	if (verticalSide && horizontalSide) {
		return true;
	} else if (horizontalSide) {
		if (circleEntity->GetPositionY() < boxEntity->GetPositionY()) {
			closestPoint = math::vec2(circleEntity->GetPositionX(), boxEntity->GetPositionY() - box->GetHeight() / 2);
		} else {
			closestPoint = math::vec2(circleEntity->GetPositionX(), boxEntity->GetPositionY() + box->GetHeight() / 2);
		}
	} else if (verticalSide) {
		if (circleEntity->GetPositionX() < boxEntity->GetPositionX()) {
			closestPoint = math::vec2(boxEntity->GetPositionX() - box->GetWidth() / 2, circleEntity->GetPositionY());
		} else {
			closestPoint = math::vec2(boxEntity->GetPositionX() + box->GetWidth() / 2, circleEntity->GetPositionY());
		}
	} else {
		if (circleEntity->GetPositionX() < boxEntity->GetPositionX()) {
			closestPoint.y = boxEntity->GetPositionY() - box->GetWidth() / 2;
		} else {
			closestPoint.y = boxEntity->GetPositionY() + box->GetWidth() / 2;
		}
		if (circleEntity->GetPositionX() < boxEntity->GetPositionX()) {
			closestPoint.x = boxEntity->GetPositionX() - box->GetWidth() / 2;
		} else {
			closestPoint.x = boxEntity->GetPositionX() + box->GetWidth() / 2;
		}
	}
	float dist = sqrt(pow(circleEntity->GetPositionX() - closestPoint.x, 2)
		+ pow(circleEntity->GetPositionY() - closestPoint.y, 2));
	return dist < circle->GetWidth();
}

bool CollideCircleToCircle(Entity *circleEntity1, Entity *circleEntity2) {
	CircleCollider *circle1 = dynamic_cast<CircleCollider *>(circleEntity1->GetCollider());
	CircleCollider *circle2 = dynamic_cast<CircleCollider *>(circleEntity2->GetCollider());
	//\
	Pseudocode for Circle-Circle detection: \
	max distance = the sum of the radii of the circles \
	calculate the actual distance using maaaaaath \
	if it's within the max distance, return true \
	otherwise, return false

	float max = circle1->GetWidth() + circle2->GetWidth();
	float dist = sqrt(pow(circleEntity1->GetPositionX() - circleEntity2->GetPositionX(), 2)
		+ pow(circleEntity1->GetPositionY() - circleEntity2->GetPositionY(), 2));
	return dist < max;
}