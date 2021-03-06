#include "Input.h"
#include "Bullet.h"
#include "out.h"

InputManager::InputManager() {

}

InputManager::InputManager(std::vector<Entity *> *entityList, std::vector<Bullet *> *entityBullets) {
	m_entityList = entityList;
	m_entityBullets = entityBullets;
}

void InputManager::Update(Entity *entity, bool controllable, float speed, double dt) {

	if(controllable) {

		// CONTROLLABLE ENTITY'S VELOCITY
		math::vec3 velocity;

		/* MOVEMENT */

		if(AEInputCheckCurr(VK_UP)		|| AEInputCheckCurr('W')) velocity.y += speed;
		if(AEInputCheckCurr(VK_DOWN)	|| AEInputCheckCurr('S')) velocity.y -= speed;
		if(AEInputCheckCurr(VK_LEFT)	|| AEInputCheckCurr('A')) velocity.x -= speed;
		if(AEInputCheckCurr(VK_RIGHT)	|| AEInputCheckCurr('D')) velocity.x += speed;
		if(AEInputCheckCurr(VK_SHIFT)) {
			velocity.x *= 2.5f;
			velocity.y *= 2.5f;
		}

		// SET CONTROLLABLE ENTITY'S VELOCITY
		entity->SetVelocity(velocity);

		if(AEInputCheckReleased('G')) {
			entity->SetInvincible(!entity->isInvincible());
			Console::out::println("God Mode: " + Console::value(std::to_string(entity->isInvincible())));
		}
		
		if(AEInputCheckCurr(' ') || AEInputCheckCurr(VK_LBUTTON)) {
			
			if(!m_once) {

				/* SHOOTING */

				// GET MOUSE POS
				s32 mX = 0;
				s32 mY = 0;
				float nmX = 0.0f;
				float nmY = 0.0f;
				AEInputGetCursorPosition(&mX, &mY);
				AEGfxConvertScreenCoordinatesToWorld(static_cast<float>(mX), static_cast<float>(mY), &nmX, &nmY);
				
				//nmX = nmX - AEGfxGetWinMaxX();
				//nmY = nmY - AEGfxGetWinMaxY();

				math::vec2 mousePos(nmX, nmY);

				// FIRE BULLET
				m_entityBullets->push_back(new Bullet(m_entityList, m_entityBullets, "entity/bullet/bullet.png", 1, entity->GetPosition()));

				// GET BULLET DIRECTION
				math::vec2 bulletPos(entity->GetPosition().x, entity->GetPosition().y);
				math::vec2 vec = mousePos - bulletPos;
				double angle = atan2(vec.y, vec.x);

				// SET BULLET VELOCITY TO BULLET DIRECTION * BULLET SPEED
				math::vec3 vel = math::vec3(static_cast<float>(cos(angle) * m_bulletSpeed), static_cast<float>(sin(angle) * m_bulletSpeed), 0.0f);
				m_entityBullets->back()->SetVelocity(vel);

			}

			m_once = true;

		} else {
			m_once = false;
		}

	}

}
