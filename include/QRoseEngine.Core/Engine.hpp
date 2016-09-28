#pragma once

#include <vector>
#include "Scene.hpp"
#include "EntitiesComponentsService.hpp"
#include "Vector.hpp"

namespace QRose
{
	class Engine
	{
	public:
		Engine(MPtr<EntitiesComponentsService> pEntitiesComponentsService);
		virtual ~Engine();

		virtual void PresentScene() abstract;
		virtual Uuid LoadMesh(const std::string& path) abstract;
		virtual Uuid LoadBoxMesh(const Vector3& size) abstract;

		Entity CreateEntity();

		template<typename TComponent>
		void AttachComponent(const Entity& entity, const TComponent& component)
		{
			pEntitiesComponentsService->AttachComponent(entity, component);
		}

		template<typename TComponent>
		TComponent GetComponentForEntity(const Uuid& entityId)
		{
			return pEntitiesComponentsService->GetComponentForEntity<TComponent>(entityId);
		}

	protected:
		MPtr<EntitiesComponentsService> pEntitiesComponentsService;
	};
}