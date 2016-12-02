#pragma once

#include <vector>
#include "System.hpp"
#include "Render.hpp"
#include "EntitiesComponentsService.hpp"
#include "Components/MeshComponent.hpp"
#include "Components/TransformationComponent.hpp"

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
