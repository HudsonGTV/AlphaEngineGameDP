
#include "Velocity.h"

void Velocity::SetVelocity(math::vec3 velocity) {

	m_velocity = velocity;

}
void Velocity::ApplyForce(math::vec3 force) {

	m_velocity += force;

}

math::vec3 Velocity::GetVelocity() {

	return m_velocity;

}