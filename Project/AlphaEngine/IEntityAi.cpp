#include "Entity.h"

IEntityAi::IEntityAi(std::vector<Entity *> *entityID, char *texturePath, int frameCount, ColliderType ctype, float width, float height, float textureWidth, float textureHeight) : Entity(entityID, /* IDs should be automatic: 1, */ texturePath, frameCount, ctype, width, height, textureWidth, textureHeight) {

}

void IEntityAi::Update() {

}

void IEntityAi::AiUpdate(std::vector<Entity *> *entityID, double dt) {

}
