#ifndef INPUT_H
#define INPUT_H

#include "AEEngine.h"
#include "Entity.h"
#include <vector>

class Entity;

class InputManager {
private:
	bool m_once = false;

public:
	InputManager();

	void Update(Entity *entity, bool controllable, double dt = 1.0, float speed = 1.0f);

};

#endif