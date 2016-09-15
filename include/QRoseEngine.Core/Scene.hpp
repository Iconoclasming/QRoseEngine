#pragma once

#include <list>
#include "Entity.hpp"

namespace QRose
{
	class Scene
	{
	public:
		Scene(const std::list<Entity>& entities);
		~Scene();

	private:
		std::list<Entity> entities;
	};
}