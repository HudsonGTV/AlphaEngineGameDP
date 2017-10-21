#include "Input.h"
#include "Math.h"

InputManager::InputManager() {

}

void InputManager::Update(Entity *entity, bool controllable, float speed) {

	if(controllable) {

		if(AEInputCheckCurr(VK_UP)) {
			entity->SetPosition(math::vec3(0.0f, speed, 0.0f));
		}

		if(AEInputCheckCurr(VK_DOWN)) {
			entity->SetPosition(math::vec3(0.0f, -speed, 0.0f));
		}

		if(AEInputCheckCurr(VK_LEFT)) {
			entity->SetPosition(math::vec3(-speed, 0.0f, 0.0f));
		}

		if(AEInputCheckCurr(VK_RIGHT)) {
			entity->SetPosition(math::vec3(speed, 0.0f, 0.0f));
		}

	}

}
