#pragma once

#include "QRoseEngine.Core/Vector3.hpp"
#include "QRoseEngine.Core/Color.hpp"

namespace QRose
{
	class IDebugRender
	{
	public:
		// TODO: select space in which draw this: in screen or world
		virtual void DrawLine(Vector3 from, Vector3 to, float thickness, Color colorStart, Color colorEnd) abstract;

	protected:
		~IDebugRender() = default;
	};
}