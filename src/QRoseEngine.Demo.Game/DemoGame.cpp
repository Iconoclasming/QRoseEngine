#include <QRoseEngine.Demo.Game/DemoGame.hpp>

#include <QRoseCore.hpp>
#include <QRoseEngine.Graphics/Components/MeshComponent.hpp>

using namespace QRose;

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
	entity1Transform.position += Vector3(1.0, 0.0, 0.0);
	pECS->GetManager<MeshComponent>()->CreateComponent(entity1, boxMeshId);
}

void DemoGame::Update(double millisecondsElapsed)
{
}