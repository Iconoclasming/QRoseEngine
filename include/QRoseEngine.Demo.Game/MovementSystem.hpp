#pragma once

#include <QRoseEngine.Core/ManagedPtr.hpp>
#include <QRoseEngine.Core/Manager.hpp>
#include <QRoseEngine.Core/Components/TransformationComponent.hpp>
#include "Input.hpp"
#include "MovableComponent.hpp"

namespace QRose
{
	class MovementSystem
	{
	public:
		MovementSystem(Ptr<Input> pInput, Ptr<Manager<MovableComponent>> pMovableComponentManager,
			Ptr<Manager<TransformationComponent>> pTransformationComponentManager);
		~MovementSystem();

		void Update(double millisecondsElapsed);

	private:
		Ptr<Input> pInput;
		Ptr<Manager<MovableComponent>> pMovableComponentManager;
		Ptr<Manager<TransformationComponent>> pTransformationComponentManager;
	};
}