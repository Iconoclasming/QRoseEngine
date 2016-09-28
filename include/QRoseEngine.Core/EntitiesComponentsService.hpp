#pragma once

#include "Entity.hpp"
#include "EntitiesComponentsRepository.hpp"
#include "ComponentsRepository.hpp"
#include "EntitiesRepository.hpp"
#include "ManagedPtr.hpp"

namespace QRose
{
	class EntitiesComponentsService
	{
	public:
		EntitiesComponentsService(MPtr<EntitiesRepository> pEntitiesRepository,
			MPtr<ComponentsRepository> pComponentsRepository,
			MPtr<EntitiesComponentsRepository> pEntitiesComponentsRepository);

		void AddEntity(const Entity& entity);

		template<typename TComponent>
		void AttachComponent(const Entity& entity, const TComponent& component);

	private:
		MPtr<EntitiesRepository> pEntitiesRepository;
		MPtr<ComponentsRepository> pComponentsRepository;
		MPtr<EntitiesComponentsRepository> pEntitiesComponentsRepository;
	};

	template <typename TComponent>
	void EntitiesComponentsService::AttachComponent(const Entity& entity, const TComponent& component)
	{
		if (pEntitiesRepository->Contains(entity))
		{
			if(!pComponentsRepository->Contains(component))
			{
				pComponentsRepository->Add(component);
			}
			pEntitiesComponentsRepository->Add(entity.GetID(), component.GetID());
		}
	}
}