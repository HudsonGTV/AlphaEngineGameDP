#ifndef VELOCITY_H
#define VELOCITY_H

#include "Math.h"

class Velocity {

private:
	math::vec3 m_velocity;

public:
	void SetVelocity(math::vec3 velocity);
	void ApplyForce(math::vec3 force);
	math::vec3 GetVelocity();

};

#endif
