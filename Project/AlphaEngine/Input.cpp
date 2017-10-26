#include "Input.h"
#include "Math.h"


InputManager::InputManager() {

}

void InputManager::Update(Entity *entity, bool controllable, float speed) {

	if(controllable) {

		if(AEInputCheckCurr(VK_UP) || AEInputCheckCurr('W')) {
			entity->SetPosition(math::vec3(0.0f, speed, 0.0f));
		}

		if(AEInputCheckCurr(VK_DOWN) || AEInputCheckCurr('S')) {
			entity->SetPosition(math::vec3(0.0f, -speed, 0.0f));
		}

		if(AEInputCheckCurr(VK_LEFT) || AEInputCheckCurr('A')) {
			entity->SetPosition(math::vec3(-speed, 0.0f, 0.0f));
		}

		if(AEInputCheckCurr(VK_RIGHT) || AEInputCheckCurr('D')) {
			entity->SetPosition(math::vec3(speed, 0.0f, 0.0f));
		}
		
		
		if (AEInputCheckCurr(' ') || AEInputCheckCurr(VK_LBUTTON)) {
			
			if (!m_once) {
				//shooting code
				//get mouse pos
				s32 mX = 0;
				s32 mY = 0;
				AEInputGetCursorPositionDelta(&mX, &mY);
				int X = mX;
				int Y = mY;

				//shoot
				//Bullet bullet("../../assets/entity/bullet/bullet.png", 1, entityBullets, entity->GetPosition());
				//bullet.m_velocity.SetVelocity(math::vec3(1, 1, 0));
			}
			m_once = true;
		}
		else {
			m_once = false;
		}
	}

}
