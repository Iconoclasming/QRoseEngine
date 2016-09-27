#pragma once

#include "Engine.hpp"
#include "GraphicsDesc.hpp"
#include "ManagedPtr.hpp"

namespace QRose
{
	class EngineFactory
	{
	public:
		static ManagedPtr<Engine> CreateEngine(const GraphicsDesc& graphicsDesc);
	};
}