#pragma once

#include "Engine.hpp"
#include "GraphicsDesc.hpp"

namespace QRose
{
	class EngineFactory
	{
	public:
		static Engine* CreateEngine(const GraphicsDesc& graphicsDesc);
	};
}