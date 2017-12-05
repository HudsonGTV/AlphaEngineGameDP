#ifndef INPUT_H
#define INPUT_H

#include <vector>

class Bullet;
class Entity;

class InputManager {
private:

	bool m_once = false;

	double m_bulletSpeed = 3.0;

	std::vector<Bullet *> *m_entityBullets;
	std::vector<Entity *> *m_entityID;

public:

	InputManager();
	InputManager(std::vector<Entity *> *entityID, std::vector<Bullet *> *entityBullets);

	void Update(Entity *entity, bool controllable, float speed = 1.0f, double dt = 1.0);

};

#endif