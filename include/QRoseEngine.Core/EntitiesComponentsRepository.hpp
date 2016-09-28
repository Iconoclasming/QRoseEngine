#pragma once

#include <list>
#include "Uuid.hpp"

namespace QRose
{
	class EntitiesComponentsRepository
	{
	public:

		void Add(const Uuid& entityId, const Uuid& componentTypeId, const Uuid& componentId);
		bool ContainsComponent(const Uuid& entityId, const Uuid& componentId);
		bool ContainsComponentType(const Uuid& entityId, const Uuid& componentTypeId);

		std::list<std::tuple<Uuid, Uuid, Uuid>> GetEntitiesComponentsMapping();
	private:
		// Entity ID, Component type ID, Component ID
		std::list<std::tuple<Uuid, Uuid, Uuid>> entitiesComponents;
	};
};