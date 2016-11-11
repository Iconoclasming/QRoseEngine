#include "QRoseEngine.Core/EntitiesComponentsService.hpp"

using namespace QRose;

EntitiesComponentsService::EntitiesComponentsService(MPtr<EntitiesRepository> pEntitiesRepository,
	MPtr<ComponentsRepository> pComponentsRepository,
	MPtr<EntitiesComponentsRepository> pEntitiesComponentsRepository)
{
	if(pEntitiesRepository == nullptr)
	{
		throw std::invalid_argument("pEntitiesRepository == null");
	}
	if (pComponentsRepository == nullptr)
	{
		throw std::invalid_argument("pComponentsRepository == null");
	}
	if (pEntitiesComponentsRepository == nullptr)
	{
		throw std::invalid_argument("pEntitiesComponentsRepository == null");
	}
	this->pEntitiesRepository = pEntitiesRepository;
	this->pComponentsRepository = pComponentsRepository;
	this->pEntitiesComponentsRepository = pEntitiesComponentsRepository;

	componentAddedEvent = new Event<ComponentEventArgs>(&componentAddedEventInvoker);
	componentRemovedEvent = new Event<ComponentEventArgs>(&componentRemovedEventInvoker);
	componentUpdatedEvent = new Event<ComponentUpdatedEventArgs>(&componentUpdatedEventInvoker);
	entityAddedEvent = new Event<EntityEventArgs>(&entityAddedEventInvoker);
	entityRemovedEvent = new Event<EntityEventArgs>(&entityRemovedEventInvoker);
}

EntitiesComponentsService::~EntitiesComponentsService()
{
	delete componentAddedEvent;
	delete componentRemovedEvent;
	delete componentUpdatedEvent;
	delete entityAddedEvent;
	delete entityRemovedEvent;
}

void EntitiesComponentsService::AddEntity(const Entity& entity)
{
	if (!pEntitiesRepository->Contains(entity))
	{
		pEntitiesRepository->Add(entity);	
	}
}

std::vector<Entity> EntitiesComponentsService::GetEntities() const
{
	return pEntitiesRepository->GetEntities();
}