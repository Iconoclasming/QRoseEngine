#pragma once

#include <vector>
#include "Scene.hpp"
#include "ECService.hpp"
#include "System.hpp"

namespace QRose
{
	class Engine
	{
	public:
		Engine(ECService* pEcService, std::vector<System*> systems) : pEcService(pEcService) {}
		virtual ~Engine() {}

		virtual void PresentScene(const Scene& scene) abstract;

		Uuid LoadMesh(const std::string& path) { return Uuid::GenerateUuid(); }

		Entity CreateEntity()
		{
			Entity entity;
			pEcService->AddEntity(entity);
			return entity;
		}

		template<typename TComponent>
		void AttachComponent(const Entity& entity, const TComponent& component)
		{
			pEcService->AttachComponent(entity, component);
		}

	protected:
		std::vector<System*> systems;

	private:
		ECService* pEcService;
	};
}