#include "Entity.h"
#include "consoleio.h"

Entity::Entity(std::vector<Entity *> *entityList, char *texturePath, int frameCount, ColliderType ctype, float width, float height, float textureWidth, float textureHeight) {

	// STORE POINTER TO VECTOR OF ENTITY POINTERS
	m_entityList = entityList;

	// GIVE UNIQUE ID TO OBJECT
	m_id = ObjectManager::giveUniqueID();

	// STORE TEXTURE WIDTH/HEIGHT
	m_textureWidth = textureWidth;
	m_textureHeight = textureHeight;

	// SET TEXTURE PATH AND TEXTURE FRAME COUNT (AMOUNT OF FRAMES IN THE SPRITE)
	m_texturePath = texturePath;
	m_frameCount = frameCount;

	/* STORE COLLIDER TYPE */

	if(ctype == COLLIDER_BOX) {
		m_collider = new BoxCollider(width, height);
	} else if(ctype == COLLIDER_CIRCLE) {
		m_collider = new CircleCollider(width);
	} else {
		m_collider = nullptr;
	}

	// CREATE OBJECT MESH
	Graphics::CreateMesh(&m_mesh, &m_texture, m_texturePath, m_frameCount, math::vec2(m_textureWidth, m_textureHeight));

	/* DRAW DEBUG LINES IF ENABLED */

	if(ENABLE_DEBUG_LINES) {
		switch(ctype) {
		case COLLIDER_BOX:
			Graphics::CreateMesh(&m_debugMesh, &m_debugTexture, "dbug/box.png", 1, math::vec2(width, height));
			break;
		case COLLIDER_CIRCLE:
			Graphics::CreateMesh(&m_debugMesh, &m_debugTexture, "dbug/circle.png", 1, math::vec2(width, width));
			break;
		default:
			break;
		}
	}

	// SET COLLIDER TYPE
	m_ctype = ctype;

}

Entity::~Entity() {

	// DEALLOCATION
	AEGfxMeshFree(m_mesh);
	AEGfxMeshFree(m_debugMesh);
	AEGfxTextureUnload(m_texture);

	if(m_input != nullptr) {
		delete m_input;
		m_input = nullptr;
	}

	if(m_collider != nullptr) {
		delete m_collider;
		m_collider = nullptr;
	}

}

void Entity::SetWorldPosition(math::vec3 pos) {
	m_position = pos;
}

void Entity::SetPosition(math::vec3 pos) {
	m_position += pos;
}

void Entity::SetVelocity(math::vec3 vel) {
	double dt = AEFrameRateControllerGetFrameTime();
	m_velocity = vel * math::vec3(dt * 60.0, dt * 60.0, dt * 60.0);
}

void Entity::SetHealth(float health) {
	if(!m_isInvincible) {
		m_health = health;
	} else {
		Console::out::println(
			"Cannot set health of Entity with name " + Console::value(m_name) + " to " + Console::value(std::to_string(health)) + ". It is invincible.",
			"Debug"
		);
	}
}

void Entity::SetInvincible(bool isInvincible) {
	m_isInvincible = isInvincible;
}

void Entity::SetName(std::string name) {
	m_name = name;
}

void Entity::SetGroup(std::string group) {
	m_group = group;
}

void Entity::Update() {

	if(!m_objectWasRemovedByID) {

		// DRAW MESH
		Graphics::DrawMesh(this, &m_mesh, &m_texture, m_zOrder, m_frameCount);

		// DRAW DEBUG LINES IF ENABLED
		if(ENABLE_DEBUG_LINES) {
			Graphics::DrawMesh(this, &m_debugMesh, &m_debugTexture, 5.0f, 1);
		}

		// SET RELATIVE POSITION
		SetPosition(m_velocity);

		// CALL INPUT UPDATE
		m_input->Update(this, false, 0.0f);

	}

}

