#include "Input.h"
#include "Bullet.h"

InputManager::InputManager() {

}

InputManager::InputManager(std::vector<Bullet *> *entityBullets) {
	m_entityBullets = entityBullets;
}

void InputManager::Update(Entity *entity, bool controllable, float speed, double dt) {

	if(controllable) {

		if ((AEInputCheckCurr(VK_RIGHT) || AEInputCheckCurr('D')) && (AEInputCheckCurr(VK_DOWN) || AEInputCheckCurr('S'))) {
			entity->SetVelocity(math::vec3(speed, -speed, 0.0f));
		}
		else if ((AEInputCheckCurr(VK_RIGHT) || AEInputCheckCurr('D')) && (AEInputCheckCurr(VK_UP) || AEInputCheckCurr('W'))) {
			entity->SetVelocity(math::vec3(speed, speed, 0.0f));
		}
		else if ((AEInputCheckCurr(VK_LEFT) || AEInputCheckCurr('A')) && (AEInputCheckCurr(VK_DOWN) || AEInputCheckCurr('S'))) {
			entity->SetVelocity(math::vec3(-speed, -speed, 0.0f));
		}
		else if ((AEInputCheckCurr(VK_LEFT) || AEInputCheckCurr('A')) && (AEInputCheckCurr(VK_UP) || AEInputCheckCurr('W'))) {
			entity->SetVelocity(math::vec3(-speed, speed, 0.0f));
		}
		else if(AEInputCheckCurr(VK_UP) || AEInputCheckCurr('W')) {
			entity->SetVelocity(math::vec3(0.0f, speed, 0.0f));
		}
		else if(AEInputCheckCurr(VK_DOWN) || AEInputCheckCurr('S')) {
			entity->SetVelocity(math::vec3(0.0f, -speed, 0.0f));
		}
		else if(AEInputCheckCurr(VK_LEFT) || AEInputCheckCurr('A')) {
			entity->SetVelocity(math::vec3(-speed, 0.0f, 0.0f));
		}
		else if(AEInputCheckCurr(VK_RIGHT) || AEInputCheckCurr('D')) {
			entity->SetVelocity(math::vec3(speed, 0.0f, 0.0f));
		}
		else {
			entity->SetVelocity(math::vec3(0.0f, 0.0f, 0.0f));
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
				m_entityBullets->push_back(new Bullet("../../assets/entity/bullet/bullet.png", 1, entity->GetPosition()));
				m_entityBullets->back()->SetVelocity(math::vec3(1,1,0));
				
			}
			m_once = true;
		}
		else {
			m_once = false;
		}
	}

}
