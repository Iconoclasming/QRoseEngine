#include <QRoseEngineCore.hpp>
#include <TransformationComponent.hpp>
#include <MeshComponent.hpp>

using namespace QRose;

void main()
{
	WindowDesc windowDesc("Awesome Sample Game", Size<int>(800, 600));
	GraphicsDesc graphicsDesc(windowDesc, Color(24, 42, 51));
	Engine* pEngine = EngineFactory::CreateEngine(graphicsDesc);
	//engine->Exit += &OnExit;

	Entity boxEntity = pEngine->CreateEntity();

	Uuid boxMeshId = pEngine->LoadMesh("D:\\SomePathToMesh");
	MeshComponent boxMeshComponent(boxMeshId);
	pEngine->AttachComponent(boxEntity, boxMeshComponent);

	TransformationComponent boxTransformationComponent;
	pEngine->AttachComponent(boxEntity, boxTransformationComponent);
	Scene mainScene({ boxEntity });
	pEngine->PresentScene(mainScene);
}

/*class MyScene : public Scene
{
public:
//...
};*/