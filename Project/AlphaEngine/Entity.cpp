#include "Entity.h"
#include "consoleio.h"

Entity::Entity(std::vector<Entity *> *entityID, /* IDs should be automatic: int id, */ char *texturePath, int frameCount, ColliderType ctype, float width, float height, float textureWidth, float textureHeight) {

	m_entityID = entityID;
	m_id = ObjectManager::giveUniqueID();

	m_textureWidth = textureWidth;
	m_textureHeight = textureHeight;

	m_texturePath = texturePath;
	m_frameCount = frameCount;

	if(ctype == COLLIDER_BOX) {
		m_collider = new BoxCollider(width, height);
	} else if(ctype == COLLIDER_CIRCLE) {
		m_collider = new CircleCollider(width);
	} else {
		m_collider = nullptr;
	}

	Graphics::CreateMesh(this, &m_mesh, &m_texture, m_texturePath, m_frameCount, math::vec2(m_textureWidth, m_textureHeight));

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

void Entity::Update() {

	if(!m_objectWasRemovedByID) {

		Graphics::DrawMesh(this, &m_mesh, &m_texture, m_frameCount);

		if(ENABLE_DEBUG_LINES) {
			Graphics::DrawMesh(this, &m_debugMesh, &m_debugTexture, 1, 5.0f);
		}

		SetPosition(m_velocity);

		m_input->Update(this, false, 0.0f);

	}

}

void Entity::Collide(Entity *other) {

	if(other == nullptr) {
		Console::out::println(std::string("BIG PROBLEM in \"Entity::Collide\""));
		return;
	}

	if(m_name == "Enemy") {
		if(other->m_name == "Bullet") {

			SetHealth(m_health - 1);

			Console::out::println(std::string("Enemy Health: " + std::to_string(m_health)));

			// DON'T DELETE BULLETS HERE! QUEUE THEIR DELETION INSTEAD! THEY ARE AUTO DELETED IN PLAYER.CPP
			ObjectManager::removeEntityByID(m_entityID, other->m_id, false);

			return;

		}
	}

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

float Entity::GetPositionX() const {
	return m_position.x;
}

float Entity::GetPositionY() const {
	return m_position.y;
}

float Entity::GetPositionZ() const {
	return m_position.z;
}
