#pragma once

#include <QRoseEngine.Core/ManagedPtr.hpp>
#include <QRoseEngine.Core/World.hpp>
#include "Input.hpp"
#include "MovableComponent.hpp"
#include "QRoseEngine.Core/Components/TransformComponent.hpp"

namespace QRose
{
	class MovementSystem
	{
	public:
		MovementSystem(Ptr<Input> pInput, Ptr<World> pWorld);
		~MovementSystem();

		void Update(double msElapsed);

	private:
		Ptr<Input> pInput;
		Ptr<World> pWorld;

		Storage<MovableComponent>* pMovableComponents;
		Storage<TransformComponent>* pTransformComponents;
	};
}
