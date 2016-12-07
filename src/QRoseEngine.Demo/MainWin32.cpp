#include <QRoseCore.hpp>
#include <QRoseEngine.Platform/EngineFactory.hpp>
#include <QRoseEngine.Platform/Scene.hpp>
#include <QRoseEngine.Graphics/Components/MeshComponent.hpp>

using namespace QRose;

class DemoScene : public Scene
{
public:
	DemoScene();
	virtual ~DemoScene();

	void OnLoad() override;
	void OnUpdate(double millisecondsElapsed) override;

private:
	Handle entity1;

};

int main()
{
	WindowDesc windowDesc("Awesome Sample Game", Size<int>(800, 600));
	GraphicsDesc graphicsDesc(windowDesc, Color::Aqua);
	Ptr<Engine> engine = EngineFactory::CreateEngine(graphicsDesc);
	DemoScene scene;
	engine->PresentScene(scene);

	return 0;
}

DemoScene::DemoScene()
{
}

DemoScene::~DemoScene()
{
}

void DemoScene::OnLoad()
{
	Handle boxMeshId = GetEngine()->LoadBoxMesh(Vector3(0.5f, 0.5f, 0.5f));

	Ptr<EntitiesComponentsService> ecs = GetEngine()->GetEntitiesComponentsService();
	entity1 = ecs->CreateEntity();
	Ptr<Manager<TransformationComponent>> transformComponentManager = ecs->GetManager<TransformationComponent>();
	TransformationComponent& entity1Transform = transformComponentManager->CreateComponent(entity1);
	entity1Transform.position += Vector3(1.0, 0.0, 0.0);
	ecs->GetManager<MeshComponent>()->CreateComponent(entity1, boxMeshId);
}

void DemoScene::OnUpdate(double millisecondsElapsed)
{
}
