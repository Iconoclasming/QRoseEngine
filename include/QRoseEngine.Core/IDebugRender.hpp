#pragma once

#include "QRoseEngine.Core/Vector.hpp"
#include "QRoseEngine.Core/Color.hpp"

namespace QRose
{
	class IDebugRender
	{
	public:
		virtual void DrawLine(Vector2 from, Vector2 to, float thickness, Color colorStart, Color colorEnd) abstract;
		virtual void DrawLine(Vector3 from, Vector3 to, float thickness, Color colorStart, Color colorEnd) abstract;

	protected:
		~IDebugRender() = default;
	};
}