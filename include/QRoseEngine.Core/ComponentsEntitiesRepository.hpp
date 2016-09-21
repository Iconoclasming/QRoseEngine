#pragma once

#include "Uuid.hpp"

namespace QRose
{
	class ComponentsEntitiesRepository
	{
	public:

		void Add(const Uuid& entityId, const Uuid& componentId);
	};
}