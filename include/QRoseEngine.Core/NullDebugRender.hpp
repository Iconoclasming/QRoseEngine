#pragma once

#include "IDebugRender.hpp"

namespace QRose
{
	class NullDebugRender : public IDebugRender
	{
	public:
		virtual ~NullDebugRender() = default;

		void DrawLine(Vector2 from, Vector2 to, float thickness, Color colorStart, Color colorEnd) override
		{
		}

		void DrawLine(Vector3 from, Vector3 to, float thickness, Color colorStart, Color colorEnd) override 
		{
		}
	};	
}
