#include "Entity.hpp"

using namespace QRose;

Entity::Entity()
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