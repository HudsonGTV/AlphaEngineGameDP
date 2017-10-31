#ifndef INPUT_H
#define INPUT_H

class Bullet;
class Entity;
#include <vector>

class InputManager {
private:
	bool m_once = false;
	std::vector<Bullet *> *m_entityBullets;

public:
	InputManager();
	InputManager(std::vector<Bullet *> *entityBullets);

	void Update(Entity *entity, bool controllable, float speed = 1.0f, double dt = 1.0);

};

#endif