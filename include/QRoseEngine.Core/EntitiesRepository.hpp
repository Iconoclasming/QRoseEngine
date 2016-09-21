#pragma once

#include "Entity.hpp"

namespace QRose
{
	class EntitiesRepository
	{
	public:
		void Add(const Entity& entity);
	};
}