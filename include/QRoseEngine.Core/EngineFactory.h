#pragma once

#include "Engine.h"

namespace QRose
{
	class EngineFactory
	{
	public:
		static Engine* CreateEngine(const GraphicsDesc& graphicsDesc);
	};
}