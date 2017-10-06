#include <QRoseEngine.Demo/MovementSystem.hpp>

using namespace QRose;

MovementSystem::MovementSystem(Ptr<Input> pInput, Ptr<World> pWorld)
	: pInput(pInput), pWorld(pWorld), pMovableComponents(nullptr), pTransformComponents(nullptr)
{
	if (pInput == nullptr) throw std::invalid_argument("pInput == nullptr");
	if (pWorld == nullptr) throw std::invalid_argument("pWorld == nullptr");
}

MovementSystem::~MovementSystem()
{
}

void MovementSystem::Update(double msElapsed)
{
	if(pMovableComponents == nullptr)
	{
		pMovableComponents = pWorld->Get<Storage<MovableComponent>>();
	}
	if(pTransformComponents == nullptr)
	{
		pTransformComponents = pWorld->Get<Storage<TransformComponent>>();
	}

	MovementData movementData = pInput->GetMovementData();
	MovableComponent* movableComponents = pMovableComponents->GetAll();
	for (int i = 0; i < pMovableComponents->Size(); i++)
	{
		if(pTransformComponents->Has(movableComponents[i].id))
		{
			TransformComponent& transformComponent = pTransformComponents->Get(movableComponents[i].id);
			transformComponent.position -= movableComponents[i].front * movementData.forward
				* movableComponents[i].forwardSpeed;
			transformComponent.position += movementData.backward * movableComponents[i].backwardSpeed
				* movableComponents[i].front;
			transformComponent.position += movableComponents[i].front.Cross(movableComponents[i].up).Normalize()
				* movableComponents[i].leftSpeed * movementData.left;
			transformComponent.position -= movableComponents[i].front.Cross(movableComponents[i].up).Normalize()
				* movableComponents[i].rightSpeed * movementData.right;
		}
	}
}