#pragma once

#include "Entity.hpp"
#include "EntitiesComponentsRepository.hpp"
#include "ComponentsRepository.hpp"
#include "EntitiesRepository.hpp"

namespace QRose
{
	class ECService
	{
	public:
		ECService(EntitiesRepository* pEntitiesRepository, ComponentsRepository* pComponentsRepository,
			EntitiesComponentsRepository* pEntitiesComponentsRepository);

		void AddEntity(const Entity& entity);

		template<typename TComponent>
		void AttachComponent(const Entity& entity, const TComponent& component);

	private:
		EntitiesRepository* pEntitiesRepository;
		ComponentsRepository* pComponentsRepository;
		EntitiesComponentsRepository* pEntitiesComponentsRepository;
	};

	template <typename TComponent>
	void ECService::AttachComponent(const Entity& entity, const TComponent& component)
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