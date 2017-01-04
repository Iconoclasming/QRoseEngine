#include <QRoseEngine.Demo.Game/DemoGame.hpp>

#include <QRoseCore.hpp>
#include <QRoseEngine.Graphics/Components/MeshComponent.hpp>

using namespace QRose;

float angle = 0.78539f;

DemoGame::DemoGame(Ptr<EntitiesComponentsService> pEntitiesComponentsService, Ptr<Graphics> pGraphics)
	: pECS(pEntitiesComponentsService), pGraphics(pGraphics)
{
}

DemoGame::~DemoGame()
{
}

void DemoGame::Load()
{
	Handle boxMeshId = pGraphics->CreateBoxMesh(Vector3(0.5f, 0.5f, 0.5f));

	entity1 = pECS->CreateEntity();
	Ptr<Manager<TransformationComponent>> transformComponentManager = pECS->GetManager<TransformationComponent>();
	TransformationComponent& entity1Transform = transformComponentManager->CreateComponent(entity1);
	entity1Transform.position = Vector3(0.5, 0.0, 0.0);
	entity1Transform.rotation = Vector4::FromAxisAngle(Vector3(0.0f, 0.0f, 1.0f), angle);
	entity1Transform.scale = Vector3(1.5f, 0.5f, 0.5f);
	pECS->GetManager<MeshComponent>()->CreateComponent(entity1, boxMeshId);
}

void DemoGame::Update(double millisecondsElapsed)
{
	TransformationComponent& entity1Transform = pECS->GetManager<TransformationComponent>()->GetComponent(entity1);
	angle += 0.0005f;
	entity1Transform.rotation = Vector4::FromAxisAngle(Vector3(0.0f, 0.0f, 1.0f), angle);
}