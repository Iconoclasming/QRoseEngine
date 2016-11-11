#include <QRoseEngine.Core/EngineFactory.hpp>
#include "QRoseEngine.Platforms.Win32/Win32Engine.hpp"

using namespace QRose;

MPtr<Engine> EngineFactory::CreateEngine(const GraphicsDesc& graphicsDesc)
{
	MPtr<EntitiesRepository> pEntitiesRepository = Managed<EntitiesRepository>();
	MPtr<ComponentsRepository> pComponentsRepository = Managed<ComponentsRepository>();
	MPtr<EntitiesComponentsRepository> pEntitiesComponentsRepository = Managed<EntitiesComponentsRepository>();
	MPtr<EntitiesComponentsService> pEntitiesComponentsService = Managed<EntitiesComponentsService>(pEntitiesRepository,
		pComponentsRepository, pEntitiesComponentsRepository);
	MPtr<Win32Engine> pEngine = Managed<Win32Engine>(pEntitiesComponentsService);
	pEngine->Initialize(graphicsDesc);
	return pEngine;
}