#pragma once

#include "GraphicsDesc.hpp"
#include "Scene.hpp"

namespace QRose
{
	class Engine
	{
	public:
		virtual void PresentScene(const Scene& scene) abstract;
	};
}