#include "QRoseEngine.Platform/Engine.hpp"

using namespace QRose;

Engine::Engine(Ptr<EntitiesComponentsService> pEntitiesComponentsService)
	: pEntitiesComponentsService(pEntitiesComponentsService)
{
}

Engine::~Engine()
{
}