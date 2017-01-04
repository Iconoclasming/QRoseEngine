#include "QRoseEngine.Platform.Agnostic/AgnosticEngine.hpp"

#include <QRoseEngine.Graphics/RenderSystem.hpp>
#include <QRoseEngine.Platform/Scene.hpp>

using namespace QRose;

AgnosticEngine::AgnosticEngine(Ptr<EntitiesComponentsService> pEntitiesComponentsService)
	: Engine(pEntitiesComponentsService)
{
}

AgnosticEngine::~AgnosticEngine()
{
}

void AgnosticEngine::Initialize(const GraphicsDesc& graphicsDesc)
{
	pGraphics = Managed<OpenGLGraphics>();
	pGraphics->Initialize(graphicsDesc);
	Ptr<RenderSystem> pRenderSystem = Managed<RenderSystem>(pGraphics->GetRender(), pEntitiesComponentsService);
	systems.push_back(pRenderSystem);
}

Uuid AgnosticEngine::LoadMesh(const std::string& path)
{
	return pGraphics->LoadMesh(path);
}

Uuid AgnosticEngine::LoadBoxMesh(const Vector3& size)
{
	return pGraphics->LoadBoxMesh(size);
}

void AgnosticEngine::PresentScene(Scene& scene)
{
	Engine::SetScene(scene);
	scene.OnLoad();

	while (!glfwWindowShouldClose(pGraphics->GetWindow()))
	{
		glfwPollEvents();

		scene.OnUpdate(0.0);
		for(auto& system : systems)
		{
			system->Update(0.0);
		}

	}
	glfwTerminate();
}