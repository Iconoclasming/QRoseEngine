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

void MovementSystem::Update(double dt)
{
	std::vector<std::pair<EntityHandle, MovableComponent>> movableComponents = pMovableComponentManager->GetAllComponents();
	MovementData movementData = pInput->GetMovementData();
	for (int i = 0; i < movableComponents.size(); i++)
	{
		if (pTransformationComponentManager->Contains(movableComponents[i].first))
		{
			TransformationComponent& rTransformationComponent = 
				pTransformationComponentManager->GetComponent(movableComponents[i].first);
			rTransformationComponent.position -= movableComponents[i].second.front * movementData.forward
				* movableComponents[i].second.forwardSpeed;
			rTransformationComponent.position += movementData.backward * movableComponents[i].second.backwardSpeed
				* movableComponents[i].second.front;
			rTransformationComponent.position +=
				movableComponents[i].second.front.Cross(movableComponents[i].second.up).Normalize()
				* movableComponents[i].second.leftSpeed * movementData.left;
			rTransformationComponent.position -=
				movableComponents[i].second.front.Cross(movableComponents[i].second.up).Normalize()
				* movableComponents[i].second.rightSpeed * movementData.right;
		}
	}
}