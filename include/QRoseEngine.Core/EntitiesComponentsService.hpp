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
		inline TComponent GetComponentForEntity(const Uuid& entityId);

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
			if(!pComponentsRepository->Contains(component.GetID()))
			{
				pComponentsRepository->Add(component);
			}
			pEntitiesComponentsRepository->Add(entity.GetID(), TComponent::ComponentTypeId, component.GetID());
			componentAddedEventInvoker.Invoke(ComponentEventArgs(TComponent::ComponentTypeId, entity.GetID(),
				component.GetID()));
		}
	}

	template <typename TComponent>
	bool EntitiesComponentsService::IsComponentPresentForEntity(const Uuid& entityId)
	{
		return pEntitiesComponentsRepository->ContainsComponentType(entityId, TComponent::ComponentTypeId);
	}

	template <typename TComponent>
	TComponent EntitiesComponentsService::GetComponent(const Uuid& componentId)
	{
		return pComponentsRepository->Get<TComponent>(componentId);
	}

	template <typename TComponent>
	TComponent EntitiesComponentsService::GetComponentForEntity(const Uuid& entityId)
	{
		if (!IsComponentPresentForEntity<TComponent>(entityId))
		{
			throw std::invalid_argument("component of type " + TComponent::ComponentName
				+ " is not present for entity " + entityId.ToString());
		}
		Uuid componentTypeId = TComponent::ComponentTypeId;
		std::list<std::tuple<Uuid, Uuid, Uuid>> entitiesComponentsMap = pEntitiesComponentsRepository->GetEntitiesComponentsMapping();
		std::tuple<Uuid, Uuid, Uuid> entityComponent = QCE::Find<std::tuple<Uuid, Uuid, Uuid>>(entitiesComponentsMap,
			[&entityId, &componentTypeId](const std::tuple<Uuid, Uuid, Uuid>& entityComponentLocal)
		{
			return std::get<0>(entityComponentLocal) == entityId && std::get<1>(entityComponentLocal) == componentTypeId;
		});
		return GetComponent<TComponent>(std::get<2>(entityComponent));
	}
}