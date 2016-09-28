#pragma once

#include <vector>
#include "Scene.hpp"
#include "EntitiesComponentsService.hpp"
#include "System.hpp"

namespace QRose
{
	class Engine
	{
	public:
		Engine(MPtr<EntitiesComponentsService> pEntitiesComponentsService, std::vector<System*> systems) 
			: pEntitiesComponentsService(pEntitiesComponentsService) {}
		virtual ~Engine() {}

		virtual void PresentScene(const Scene& scene) abstract;

		Uuid LoadMesh(const std::string& path) { return Uuid::GenerateUuid(); }

		Entity CreateEntity()
		{
			Entity entity;
			pEntitiesComponentsService->AddEntity(entity);
			return entity;
		}

		template<typename TComponent>
		void AttachComponent(const Entity& entity, const TComponent& component)
		{
			pEntitiesComponentsService->AttachComponent(entity, component);
		}

	protected:
		std::vector<System*> systems;

	private:
		MPtr<EntitiesComponentsService> pEntitiesComponentsService;
	};
}