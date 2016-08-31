#pragma once

#include "GraphicsDesc.h"
#include "Scene.h"

namespace QRose
{
	class Engine
	{
	public:
		virtual void PresentScene(const Scene& scene) abstract;
	};
}