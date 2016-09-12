#pragma once

#include <vector>
#include "Entity.hpp"

namespace QRose
{
	class Scene
	{
	public:
		Scene(Entity entities ...);
		Scene(const std::vector<Entity>& entities);
		~Scene();
	};
}