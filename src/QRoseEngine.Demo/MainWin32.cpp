#include <fstream>
#include <json/json.hpp>
#include <QRoseEngine.Graphics.OpenGL/OpenGLGraphics.hpp>
#include <QRoseEngine.Graphics/RenderSystem.hpp>
#include <QRoseEngine.Demo.Game/DemoGame.hpp>
#include <QRoseEngine.Demo.Application/EntitiesComponentsService.hpp>

using namespace QRose;

struct Config
{
	std::string assetsRoot;
};

Config LoadConfig(const std::string& pathToConfig);

int main()
{
	Ptr<EntitiesComponentsService> pEntitiesComponentsService = NewManaged<EntitiesComponentsService>();
	WindowDesc windowDesc("Awesome Sample Game", Size<int>(800, 600));
	GraphicsDesc graphicsDesc(windowDesc, Color::Aqua);
	Config config = LoadConfig("config.json");
	Ptr<OpenGLGraphics> pGraphics = NewManaged<OpenGLGraphics>();
	pGraphics->Initialize(graphicsDesc, config.assetsRoot);
	Ptr<RenderSystem> pRenderSystem = NewManaged<RenderSystem>(pGraphics->GetRender(), 
		pEntitiesComponentsService->GetManager<TransformationComponent>(),
		pEntitiesComponentsService->GetManager<MeshComponent>());
	Ptr<DemoGame> pGame = NewManaged<DemoGame>(pEntitiesComponentsService, pGraphics,
		pEntitiesComponentsService->GetManager<TransformationComponent>(),
		pEntitiesComponentsService->GetManager<MeshComponent>());

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

Config LoadConfig(const std::string& pathToConfig)
{
	std::fstream inputFileStream(pathToConfig, std::fstream::in);
	Config config;
	if (inputFileStream.is_open())
	{
		nlohmann::json jsonConfig(inputFileStream);
		auto assetsRootJson = jsonConfig["AssetsRoot"];
		if (!assetsRootJson.is_null())
		{
			config.assetsRoot = assetsRootJson.get<std::string>();
		}
		inputFileStream.close();
	}
	return config;
}