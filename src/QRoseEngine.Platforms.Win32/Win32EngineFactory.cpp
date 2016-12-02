#include <QRoseEngine.Core/EngineFactory.hpp>
#include "QRoseEngine.Platforms.Win32/Win32Engine.hpp"

using namespace QRose;

Ptr<Engine> EngineFactory::CreateEngine(const GraphicsDesc& graphicsDesc)
{
	Ptr<EntitiesComponentsService> pEntitiesComponentsService = Managed<EntitiesComponentsService>();
	Ptr<Win32Engine> pEngine = Managed<Win32Engine>(pEntitiesComponentsService);
	pEngine->Initialize(graphicsDesc);
	return pEngine;
}