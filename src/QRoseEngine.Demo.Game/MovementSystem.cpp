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
	std::vector<std::pair<Handle, MovableComponent>> movableComponents = pMovableComponentManager->GetAllComponents();
	MovementData movementData = pInput->GetMovementData();
	for (int i = 0; i < movableComponents.size(); i++)
	{
		if (pTransformationComponentManager->Contains(movableComponents[i].first))
		{
			TransformationComponent& rTransformationComponent = 
				pTransformationComponentManager->GetComponent(movableComponents[i].first);
			//float dx = movableComponents[i].second.rightSpeed * movementData.right
			//	- movableComponents[i].second.leftSpeed * movementData.left;
			//float dz = movableComponents[i].second.forwardSpeed * movementData.forward
			//	- movableComponents[i].second.backwardSpeed * movementData.backward;
			// TODO: handle flipped z-axis (OpenGL) - and not here
			//rTransformationComponent.position += Vector3(dx, 0.0f, -dz);
			if (movementData.left != 0.0f)
			{
				int i = 0;
			}
			rTransformationComponent.position += movableComponents[i].second.front * movementData.forward
				* movableComponents[i].second.forwardSpeed;
			rTransformationComponent.position -= movementData.backward * movableComponents[i].second.backwardSpeed
				* movableComponents[i].second.front;
			rTransformationComponent.position -=
				movableComponents[i].second.front.Cross(movableComponents[i].second.up).Normalize()
				* movableComponents[i].second.leftSpeed * movementData.left;
			rTransformationComponent.position +=
				movableComponents[i].second.front.Cross(movableComponents[i].second.up).Normalize()
				* movableComponents[i].second.rightSpeed * movementData.right;
		}
	}
}