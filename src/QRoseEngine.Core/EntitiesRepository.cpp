#include "QRoseEngine.Core/EntitiesRepository.hpp"

#include <algorithm>

using namespace QRose;

void EntitiesRepository::Add(const Entity& entity)
{
	entities.push_back(entity);
}

bool EntitiesRepository::Contains(const Entity& entity)
{
	return std::find(entities.begin(), entities.end(), entity) != entities.end();
}

bool EntitiesRepository::Contains(const Uuid& entityId)
{
	return std::find_if(entities.begin(), entities.end(), [&entityId](const Entity& entity) { return entity.GetID() == entityId; }) != entities.end();
}

std::vector<Entity> EntitiesRepository::GetEntities() const
{
	return std::vector<Entity>(entities.begin(), entities.end());
}