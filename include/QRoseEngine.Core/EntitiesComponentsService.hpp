#pragma once

#include <vector>
#include <map>
#include "Entity.hpp"
#include "EntitiesComponentsRepository.hpp"
#include "ComponentsRepository.hpp"
#include "EntitiesRepository.hpp"
#include "ManagedPtr.hpp"
#include "ComponentUpdatedEventArgs.hpp"
#include "Event.hpp"
#include "ComponentEventArgs.hpp"
#include "EntityEventArgs.hpp"

namespace QRose
{
	class EntitiesComponentsService
	{
	public:
		EntitiesComponentsService(MPtr<EntitiesRepository> pEntitiesRepository,
			MPtr<ComponentsRepository> pComponentsRepository,
			MPtr<EntitiesComponentsRepository> pEntitiesComponentsRepository);
		~EntitiesComponentsService();

		void AddEntity(const Entity& entity);

		template<typename TComponent>
		void AttachComponent(const Entity& entity, const TComponent& component);
		template<typename TComponent>
		inline bool IsComponentPresentForEntity(const Uuid& entityId);
		template<typename TComponent>
		inline TComponent GetComponent(const Uuid& componentId);
		template<typename TComponent>
		inline TComponent GetComponentForEntity(const Uuid entityId);

		Event<ComponentEventArgs>& GetComponentAddedEvent() { return *componentAddedEvent; }
		Event<ComponentEventArgs>& GetComponentRemovedEvent() { return *componentRemovedEvent; }
		Event<ComponentUpdatedEventArgs>& GetComponentUpdatedEvent() { return *componentUpdatedEvent; }
		Event<EntityEventArgs>& GetEntityAddedEvent() { return *entityAddedEvent; }
		Event<EntityEventArgs>& GetEntityRemovedEvent() { return *entityRemovedEvent; }

		std::vector<Entity> GetEntities() const;

	private:
		MPtr<EntitiesRepository> pEntitiesRepository;
		MPtr<ComponentsRepository> pComponentsRepository;
		MPtr<EntitiesComponentsRepository> pEntitiesComponentsRepository;

		Event<ComponentEventArgs>* componentAddedEvent;
		EventInvoker<ComponentEventArgs> componentAddedEventInvoker;

		Event<ComponentEventArgs>* componentRemovedEvent;
		EventInvoker<ComponentEventArgs> componentRemovedEventInvoker;

		Event<ComponentUpdatedEventArgs>* componentUpdatedEvent;
		EventInvoker<ComponentUpdatedEventArgs> componentUpdatedEventInvoker;

		Event<EntityEventArgs>* entityAddedEvent;
		EventInvoker<EntityEventArgs> entityAddedEventInvoker;

		Event<EntityEventArgs>* entityRemovedEvent;
		EventInvoker<EntityEventArgs> entityRemovedEventInvoker;
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

	template <typename TComponent>
	bool EntitiesComponentsService::IsComponentPresentForEntity(const Uuid& entityId)
	{
		return pEntitiesComponentsRepository->Contains(entityId, TComponent::ComponentTypeId);
	}

	template <typename TComponent>
	TComponent EntitiesComponentsService::GetComponent(const Uuid& componentId)
	{

	}

	template <typename TComponent>
	TComponent EntitiesComponentsService::GetComponentForEntity(const Uuid entityId)
	{
		Uuid componentTypeId = TComponent::ComponentTypeId;
		if (IsComponentPresentForEntity<TComponent>(entityId))
		{
			//std::list<std::tuple<Uuid, Uuid>> entitiesComponentsMap = pEntitiesComponentsRepository->GetEntitiesComponentsMapping();
			//rComponentOut = GetComponent<TComponent>(entitiesComponentsMap[componentTypeId][entityId]);
			//return true;
		}
		else
		{
			//return false;
		}
	}
}