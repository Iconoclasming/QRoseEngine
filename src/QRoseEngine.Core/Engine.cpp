#include "QRoseEngine.Core/Engine.hpp"

using namespace QRose;

Engine::Engine(MPtr<EntitiesComponentsService> pEntitiesComponentsService)
	: pEntitiesComponentsService(pEntitiesComponentsService)
{
}

Engine::~Engine()
{
}

Entity Engine::CreateEntity()
{
	Entity entity;
	pEntitiesComponentsService->AddEntity(entity);
	return entity;
}