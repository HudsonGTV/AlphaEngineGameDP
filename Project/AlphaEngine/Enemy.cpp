#include "Enemy.h"

Enemy::Enemy(char *texturePath, int frameCount, ColliderType ctype, float width, float height) : Entity(texturePath, frameCount, COLLIDER_BOX, width, height) {

	

}

void Enemy::Update() {

	// AI
	/*
	getting vector:
		player pos - my pos
		convert to angle
		convert to vec3
	
	
	*/
	//anglt = std::atan2(x, y);
}
