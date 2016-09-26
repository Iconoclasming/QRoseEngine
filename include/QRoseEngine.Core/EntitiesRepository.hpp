#pragma once

#include <list>
#include "Entity.hpp"
#include "Managed.hpp"

namespace QRose
{
	class EntitiesRepository : public Managed<EntitiesRepository>
	{
	public:
		void Add(const Entity& entity);
		bool Contains(const Entity& entity);
		bool Contains(const Uuid& entityId);

	private:
		std::list<Entity> entities;
	};
}