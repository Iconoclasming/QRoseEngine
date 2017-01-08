#include <QRoseEngine.Demo.Game/MovementSystem.hpp>

using namespace QRose;

MovementSystem::MovementSystem(Ptr<Input> pInput, Ptr<Manager<MovableComponent>> pMovableComponentManager, 
	Ptr<Manager<TransformationComponent>> pTransformationComponentManager)
	: pInput(pInput), pMovableComponentManager(pMovableComponentManager),
	pTransformationComponentManager(pTransformationComponentManager)
{
	if (pInput == nullptr) throw std::invalid_argument("pInput == nullptr");
	if (pMovableComponentManager == nullptr) throw std::invalid_argument("pMovableComponentManager == nullptr");
	if (pTransformationComponentManager == nullptr) 
		throw std::invalid_argument("pTransformationComponentManager == nullptr");
}

MovementSystem::~MovementSystem()
{
}

void MovementSystem::Update(double millisecondsElapsed)
{
	MovementData movementData = pInput->GetMovementData();
	std::vector<std::pair<Handle, MovableComponent>> movableComponents = pMovableComponentManager->GetAllComponents();
	for (int i = 0; i < movableComponents.size(); i++)
	{
		if (pTransformationComponentManager->Contains(movableComponents[i].first))
		{
			TransformationComponent& rTransformationComponent = 
				pTransformationComponentManager->GetComponent(movableComponents[i].first);
			float dx = movableComponents[i].second.rightSpeed * movementData.rightLeft
				+ movableComponents[i].second.leftSpeed * movementData.rightLeft;
			float dz = movableComponents[i].second.forwardSpeed * movementData.foreAft
				+ movableComponents[i].second.backwardSpeed * movementData.foreAft;
			// TODO: handle flipped z-axis (OpenGL) - and not here
			rTransformationComponent.position += Vector3(dx, 0.0f, -dz);
		}
	}
}
