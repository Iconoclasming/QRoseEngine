#include "Win32Engine.hpp"
#include <RenderSystem.hpp>

using namespace QRose;

Win32Engine::Win32Engine(MPtr<EntitiesComponentsService> pEntitiesComponentsService)
	: Engine(pEntitiesComponentsService)
{
}

Win32Engine::~Win32Engine()
{
}

void Win32Engine::Initialize(const GraphicsDesc& graphicsDesc)
{
	pGraphics = std::make_shared<OpenGLGraphics>();
	pGraphics->Initialize(graphicsDesc);
	MPtr<RenderSystem> pRenderSystem = Managed<RenderSystem>(pGraphics->GetRender(), pEntitiesComponentsService);
	systems.push_back(pRenderSystem);
}

Uuid Win32Engine::LoadMesh(const std::string& path)
{
	return pGraphics->LoadMesh(path);
}

Uuid Win32Engine::LoadBoxMesh(const Vector3& size)
{
	return pGraphics->LoadBoxMesh(size);
}

void Win32Engine::PresentScene()
{
	while (!glfwWindowShouldClose(pGraphics->GetWindow()))
	{
		glfwPollEvents();

		for(auto& system : systems)
		{
			system->Update(0.0);
		}

	}
	glfwTerminate();
}