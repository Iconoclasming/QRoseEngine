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
		RenderSystem(MPtr<Render> pRender, MPtr<EntitiesComponentsService> pEntitiesComponentsService);
		virtual ~RenderSystem();

		void Update(double millisecondsElapsed) override;

	private:
		MPtr<Render> pRender;
		MPtr<EntitiesComponentsService> pEntitiesComponentsService;

		// subscribe to ComponentAdded, ComponentRemoved, ComponentUpdated
		// when desired components tuples added to one entity, add these components to corresponding vector
		std::vector<std::tuple<Uuid, MeshComponent, TransformationComponent>> toDraw;
	};
}
