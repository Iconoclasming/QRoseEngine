#include <QRoseEngine.Platform/EngineFactory.hpp>
#include <QRoseCore.hpp>
#include <QRoseEngine.Graphics/Components/MeshComponent.hpp>

using namespace QRose;

int main()
{
	WindowDesc windowDesc("Awesome Sample Game", Size<int>(800, 600));
	GraphicsDesc graphicsDesc(windowDesc, Color::Aqua);
	Ptr<Engine> engine = EngineFactory::CreateEngine(graphicsDesc);

	Uuid boxMeshId = engine->LoadBoxMesh(Vector3(0.5f, 0.5f, 0.5f));

	Ptr<EntitiesComponentsService> ecs = engine->GetEntitiesComponentsService();
	Uuid entity1 = ecs->CreateEntity();
	Ptr<Manager<TransformationComponent>> transformComponentManager = ecs->GetManager<TransformationComponent>();
	TransformationComponent& entity1Transform = transformComponentManager->CreateComponent(entity1);
	entity1Transform.position += Vector3(1.0, 0.0, 0.0);
	ecs->GetManager<MeshComponent>()->CreateComponent(entity1, boxMeshId);

	engine->PresentScene();

	return 0;
}