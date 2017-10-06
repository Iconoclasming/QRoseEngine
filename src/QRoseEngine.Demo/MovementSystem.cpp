#include <QRoseEngine.Demo/MovementSystem.hpp>

using namespace QRose;

MovementSystem::MovementSystem(Ptr<Input> pInput)
	: pInput(pInput)
{
	if (pInput == nullptr) throw std::invalid_argument("pInput == nullptr");
}

MovementSystem::~MovementSystem()
{
}

void MovementSystem::Update(double msElapsed, World& world)
{
	/*std::vector<std::pair<EntityHandle, MovableComponent>> movableComponents = pMovableComponentManager->GetAllComponents();
	MovementData movementData = pInput->GetMovementData();
	for (int i = 0; i < movableComponents.size(); i++)
	{
		if (pTransformComponentStorage->Contains(movableComponents[i].first))
		{
			TransformComponent& rTransformationComponent = 
				pTransformComponentStorage->GetComponent(movableComponents[i].first);
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
	}*/
}