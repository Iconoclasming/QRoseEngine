#include "RenderSystem.hpp"

using namespace QRose;

RenderSystem::RenderSystem(MPtr<Render> pRender, MPtr<EntitiesComponentsService> pEntitiesComponentsService)
	: pRender(pRender), pEntitiesComponentsService(pEntitiesComponentsService)
{
}

RenderSystem::~RenderSystem()
{
}

void RenderSystem::Update(double millisecondsElapsed)
{
}