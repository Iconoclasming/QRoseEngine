#pragma once

#include "EventArgs.hpp"
#include "Uuid.hpp"

namespace QRose
{
	class ComponentEventArgs : public EventArgs
	{
	public:
		ComponentEventArgs(const Uuid& componentTypeId, const Uuid& entityId, const Uuid& componentId)
			: componentTypeId(componentTypeId), entityId(entityId), componentId(componentId)
		{}
		virtual ~ComponentEventArgs() {}

		Uuid GetAddedComponentTypeId() const { return componentTypeId; }
		Uuid GetEntityId() const { return entityId; }
		Uuid GetAddedComponentId() const { return componentId; }

	private:
		Uuid componentTypeId;
		Uuid entityId;
		Uuid componentId;
	};
}