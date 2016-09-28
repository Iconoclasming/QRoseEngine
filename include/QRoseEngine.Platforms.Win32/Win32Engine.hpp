#pragma once

#include "Engine.hpp"
#include "ManagedPtr.hpp"
#include <System.hpp>
#include <OpenGLGraphics.hpp>
#include <GraphicsDesc.hpp>

namespace QRose
{
	class Win32Engine : public Engine
	{
	public:
		Win32Engine(MPtr<EntitiesComponentsService> pEntitiesComponentsService, const GraphicsDesc& graphicsDesc);
		virtual ~Win32Engine();

		void PresentScene() override;

	private:
		std::vector<System*> systems;

		MPtr<OpenGLGraphics> pGraphics;
	};
}