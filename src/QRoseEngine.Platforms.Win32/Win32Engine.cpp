#include "Win32Engine.hpp"

using namespace QRose;

Win32Engine::Win32Engine(MPtr<EntitiesComponentsService> pEntitiesComponentsService, const GraphicsDesc& graphicsDesc)
	: Engine(pEntitiesComponentsService)
{
}

Win32Engine::~Win32Engine()
{
}

void Win32Engine::PresentScene()
{
}