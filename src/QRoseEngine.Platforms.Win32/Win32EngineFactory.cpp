#include <EngineFactory.hpp>
#include <ManagedPtr.hpp>
#include <Win32Engine.hpp>

using namespace QRose;

MPtr<Engine> EngineFactory::CreateEngine(const GraphicsDesc& graphicsDesc)
{
	MPtr<EntitiesRepository> pEntitiesRepository = Managed<EntitiesRepository>();
	MPtr<ComponentsRepository> pComponentsRepository = Managed<ComponentsRepository>();
	MPtr<EntitiesComponentsRepository> pEntitiesComponentsRepository = Managed<EntitiesComponentsRepository>();
	MPtr<EntitiesComponentsService> pEntitiesComponentsService = Managed<EntitiesComponentsService>(pEntitiesRepository,
		pComponentsRepository, pEntitiesComponentsRepository);
	return Managed<Win32Engine>(pEntitiesComponentsService, graphicsDesc);
}