#pragma once

#include "System.hpp"
#include "Render.hpp"
#include "EntitiesComponentsService.hpp"

namespace QRose
{
	class RenderSystem : public System
	{
	public:
		RenderSystem(ManagedPtr<Render> pRender, ManagedPtr<EntitiesComponentsService> pEntitiesComponentsService);
		virtual ~RenderSystem();

		void Update(double millisecondsElapsed) override;

	private:
		ManagedPtr<Render> pRender;
		ManagedPtr<EntitiesComponentsService> pEntitiesComponentsService;
	};
}
