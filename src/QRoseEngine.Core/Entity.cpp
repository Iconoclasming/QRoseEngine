#include "Entity.hpp"

using namespace QRose;

Entity::Entity() : Entity(Uuid::GenerateUuid())
{
}

Entity::Entity(const Uuid& id) : id(id)
{
}

Entity::~Entity()
{
}

Uuid Entity::GetID() const
{
	return id;
}

bool Entity::operator==(const Entity& rhs) const
{
	return this->GetID() == rhs.GetID();
}