#ifndef INPUT_H
#define INPUT_H

#include "AEEngine.h"
#include "Entity.h"
#include <vector>
#include "Bullet.h"

class Entity;

class InputManager {
private:
	bool m_once = false;

public:
	InputManager();

	void Update(Entity *entity, bool controllable, float speed = 1.0f);

};

#endif