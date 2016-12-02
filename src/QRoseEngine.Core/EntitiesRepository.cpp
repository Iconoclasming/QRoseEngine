#include "QRoseEngine.Core/EntitiesRepository.hpp"

#include <QRoseEngine.Core/QCE.hpp>

using namespace QRose;

void EntitiesRepository::Add(const Entity& entity)
{
	entities.push_back(entity);
}

bool EntitiesRepository::Contains(const Entity& entity)
{
	return QCE::Contains(entities, entity);
}

bool EntitiesRepository::Contains(const Uuid& entityId)
{
	return QCE::ContainsAny(entities, [&entityId](const Entity& entity) { return entity.GetID() == entityId; });
}

std::vector<Entity> EntitiesRepository::GetEntities() const
{
	return entities;
}