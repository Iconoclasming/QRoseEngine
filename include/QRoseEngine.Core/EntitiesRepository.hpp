#pragma once

#include <list>
#include "Entity.hpp"
#include <vector>

namespace QRose
{
	class EntitiesRepository
	{
	public:
		void Add(const Entity& entity);
		bool Contains(const Entity& entity);
		bool Contains(const Uuid& entityId);

		std::vector<Entity> GetEntities() const;
	private:
		std::list<Entity> entities;
	};
}