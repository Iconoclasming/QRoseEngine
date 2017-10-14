#include <fstream>
#include <json/json.hpp>
#include <QRoseEngine.Graphics.OpenGL/OpenGlGraphics.hpp>
#include <QRoseEngine.Graphics/RenderSystem.hpp>
#include <QRoseEngine.Demo/MovementSystem.hpp>
#include <QRoseEngine.Demo/GlfwInput.hpp>
#include <QRoseEngine.Core/Storage.hpp>

using namespace QRose;

struct Config
{
	std::string assetsRoot;
};

Config LoadConfig(const std::string& pathToConfig);

int main()
{
	Config config = LoadConfig("config.json");

	WindowDesc windowDesc("Awesome Sample Game", Size<int>(800, 600));
	GraphicsDesc graphicsDesc(windowDesc, Color::Aqua);
	Ptr<OpenGlGraphics> pGraphics = NewManaged<OpenGlGraphics>();
	pGraphics->Initialize(graphicsDesc, config.assetsRoot);
	Ptr<Input> pGlfwInput = NewManaged<GlfwInput>(pGraphics->GetWindow());

	Ptr<World> pWorld = NewManaged<World>();
	pWorld->Add(new Storage<CameraComponent>());
	pWorld->Add(new Storage<TransformComponent>());
	pWorld->Add(new Storage<MeshComponent>());
	pWorld->Add(new Storage<MovableComponent>());
	pWorld->Add(new Storage<LightComponent>());

	Ptr<MovementSystem> pMovementSystem = NewManaged<MovementSystem>(pGlfwInput, pWorld);
	Ptr<RenderSystem> pRenderSystem = NewManaged<RenderSystem>(pGraphics->GetRender(), pWorld);

	MeshHandle boxMeshId = pGraphics->CreateBoxMesh(Vector3(0.5f, 0.5f, 0.5f));

	const EntityHandle cameraEntityId = 1;
	CameraComponent cameraComponent(cameraEntityId, 45.0f);
	pWorld->Get<Storage<CameraComponent>>()->Add(cameraComponent);
	TransformComponent cameraTransformComponent(cameraEntityId);
	cameraTransformComponent.position = Vector3(0.5f, 0.0f, -3.0f);
	pWorld->Get<Storage<TransformComponent>>()->Add(cameraTransformComponent);
	MovableComponent movableComponent(cameraEntityId, 1.0f, 1.0f, 1.0f, 1.0f, Vector3(0.0f, 0.0f, -1.0f),
		Vector3(0.0f, 1.0f, 0.0f));
	pWorld->Get<Storage<MovableComponent>>()->Add(movableComponent);

	const EntityHandle boxEntityId = 2;
	TransformComponent boxTransformComponent(boxEntityId);
	pWorld->Get<Storage<TransformComponent>>()->Add(boxTransformComponent);
	MeshComponent meshComponent(boxEntityId, boxMeshId);
	//pWorld->Get<Storage<MeshComponent>>()->Add(meshComponent);

	MeshHandle humanMeshId = pGraphics->LoadMesh(config.assetsRoot + "/models/BaseHuman.blend");
	const EntityHandle humanEntityId = 3;
	TransformComponent humanTransformComponent(humanEntityId);
	humanTransformComponent.rotation = Vector4::FromAxisAngle(Vector3(-1.0f, 0.0f, 0.0f), 90.0f);
	pWorld->Get<Storage<TransformComponent>>()->Add(humanTransformComponent);
	MeshComponent humanMeshComponent(humanEntityId, humanMeshId);
	pWorld->Get<Storage<MeshComponent>>()->Add(humanMeshComponent);

	const EntityHandle lightEntityId = 4;
	TransformComponent lightTransformComponent(lightEntityId);
	lightTransformComponent.position = Vector3(0.0f, -15.0f, 20.0f);
	LightComponent lightComponent(lightEntityId);
	pWorld->Get<Storage<TransformComponent>>()->Add(lightTransformComponent);
	pWorld->Get<Storage<LightComponent>>()->Add(lightComponent);

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
		
		pMovementSystem->Update(dt);

		TransformComponent& transform = pWorld->Get<Storage<TransformComponent>>()->Get(humanEntityId);
		angle += 0.005f;
		transform.rotation = Vector4::FromAxisAngle(Vector3(1.0f, 0.0f, 0.0f), angle);
		
		pGraphics->GetRender()->ClearView();
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