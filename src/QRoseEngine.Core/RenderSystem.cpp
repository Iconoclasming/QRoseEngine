#include "RenderSystem.hpp"

using namespace QRose;

RenderSystem::RenderSystem(MPtr<Render> pRender, MPtr<EntitiesComponentsService> pEntitiesComponentsService)
	: pRender(pRender), pEntitiesComponentsService(pEntitiesComponentsService),
	componentAddedDelegate(Delegate<void, const ComponentEventArgs&>::Bind<RenderSystem, &RenderSystem::ComponentAddedHandler>(this)),
	componentRemovedDelegate(Delegate<void, const ComponentEventArgs&>::Bind<RenderSystem, &RenderSystem::ComponentRemovedHandler>(this)),
	componentUpdatedDelegate(Delegate<void, const ComponentUpdatedEventArgs&>::Bind<RenderSystem, &RenderSystem::ComponentUpdatedHandler>(this)),
	entityRemovedDelegate(Delegate<void, const EntityEventArgs&>::Bind<RenderSystem, &RenderSystem::EntityRemovedHandler>(this))
{
	if(pRender == nullptr)
	{
		throw std::invalid_argument("pRender == nullptr");
	}
	if(pEntitiesComponentsService == nullptr)
	{
		throw std::invalid_argument("pEntitiesComponentsService == nullptr");
	}

	pEntitiesComponentsService->GetComponentAddedEvent() += componentAddedDelegate;
	pEntitiesComponentsService->GetComponentRemovedEvent() += componentRemovedDelegate;
	pEntitiesComponentsService->GetComponentUpdatedEvent() += componentUpdatedDelegate;
	pEntitiesComponentsService->GetEntityRemovedEvent() += entityRemovedDelegate;
}

RenderSystem::~RenderSystem()
{
	pEntitiesComponentsService->GetComponentAddedEvent() -= componentAddedDelegate;
	pEntitiesComponentsService->GetComponentRemovedEvent() -= componentRemovedDelegate;
	pEntitiesComponentsService->GetComponentUpdatedEvent() -= componentUpdatedDelegate;
	pEntitiesComponentsService->GetEntityRemovedEvent() -= entityRemovedDelegate;
}

void RenderSystem::Update(double millisecondsElapsed)
{
	pRender->ClearView();
	pRender->BeginDrawing();
	for each (const auto& toDrawTuple in toDraw)
	{
		MeshComponent meshComponent = std::get<1>(toDrawTuple);
		TransformationComponent transform = std::get<2>(toDrawTuple);
		pRender->DrawMesh(meshComponent.GetMeshId(), transform.GetPosition());
	}
	pRender->Present();
}

void RenderSystem::ComponentAddedHandler(const ComponentEventArgs& a)
{
	AddEntityIfItMatches(a.GetEntityId());
}

void RenderSystem::ComponentRemovedHandler(const ComponentEventArgs& a)
{
	Uuid entityId = a.GetEntityId();
	// TODO: remove components for that entity if they are cached
}

void RenderSystem::ComponentUpdatedHandler(const ComponentUpdatedEventArgs& a)
{
}

void RenderSystem::EntityRemovedHandler(const EntityEventArgs& a)
{
}

void RenderSystem::AddEntityIfItMatches(const Uuid& entityId)
{
	auto entitiesInScene = pEntitiesComponentsService->GetEntities();
	// if this entity isn't present on current scene then return
	if (!QCE::ContainsIf(entitiesInScene, [&entityId](const Entity& entity)
	{
		return entity.GetID() == entityId;
	}))
	{
		return;
	}

	// if this entity is not already added
	if (!QCE::ContainsIf(toDraw, [&entityId](const std::tuple<Uuid, MeshComponent, TransformationComponent>& tupleToDraw)
	{
		return std::get<0>(tupleToDraw) == entityId;
	}))
	{
		// if this entity contains all the desired components
		if (pEntitiesComponentsService->IsComponentPresentForEntity<MeshComponent>(entityId)
			&& pEntitiesComponentsService->IsComponentPresentForEntity<TransformationComponent>(entityId))
		{
			MeshComponent meshComponent = pEntitiesComponentsService->GetComponentForEntity<MeshComponent>(entityId);
			TransformationComponent transformationComponent = pEntitiesComponentsService->GetComponentForEntity<TransformationComponent>(entityId);
			toDraw.push_back(std::tuple<Uuid, MeshComponent, TransformationComponent>(entityId, meshComponent,
						transformationComponent));
		}
	}

}