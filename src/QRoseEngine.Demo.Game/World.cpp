#include <QRoseEngine.Demo.Game/World.hpp>

using namespace QRose;

World::World()
{
	pTransformationComponentManager = NewManaged<Manager<TransformationComponent>>();
	pMeshComponentManager = NewManaged<Manager<MeshComponent>>();
	pMovableComponentManager = NewManaged<Manager<MovableComponent>>();
	pCameraComponentManager = NewManaged<Manager<CameraComponent>>();
}