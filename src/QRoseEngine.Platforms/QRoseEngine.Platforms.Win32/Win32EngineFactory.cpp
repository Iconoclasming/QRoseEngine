#include "EngineFactory.hpp"
#include "QRoseEngine.Platforms.Win32/Win32Engine.hpp"

using namespace QRose;

Engine* EngineFactory::CreateEngine(const GraphicsDesc& graphicsDesc)
{
	ECService* pEcService = new ECService(new EntitiesRepository(), new ComponentsRepository(), new EntitiesComponentsRepository());
	return new Win32Engine(pEcService);
}
