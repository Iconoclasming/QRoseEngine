#include "EngineFactory.hpp"
#include "QRoseEngine.Platforms.Win32/Win32Engine.hpp"

using namespace QRose;

Engine* EngineFactory::CreateEngine(const GraphicsDesc& graphicsDesc)
{
	ManagedPtr<EntitiesComponentsService> pEcService = new EntitiesComponentsService(ManagedPtr<EntitiesRepository>(new EntitiesRepository()),
		ManagedPtr<ComponentsRepository>(new ComponentsRepository()), 
		ManagedPtr<EntitiesComponentsRepository>(new EntitiesComponentsRepository()));
	std::vector<System*> systems;
	return new Win32Engine(pEcService, systems);
}
