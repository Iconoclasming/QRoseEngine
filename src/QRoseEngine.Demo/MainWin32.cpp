#include <fstream>
#include <json/json.hpp>
#include <QRoseEngine.Graphics.OpenGL/OpenGLGraphics.hpp>
#include <QRoseEngine.Graphics/RenderSystem.hpp>
#include <QRoseEngine.Demo.Game/DemoGame.hpp>
#include <QRoseEngine.Demo.Game/MovementSystem.hpp>
#include <QRoseEngine.Demo/GLFWInput.hpp>

using namespace QRose;

struct Config
{
	std::string assetsRoot;
};

Config LoadConfig(const std::string& pathToConfig);

int main()
{
	WindowDesc windowDesc("Awesome Sample Game", Size<int>(800, 600));
	GraphicsDesc graphicsDesc(windowDesc, Color::Aqua);
	Config config = LoadConfig("config.json");
	Ptr<OpenGLGraphics> pGraphics = NewManaged<OpenGLGraphics>();
	pGraphics->Initialize(graphicsDesc, config.assetsRoot);
	Ptr<DemoGame> pGame = NewManaged<DemoGame>(pGraphics);
	pGame->Load();
	Ptr<RenderSystem> pRenderSystem = NewManaged<RenderSystem>(pGraphics->GetRender(), 
		pGame->GetTransformationComponentManager(),
		pGame->GetMeshComponentManager(), pGame->GetCameraComponentManager());
	Ptr<Input> pGLFWInput = NewManaged<GLFWInput>(pGraphics->GetWindow());
	MovementSystem movementSystem(pGLFWInput, pGame->GetMovableComponentManager(),
		pGame->GetTransformationComponentManager());


	double lastFrame = glfwGetTime();
	double currentFrame = lastFrame;
	double dt = 0.0f;
	while (!glfwWindowShouldClose(pGraphics->GetWindow()))
	{
		currentFrame = glfwGetTime();
		dt = currentFrame - lastFrame;
		lastFrame = currentFrame;
		glfwPollEvents();
		pGame->Update(dt);
		pRenderSystem->Update(dt);
		movementSystem.Update(dt);
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