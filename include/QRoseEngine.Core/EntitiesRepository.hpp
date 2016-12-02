#pragma once

#include <vector>
#include "Entity.hpp"

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
		std::vector<Entity> entities;
	};
}
