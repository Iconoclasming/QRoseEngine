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

		Uuid GetID() const;

	private:
		Uuid id;
	};
}