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
				AEInputGetCursorPosition(&mX, &mY);
				
				mX = mX - AEGfxGetWinMaxX();
				mY = mY - AEGfxGetWinMaxY();

				math::vec2 mousePos(mX, -mY);
				AESysPrintf("%d", mX);
				AESysPrintf(", %d", mY);
				AESysPrintf("\n");

				//shoot
				m_entityBullets->push_back(new Bullet("../../assets/entity/bullet/bullet.png", 1, entity->GetPosition()));

				//get bullet direction
				math::vec2 bulletPos(entity->GetPosition().x, entity->GetPosition().y);
				math::vec2 vec = mousePos - bulletPos;
				double angle = atan2(vec.y, vec.x);
				math::vec3 vel = math::vec3(cos(angle)*m_bulletSpeed, sin(angle)*m_bulletSpeed, 0);
				m_entityBullets->back()->SetVelocity(vel);

			}

			m_once = true;

		} else {
			m_once = false;
		}
	}

}
