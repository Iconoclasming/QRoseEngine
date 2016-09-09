#pragma once

#include "Uuid.hpp"

namespace QRose
{
	class Entity
	{
	public:
		Entity();
		Entity(const Uuid& id);
		~Entity();

	private:
		Uuid id;
	};
}