#include "Entity.h"
#include "consoleio.h"

Entity::Entity(std::vector<Entity *> *entityID, char *texturePath, int frameCount, ColliderType ctype, float width, float height, float textureWidth, float textureHeight) {

	// STORE POINTER TO VECTOR OF ENTITY POINTERS
	m_entityID = entityID;

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
	Graphics::CreateMesh(this, &m_mesh, &m_texture, m_texturePath, m_frameCount, math::vec2(m_textureWidth, m_textureHeight));

	/* DRAW DEBUG LINES IF ENABLED */

	if(ENABLE_DEBUG_LINES) {
		switch(ctype) {
		case COLLIDER_BOX:
			Graphics::CreateMesh(this, &m_debugMesh, &m_debugTexture, "../../assets/dbug/box.png", 1, math::vec2(width, height));
			break;
		case COLLIDER_CIRCLE:
			Graphics::CreateMesh(this, &m_debugMesh, &m_debugTexture, "../../assets/dbug/circle.png", 1, math::vec2(width, width));
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
	m_velocity = vel;
}

void Entity::SetHealth(float health) {
	m_health = health;
}

void Entity::SetInvincible(bool isInvincible) {
	m_isInvincible = isInvincible;
}

void Entity::Update() {

	if(!m_objectWasRemovedByID) {

		// DRAW MESH
		Graphics::DrawMesh(this, &m_mesh, &m_texture, m_frameCount);

		// DRAW DEBUG LINES IF ENABLED
		if(ENABLE_DEBUG_LINES) {
			Graphics::DrawMesh(this, &m_debugMesh, &m_debugTexture, 1, 5.0f);
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

	if(m_name == "Enemy") {

		if(other->m_name == "Bullet") {

			SetHealth(m_health - 0.25);

			Console::out::println("Enemy Health: " + Console::value(std::to_string(m_health)), "Debug");

			// DON'T DELETE BULLETS HERE! QUEUE THEIR DELETION INSTEAD! THEY ARE AUTO DELETED IN ENEMY.CPP
			ObjectManager::removeEntityByID(m_entityID, other->m_id, false);

			return;

		}

	} else if(m_name == "Player") {

		if(other->m_name == "EBullet") {

			SetHealth(m_health - 1);

			Console::out::println("Player Health: " + Console::value(std::to_string(m_health)), "Debug");

			// DON'T DELETE ENEMY BULLETS HERE! QUEUE THEIR DELETION INSTEAD! THEY ARE AUTO DELETED IN PLAYER.CPP
			ObjectManager::removeEntityByID(m_entityID, other->m_id, false);

			return;

		} else if(other->m_name == "Enemy") {

			m_healthCooldown -= dt;

			if(m_healthCooldown <= 0.0f) {

				SetHealth(m_health - 1.0f);

				Console::out::println("Player Health: " + Console::value(std::to_string(m_health)), "Debug");

				m_healthCooldown = 1.0f;

			}

			return;

		}

	} else if(m_name != "Bullet" && m_name != "EBullet") {
		if(other->m_name == "Bullet" || other->m_name == "EBullet") {
			// DON'T DELETE BULLETS HERE! QUEUE THEIR DELETION INSTEAD! THEY ARE DELETED IN PLAYER.CPP
			ObjectManager::removeEntityByID(m_entityID, other->m_id, false);
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
