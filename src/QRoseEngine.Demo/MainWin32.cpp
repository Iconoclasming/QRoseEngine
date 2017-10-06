#include <fstream>
#include <json/json.hpp>
#include <QRoseEngine.Graphics.OpenGL/OpenGLGraphics.hpp>
#include <QRoseEngine.Graphics/RenderSystem.hpp>
#include <QRoseEngine.Demo/MovementSystem.hpp>
#include <QRoseEngine.Demo/GLFWInput.hpp>
#include <QRoseEngine.Core/Storage.hpp>

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
	Ptr<Input> pGLFWInput = NewManaged<GLFWInput>(pGraphics->GetWindow());

	Ptr<World> pWorld = NewManaged<World>();
	//pWorld->Add(new Storage<MovableComponent>());
	pWorld->Add(new Storage<CameraComponent>());
	pWorld->Add(new Storage<TransformComponent>());
	pWorld->Add(new Storage<MeshComponent>());

	Ptr<RenderSystem> pRenderSystem = NewManaged<RenderSystem>(pGraphics->GetRender(), pWorld);

	MeshHandle boxMeshId = pGraphics->CreateBoxMesh(Vector3(0.5f, 0.5f, 0.5f));

	const EntityHandle cameraEntityId = 1;
	CameraComponent cameraComponent(cameraEntityId, 45.0f);
	pWorld->Get<Storage<CameraComponent>>()->Add(cameraComponent);
	TransformComponent cameraTransformComponent(cameraEntityId);
	cameraTransformComponent.position = Vector3(0.5f, 0.0f, -3.0f);
	pWorld->Get<Storage<TransformComponent>>()->Add(cameraTransformComponent);

	const EntityHandle boxEntityId = 2;
	TransformComponent boxTransformComponent(boxEntityId);
	pWorld->Get<Storage<TransformComponent>>()->Add(boxTransformComponent);
	MeshComponent meshComponent(boxEntityId, boxMeshId);
	pWorld->Get<Storage<MeshComponent>>()->Add(meshComponent);

	double lastFrame = glfwGetTime();
	double currentFrame = lastFrame;
	double dt = 0.0f;
	float angle = 0.0f;
	while (!glfwWindowShouldClose(pGraphics->GetWindow()))
	{
		currentFrame = glfwGetTime();
		dt = currentFrame - lastFrame;
		lastFrame = currentFrame;
		glfwPollEvents();

		TransformComponent& transform = pWorld->Get<Storage<TransformComponent>>()->Get(boxEntityId);
		angle += 0.005f;
		transform.rotation = Vector4::FromAxisAngle(Vector3(0.0f, 1.0f, 0.0f), angle);

		pRenderSystem->Update(dt);
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