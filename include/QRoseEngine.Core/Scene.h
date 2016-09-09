#pragma once

#include <vector>
#include "Entity.hpp"

namespace QRose
{
	class Scene
	{
	public:
		Scene(const std::vector<Entity>& entities);
		~Scene();
	};
}