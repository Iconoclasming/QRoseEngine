#pragma once

#include <QRoseEngine.Core/ManagedPtr.hpp>
#include <QRoseEngine.Core/World.hpp>
#include "Input.hpp"
#include "MovableComponent.hpp"

namespace QRose
{
	class MovementSystem
	{
	public:
		MovementSystem(Ptr<Input> pInput);
		~MovementSystem();

		void Update(double msElapsed, World& world);

	private:
		Ptr<Input> pInput;
	};
}