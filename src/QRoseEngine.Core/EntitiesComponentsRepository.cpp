#include "QRoseEngine.Core/EntitiesComponentsRepository.hpp"

#include <tuple>
#include "QRoseEngine.Core/QCE.hpp"

using namespace QRose;

void EntitiesComponentsRepository::Add(const Uuid& entityId, const Uuid& componentTypeId, const Uuid& componentId)
{
	entitiesComponents.push_back(std::make_tuple(entityId, componentTypeId, componentId));
}

std::list<std::tuple<Uuid, Uuid, Uuid>> EntitiesComponentsRepository::GetEntitiesComponentsMapping()
{
	return entitiesComponents;
}

bool EntitiesComponentsRepository::ContainsComponent(const Uuid& entityId, const Uuid& componentId)
{
	return QCE::ContainsAny(entitiesComponents,
		[&entityId, &componentId](const std::tuple<Uuid, Uuid, Uuid>& entityComponent)
	{
		return std::get<0>(entityComponent) == entityId && std::get<2>(entityComponent) == componentId;
	});
}

bool EntitiesComponentsRepository::ContainsComponentType(const Uuid& entityId, const Uuid& componentTypeId)
{
	return QCE::ContainsAny(entitiesComponents,
		[&entityId, &componentTypeId](const std::tuple<Uuid, Uuid, Uuid>& entityComponent)
	{
		return std::get<0>(entityComponent) == entityId && std::get<1>(entityComponent) == componentTypeId;
	});
}