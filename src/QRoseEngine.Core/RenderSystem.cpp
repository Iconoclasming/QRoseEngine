#include "RenderSystem.hpp"

using namespace QRose;

RenderSystem::RenderSystem(ManagedPtr<Render> pRender,
	ManagedPtr<EntitiesComponentsService> pEntitiesComponentsService)
	: pEntitiesComponentsService(pEntitiesComponentsService)
{
}

RenderSystem::~RenderSystem()
{
}

void RenderSystem::Update(double millisecondsElapsed)
{
}