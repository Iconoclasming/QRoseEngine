#pragma once

#include "Scene.hpp"
#include "ECService.hpp"

namespace QRose
{
	class Engine
	{
	public:
		Engine(ECService* pEcService) : pEcService(pEcService) {}
		~Engine() {}

		void PresentScene(const Scene& scene) {}
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

	private:
		ECService* pEcService;
	};
}