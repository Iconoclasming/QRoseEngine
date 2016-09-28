#pragma once

#include "EventArgs.hpp"
#include "Uuid.hpp"

namespace QRose
{
	class ComponentUpdatedEventArgs : public EventArgs
	{
	public:
		ComponentUpdatedEventArgs(const Uuid& updatedComponentId) : updatedComponentId(updatedComponentId) {}
		~ComponentUpdatedEventArgs() {}

		Uuid GetUpdatedComponentId() const { return updatedComponentId; }

	private:
		Uuid updatedComponentId;
	};
}