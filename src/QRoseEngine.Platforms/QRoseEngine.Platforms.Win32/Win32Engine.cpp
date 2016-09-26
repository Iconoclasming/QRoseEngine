#include "QRoseEngine.Platforms.Win32/Win32Engine.hpp"

using namespace QRose;

Win32Engine::Win32Engine(ECService* pEcService, std::vector<System*> systems) : Engine(pEcService, systems)
{
}

Win32Engine::~Win32Engine()
{
}

void Win32Engine::PresentScene(const Scene& scene)
{
}