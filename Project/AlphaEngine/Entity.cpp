#include "Entity.h"
#include "Collider.h"
#include "GraphicsEngine.h"

Entity::Entity(int id, char *texturePath, int frameCount, ColliderType ctype, float width, float height, float textureWidth, float textureHeight) {

	m_id = id;

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

	m_ctype = ctype;

}

Entity::~Entity() {

	AEGfxMeshFree(m_mesh);
	AEGfxMeshFree(m_debugMesh);
	AEGfxTextureUnload(m_texture);

	delete m_input;
	delete m_collider;

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

	Graphics::DrawMesh(this, &m_mesh, &m_texture, m_frameCount);

	if(ENABLE_DEBUG_LINES) {
		Graphics::DrawMesh(this, &m_debugMesh, &m_debugTexture, 1, 5.0f);
	}

	SetPosition(m_velocity);

	m_input->Update(this, false, 0.0f);

}

void Entity::Collide(Entity *other) {

	std::string toPrint = "Collision at ";

	toPrint += std::to_string(m_position.x) + ", " + std::to_string(m_position.y);
	toPrint += " and ";
	toPrint += std::to_string(other->GetPosition().x) + ", " + std::to_string(other->GetPosition().y);
	toPrint += "\n";

	AESysPrintf(toPrint.c_str());

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

int GameObjects::giveUniqueID(std::vector<Entity *> *entityID, int &id) {

	for(int i = 0; i < entityID->size() + 1; ++i) {

		for(int j = 0; j < entityID->size(); ++j) {
			if((*entityID)[j]->m_id != i) {
				id = i;
			} else {
				id = -1;
				break;
			}
		}

		if(id != -1) {
			return id;
		}

	}

	if(id == -1) {
		return entityID->size() + 1;
	}

}

Entity *GameObjects::getEntityByID(std::vector<Entity *> *entityID, int id) {

	for(int i = 0; i < entityID->size(); ++i) {
		if((*entityID)[i]->m_id == id) {
			return (*entityID)[i];
		}
	}

	return nullptr;

}
