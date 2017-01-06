#pragma once

#include "Handle.hpp"

namespace QRose
{
	class EntitiesService
	{
	public:
		EntitiesService() {}
		virtual ~EntitiesService() {}

		virtual Handle CreateEntity() abstract;
	};
}