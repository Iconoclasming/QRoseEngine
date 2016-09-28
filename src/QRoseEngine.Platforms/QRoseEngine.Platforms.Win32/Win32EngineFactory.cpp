#include "QRoseEngine.Platforms.Win32/Win32Engine.hpp"
#include <EngineFactory.hpp>
#include <RenderSystem.hpp>
#include <ManagedPtr.hpp>

using namespace QRose;

MPtr<Engine> EngineFactory::CreateEngine(const GraphicsDesc& graphicsDesc)
{
	MPtr<EntitiesRepository> pEntitiesRepository = Managed<EntitiesRepository>();
	MPtr<ComponentsRepository> pComponentsRepository = Managed<ComponentsRepository>();
	MPtr<EntitiesComponentsRepository> pEntitiesComponentsRepository = Managed<EntitiesComponentsRepository>();
	MPtr<EntitiesComponentsService> pEntitiesComponentsService = Managed<EntitiesComponentsService>(pEntitiesRepository,
		pComponentsRepository, pEntitiesComponentsRepository);
	std::vector<System*> systems;
	systems.push_back(new RenderSystem(Managed<Render>(), pEntitiesComponentsService));
	return Managed<Win32Engine>(pEntitiesComponentsService, systems);
}