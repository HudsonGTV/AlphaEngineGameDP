#ifndef INPUT_H
#define INPUT_H

#include "AEEngine.h"
#include "Entity.h"

class Entity;

class InputManager {

public:
	InputManager();

	void Update(Entity *entity, bool controllable, float speed = 1.0f);

};

#endif