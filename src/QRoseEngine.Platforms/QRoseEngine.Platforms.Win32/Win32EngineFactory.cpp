#include "EngineFactory.hpp"
#include "QRoseEngine.Platforms.Win32/Win32Engine.hpp"

using namespace QRose;

Engine* EngineFactory::CreateEngine(const GraphicsDesc& graphicsDesc)
{
	ECService* pEcService = new ECService(ManagedPtr<EntitiesRepository>(new EntitiesRepository()),
		ManagedPtr<ComponentsRepository>(new ComponentsRepository()), 
		ManagedPtr<EntitiesComponentsRepository>(new EntitiesComponentsRepository()));
	return new Win32Engine(pEcService);
}
