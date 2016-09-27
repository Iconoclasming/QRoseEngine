#include "EngineFactory.hpp"
#include "QRoseEngine.Platforms.Win32/Win32Engine.hpp"
#include <RenderSystem.hpp>

using namespace QRose;

ManagedPtr<Engine> EngineFactory::CreateEngine(const GraphicsDesc& graphicsDesc)
{
	ManagedPtr<EntitiesRepository> pEntitiesRepository = Managed<EntitiesRepository>();
	ManagedPtr<ComponentsRepository> pComponentsRepository = Managed<ComponentsRepository>();
	ManagedPtr<EntitiesComponentsRepository> pEntitiesComponentsRepository = Managed<EntitiesComponentsRepository>();
	ManagedPtr<EntitiesComponentsService> pEntitiesComponentsService = Managed<EntitiesComponentsService>(pEntitiesRepository,
		pComponentsRepository, pEntitiesComponentsRepository);
	std::vector<System*> systems;
	systems.push_back(new RenderSystem(Managed<Render>(), pEntitiesComponentsService));
	return Managed<Win32Engine>(pEntitiesComponentsService, systems);
}