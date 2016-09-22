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

		bool operator==(const Entity& rhs) const;

	private:
		Uuid id;
	};
}