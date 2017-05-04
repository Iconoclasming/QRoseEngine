#include <QRoseEngine.Demo.Game/DemoGame.hpp>

#include <QRoseCore.hpp>

using namespace QRose;

float angle = 0.78539f;

DemoGame::DemoGame(Ptr<Graphics> pGraphics, Ptr<Render> pRender, Ptr<Input> pInput)
	: pGraphics(pGraphics), pRender(pRender), pInput(pInput)
{
}

DemoGame::~DemoGame()
{
}

void DemoGame::Load()
{
	pRenderSystem = NewManaged<RenderSystem>(pRender, world.GetTransformationComponentManager(),
		world.GetMeshComponentManager(), world.GetCameraComponentManager());
	pMovementSystem = NewManaged<MovementSystem>(pInput, world.GetMovableComponentManager(),
		world.GetTransformationComponentManager());

	Handle boxMeshId = pGraphics->CreateBoxMesh(Vector3(0.5f, 0.5f, 0.5f));

	entity1 = Handle();
	TransformationComponent& entity1Transform = world.GetTransformationComponentManager()->CreateComponent(entity1);
	entity1Transform.position = Vector3(0.5, 0.0, 0.0);
	entity1Transform.rotation = Vector4::FromAxisAngle(Vector3(0.0f, 0.0f, 1.0f), angle);
	entity1Transform.scale = Vector3(1.5f, 0.5f, 0.5f);
	world.GetMeshComponentManager()->CreateComponent(entity1, boxMeshId);
	world.GetMovableComponentManager()->CreateComponent(entity1, 1.0f, 1.0f, 1.0f, 1.0f, Vector3(0.0f, 0.0f, -1.0f),
		Vector3(0.0f, 1.0f, 0.0f));

	cameraEntity = Handle();
	world.GetCameraComponentManager()->CreateComponent(cameraEntity, 45.0f);	// TODO: handle flipped z-axis (OpenGL vs DirectX) - and not here
	TransformationComponent& cameraTransform = world.GetTransformationComponentManager()->CreateComponent(cameraEntity);
	cameraTransform.position = Vector3(0.5f, 0.0f, -3.0f);
}

void DemoGame::Update(double millisecondsElapsed)
{
	TransformationComponent& entity1Transform = world.GetTransformationComponentManager()->GetComponent(entity1);
	angle += 0.0005f;
	entity1Transform.rotation = Vector4::FromAxisAngle(Vector3(0.0f, 0.0f, 1.0f), angle);
	pRenderSystem->Update(millisecondsElapsed);
	pMovementSystem->Update(millisecondsElapsed);
}