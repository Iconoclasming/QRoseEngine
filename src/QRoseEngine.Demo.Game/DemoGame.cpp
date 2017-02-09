#include <QRoseEngine.Demo.Game/DemoGame.hpp>

#include <QRoseCore.hpp>
#include <QRoseEngine.Graphics/Components/MeshComponent.hpp>

using namespace QRose;

float angle = 0.78539f;

DemoGame::DemoGame(Ptr<Graphics> pGraphics)
	: pGraphics(pGraphics)
{
}

DemoGame::~DemoGame()
{
}

void DemoGame::Load()
{
	pTransformationComponentManager = NewManaged<Manager<TransformationComponent>>();
	pMeshComponentManager = NewManaged<Manager<MeshComponent>>();
	pMovableComponentManager = NewManaged<Manager<MovableComponent>>();
	pCameraComponentManager = NewManaged<Manager<CameraComponent>>();

	Handle boxMeshId = pGraphics->CreateBoxMesh(Vector3(0.5f, 0.5f, 0.5f));

	entity1 = Handle();
	TransformationComponent& entity1Transform = pTransformationComponentManager->CreateComponent(entity1);
	entity1Transform.position = Vector3(0.5, 0.0, 0.0);
	entity1Transform.rotation = Vector4::FromAxisAngle(Vector3(0.0f, 0.0f, 1.0f), angle);
	entity1Transform.scale = Vector3(1.5f, 0.5f, 0.5f);
	pMeshComponentManager->CreateComponent(entity1, boxMeshId);
	pMovableComponentManager->CreateComponent(entity1, 1.0f, 1.0f, 1.0f, 1.0f, Vector3(0.0f, 1.0f, 0.0f),
		Vector3(0.0f, 0.0f, -1.0f));

	cameraEntity = Handle();
	pCameraComponentManager->CreateComponent(cameraEntity, 45.0f);	// TODO: handle flipped z-axis (OpenGL vs DirectX) - and not here
	TransformationComponent& cameraTransform = pTransformationComponentManager->CreateComponent(cameraEntity);
	cameraTransform.position = Vector3(0.5f, 0.0f, -3.0f);
}

void DemoGame::Update(double millisecondsElapsed)
{
	TransformationComponent& entity1Transform = pTransformationComponentManager->GetComponent(entity1);
	angle += 0.0005f;
	entity1Transform.rotation = Vector4::FromAxisAngle(Vector3(0.0f, 0.0f, 1.0f), angle);
}