void Entity::Collide(Entity *other, double dt) {

	// MAKE SURE *OTHER EXISTS
	if(other == nullptr) {
		Console::out::println("in " + Console::value("Entity::Collide") + ": Other entity was nullptr.", "Error");
		return;
	}

	/* COLLISION CHECKS */

	if(GetGroup() == "GroupWall") {

		if(other->GetName() == "Bullet" || other->GetName() == "EBullet") {
			// DON'T DELETE BULLETS HERE! QUEUE THEIR DELETION INSTEAD! THEY ARE AUTO DELETED IN ENEMY.CPP
			ObjectManager::removeEntityByID(m_entityList, other->m_id, false);
		}

		return;

	}

	if(m_name == "Enemy") {

		if(other->GetName() == "Bullet") {

			SetHealth(m_health - 0.25f);

			if(!isInvincible()) {
				Console::out::println("Enemy Health: " + Console::value(std::to_string(m_health)), "Debug");
			}

			// DON'T DELETE BULLETS HERE! QUEUE THEIR DELETION INSTEAD! THEY ARE AUTO DELETED IN ENEMY.CPP
			ObjectManager::removeEntityByID(m_entityList, other->m_id, false);

			return;

		}

	} else if(m_name == "Player") {

		if(other->GetName() == "EBullet") {

			SetHealth(m_health - 1.0f);

			if(!isInvincible()) {
				Console::out::println("Player Health: " + Console::value(std::to_string(m_health)), "Debug");
			}

			// DON'T DELETE ENEMY BULLETS HERE! QUEUE THEIR DELETION INSTEAD! THEY ARE AUTO DELETED IN PLAYER.CPP
			ObjectManager::removeEntityByID(m_entityList, other->m_id, false);

			return;

		} else if(other->GetName() == "Enemy") {

			m_healthCooldown -= dt;

			if(m_healthCooldown <= 0.0f) {

				SetHealth(m_health - 1.0f);

				if(!isInvincible()) {
					Console::out::println("Player Health: " + Console::value(std::to_string(m_health)), "Debug");
				}

				m_healthCooldown = 1.0f;

			}

			return;

		}

	} else if(m_name != "Bullet" && m_name != "EBullet") {
		if(other->GetName() == "Bullet" || other->GetName() == "EBullet") {
			// DON'T DELETE BULLETS HERE! QUEUE THEIR DELETION INSTEAD! THEY ARE DELETED IN PLAYER.CPP
			ObjectManager::removeEntityByID(m_entityList, other->m_id, false);
		}
	}
	
	if(m_name != "Bullet" && m_name != "EBullet" && other->GetGroup() == "GroupWall") {

		if(other->GetName() == "WallT") {
			if(GetColliderType() == COLLIDER_BOX) {
				SetWorldPosition(math::vec3(GetPositionX(), 475.0f - dynamic_cast<BoxCollider *>(GetCollider())->GetHeight() / 2.0f, GetPositionZ()));
			} else if(GetColliderType() != COLLIDER_NONE) {
				SetWorldPosition(math::vec3(GetPositionX(), 475.0f - GetCollider()->GetWidth() / 2.0f, GetPositionZ()));
			}
		} else if(other->GetName() == "WallB") {
			if(GetColliderType() == COLLIDER_BOX) {
				SetWorldPosition(math::vec3(GetPositionX(), -475.0f + dynamic_cast<BoxCollider *>(GetCollider())->GetHeight() / 2.0f, GetPositionZ()));
			} else if(GetColliderType() != COLLIDER_NONE) {
				SetWorldPosition(math::vec3(GetPositionX(), -475.0f + GetCollider()->GetWidth() / 2.0f, GetPositionZ()));
			}
		} else if(other->GetName() == "WallL") {
			SetWorldPosition(math::vec3(-675.0f + GetCollider()->GetWidth() / 2.0f, GetPositionY(), GetPositionZ()));
		} else if(other->GetName() == "WallR") {
			SetWorldPosition(math::vec3(675.0f - GetCollider()->GetWidth() / 2.0f, GetPositionY(), GetPositionZ()));
		}

	}

}

bool Entity::isInvincible() const {
	return m_isInvincible;
}

float Entity::GetPositionX() const {
	return m_position.x;
}

float Entity::GetPositionY() const {
	return m_position.y;
}

float Entity::GetPositionZ() const {
	return m_position.z;
}

int Entity::GetID() const {
	return m_id;
}

std::string Entity::GetName() const {
	return m_name;
}

std::string Entity::GetGroup() const {
	return m_group;
}

math::vec3 Entity::GetPosition() const {
	return m_position;
}

math::vec3 Entity::GetVelocity() const {
	return m_velocity;
}

Collider *Entity::GetCollider() const {
	return m_collider;
}

ColliderType Entity::GetColliderType() const {
	return m_ctype;
}
