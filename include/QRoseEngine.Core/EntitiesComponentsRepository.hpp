#pragma once

#include "Uuid.hpp"
#include <list>

namespace QRose
{
	class EntitiesComponentsRepository
	{
	public:

		void Add(const Uuid& entityId, const Uuid& componentId);
		bool Contains(const Uuid& entityId, const Uuid& componentId);

	private:
		std::list<std::tuple<Uuid, Uuid>> entitiesComponents;
	};
};