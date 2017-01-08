#include <QRoseEngine.Demo.Game/DemoGame.hpp>

#include <QRoseCore.hpp>
#include <QRoseEngine.Graphics/Components/MeshComponent.hpp>

using namespace QRose;

float angle = 0.78539f;

DemoGame::DemoGame(Ptr<EntitiesService> pEntitiesService, Ptr<Graphics> pGraphics,
	Ptr<Manager<TransformationComponent>> pTransformationComponentManager,
	Ptr<Manager<MeshComponent>> pMeshComponentManager,
	Ptr<Manager<MovableComponent>> pMovableComponentManager)
	: pEntitiesService(pEntitiesService), pGraphics(pGraphics),
	pTransformationComponentManager(pTransformationComponentManager), pMeshComponentManager(pMeshComponentManager),
	pMovableComponentManager(pMovableComponentManager)
{
}

DemoGame::~DemoGame()
{
}

void DemoGame::Load()
{
	Handle boxMeshId = pGraphics->CreateBoxMesh(Vector3(0.5f, 0.5f, 0.5f));

	entity1 = pEntitiesService->CreateEntity();
	TransformationComponent& entity1Transform = pTransformationComponentManager->CreateComponent(entity1);
	entity1Transform.position = Vector3(0.5, 0.0, 0.0);
	entity1Transform.rotation = Vector4::FromAxisAngle(Vector3(0.0f, 0.0f, 1.0f), angle);
	entity1Transform.scale = Vector3(1.5f, 0.5f, 0.5f);
	pMeshComponentManager->CreateComponent(entity1, boxMeshId);
	pMovableComponentManager->CreateComponent(entity1, 1.0f, 1.0f, 1.0f, 1.0f);
}

void DemoGame::Update(double millisecondsElapsed)
{
	TransformationComponent& entity1Transform = pTransformationComponentManager->GetComponent(entity1);
	angle += 0.0005f;
	entity1Transform.rotation = Vector4::FromAxisAngle(Vector3(0.0f, 0.0f, 1.0f), angle);
}