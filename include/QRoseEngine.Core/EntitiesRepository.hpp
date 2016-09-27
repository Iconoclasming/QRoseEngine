#pragma once

#include <list>
#include "Entity.hpp"

namespace QRose
{
	class EntitiesRepository
	{
	public:
		void Add(const Entity& entity);
		bool Contains(const Entity& entity);
		bool Contains(const Uuid& entityId);

	private:
		std::list<Entity> entities;
	};
}