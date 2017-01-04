#pragma once

#include "Engine.hpp"
#include <QRoseEngine.Graphics/GraphicsDesc.hpp>
#include <QRoseEngine.Core/ManagedPtr.hpp>

namespace QRose
{
	class EngineFactory
	{
	public:
		static Ptr<Engine> CreateEngine(const GraphicsDesc& graphicsDesc);
	};
}