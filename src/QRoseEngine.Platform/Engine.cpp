#include <QRoseEngine.Platform/Engine.hpp>

#include <QRoseEngine.Platform/Scene.hpp>

using namespace QRose;

Engine::Engine(Ptr<EntitiesComponentsService> pEntitiesComponentsService)
	: pEntitiesComponentsService(pEntitiesComponentsService)
{
}

Engine::~Engine()
{
}

void Engine::SetScene(Scene& scene)
{
	scene.SetEngine(shared_from_this());
}
