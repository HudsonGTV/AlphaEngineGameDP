#ifndef GRAPHICSENGINE_H
#define GRAPHICSENGINE_H

#include "Entity.h"

class Graphics {

private:
	///

public:
	void Init(Entity entityArray[ENTITY_COUNT]);
	void Render(double dt);

};

#endif