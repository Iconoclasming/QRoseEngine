#include "EntitiesComponentsRepository.hpp"

#include <tuple>
#include <algorithm>

using namespace QRose;

void EntitiesComponentsRepository::Add(const Uuid& entityId, const Uuid& componentId)
{
	entitiesComponents.push_back(std::make_tuple(entityId, componentId));
}

bool EntitiesComponentsRepository::Contains(const Uuid& entityId, const Uuid& componentId)
{
	return std::find_if(entitiesComponents.begin(), entitiesComponents.end(), 
		[&entityId, &componentId](const std::tuple<Uuid, Uuid>& entityComponent)
	{
		return std::get<0>(entityComponent) == entityId && std::get<1>(entityComponent) == componentId;
	}) != entitiesComponents.end();
}