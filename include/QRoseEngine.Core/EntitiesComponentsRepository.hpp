#pragma once

#include <list>
#include "Uuid.hpp"
#include "Managed.hpp"

namespace QRose
{
	class EntitiesComponentsRepository : public Managed<EntitiesComponentsRepository>
	{
	public:

		void Add(const Uuid& entityId, const Uuid& componentId);
		bool Contains(const Uuid& entityId, const Uuid& componentId);

	private:
		std::list<std::tuple<Uuid, Uuid>> entitiesComponents;
	};
};