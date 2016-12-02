#pragma once

#include <list>
#include <QRoseEngine.Core/Uuid.hpp>

namespace QRose
{
	class Scene
	{
	public:
		Scene(const std::list<Uuid>& entities);
		~Scene();

	private:
		std::list<Uuid> entities;
	};
}