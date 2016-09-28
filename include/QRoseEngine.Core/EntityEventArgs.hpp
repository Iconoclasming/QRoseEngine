#pragma once

#include "EventArgs.hpp"
#include "Entity.hpp"

namespace QRose
{
	class EntityEventArgs : public EventArgs
	{
	public:
		EntityEventArgs(const Entity& entity) : entity(entity) {}
		virtual ~EntityEventArgs() {}

		Entity GetEntity() const { return entity; }

	private:
		Entity entity;
	};
}