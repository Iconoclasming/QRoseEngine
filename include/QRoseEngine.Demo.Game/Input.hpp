#pragma once

#include "MovementData.hpp"

namespace QRose
{
	class Input
	{
	public:
		Input() {}
		virtual ~Input() {}

		virtual MovementData GetMovementData() const abstract;
	};
}