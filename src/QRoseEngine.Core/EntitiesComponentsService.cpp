#include "EntitiesComponentsService.hpp"

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
}

void EntitiesComponentsService::AddEntity(const Entity& entity)
{
	if (!pEntitiesRepository->Contains(entity))
	{
		pEntitiesRepository->Add(entity);	
	}
}