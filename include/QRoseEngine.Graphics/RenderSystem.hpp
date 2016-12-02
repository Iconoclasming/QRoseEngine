#pragma once

#include <vector>
#include <QRoseEngine.Core/System.hpp>
#include <QRoseEngine.Core/EntitiesComponentsService.hpp>
#include "Render.hpp"

namespace QRose
{
	class RenderSystem : public System
	{
	public:
		RenderSystem(Ptr<Render> render, Ptr<EntitiesComponentsService> ecs);
		virtual ~RenderSystem();

		void Update(double millisecondsElapsed) override;

	private:
		Ptr<Render> render;
		Ptr<EntitiesComponentsService> ecs;
	};
}
