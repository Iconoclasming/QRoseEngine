#include <QRoseEngineCore.hpp>
#include <Components/MeshComponent.hpp>
#include <Components/TransformationComponent.hpp>

using namespace QRose;

void main()
{
	WindowDesc windowDesc("Awesome Sample Game", Size<int>(800, 600));
	GraphicsDesc graphicsDesc(windowDesc, Color::Aqua);
	MPtr<Engine> pEngine = EngineFactory::CreateEngine(graphicsDesc);

	Entity boxEntity = pEngine->CreateEntity();

	Uuid boxMeshId = pEngine->LoadMesh("D:\\SomePathToMesh");
	MeshComponent boxMeshComponent(boxMeshId);
	pEngine->AttachComponent(boxEntity, boxMeshComponent);

	TransformationComponent boxTransformationComponent;
	pEngine->AttachComponent(boxEntity, boxTransformationComponent);

	pEngine->PresentScene();
}