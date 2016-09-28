#include "QRoseEngine.Platforms.Win32/Win32Engine.hpp"

using namespace QRose;

Win32Engine::Win32Engine(MPtr<EntitiesComponentsService> pEntitiesComponentsService, std::vector<System*> systems)
	: Engine(pEntitiesComponentsService, systems)
{
}

Win32Engine::~Win32Engine()
{
}

void Win32Engine::PresentScene(const Scene& scene)
{
}