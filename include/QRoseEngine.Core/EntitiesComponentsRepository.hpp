#pragma once

#include <list>
#include "Uuid.hpp"
#include <map>

namespace QRose
{
	class EntitiesComponentsRepository
	{
	public:

		void Add(const Uuid& entityId, const Uuid& componentId);
		bool Contains(const Uuid& entityId, const Uuid& componentId);

		std::list<std::tuple<Uuid, Uuid>> GetEntitiesComponentsMapping();
	private:
		std::list<std::tuple<Uuid, Uuid>> entitiesComponents;
	};
};