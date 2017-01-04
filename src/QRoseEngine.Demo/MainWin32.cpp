#include <QRoseEngine.Graphics.OpenGL/OpenGLGraphics.hpp>
#include <QRoseEngine.Graphics/RenderSystem.hpp>
#include <QRoseEngine.Demo.Game/DemoGame.hpp>

using namespace QRose;

int main()
{
	Ptr<EntitiesComponentsService> pEntitiesComponentsService = NewManaged<EntitiesComponentsService>();
	WindowDesc windowDesc("Awesome Sample Game", Size<int>(800, 600));
	GraphicsDesc graphicsDesc(windowDesc, Color::Aqua);
	Ptr<OpenGLGraphics> pGraphics = NewManaged<OpenGLGraphics>();
	pGraphics->Initialize(graphicsDesc);
	Ptr<RenderSystem> pRenderSystem = NewManaged<RenderSystem>(pGraphics->GetRender(), pEntitiesComponentsService);
	Ptr<DemoGame> pGame = NewManaged<DemoGame>(pEntitiesComponentsService, pGraphics);

	pGame->Load();

	while (!glfwWindowShouldClose(pGraphics->GetWindow()))
	{
		glfwPollEvents();
		pGame->Update(0.0);
		pRenderSystem->Update(0.0);
	}
	glfwTerminate();
	return 0;
}
