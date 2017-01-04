#include <QRoseEngine.Platform/EngineFactory.hpp>

#include "QRoseEngine.Platform.Agnostic/AgnosticEngine.hpp"

using namespace QRose;

Ptr<Engine> EngineFactory::CreateEngine(const GraphicsDesc& graphicsDesc)
{
	Ptr<EntitiesComponentsService> pEntitiesComponentsService = Managed<EntitiesComponentsService>();
	Ptr<AgnosticEngine> pEngine = Managed<AgnosticEngine>(pEntitiesComponentsService);
	pEngine->Initialize(graphicsDesc);
	return pEngine;
}