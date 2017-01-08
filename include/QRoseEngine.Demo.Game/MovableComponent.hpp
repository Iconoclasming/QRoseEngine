#pragma once

#include <QRoseEngine.Core/Uuid.hpp>

namespace QRose
{
	struct MovableComponent
	{
		float forwardSpeed;
		float backwardSpeed;
		float rightSpeed;
		float leftSpeed;

		MovableComponent() : MovableComponent(0.0f, 0.0f, 0.0f, 0.0f) {}
		MovableComponent(float forwardSpeed, float backwardSpeed, float rightSpeed, float leftSpeed)
			: forwardSpeed(forwardSpeed), backwardSpeed(backwardSpeed), rightSpeed(rightSpeed), leftSpeed(leftSpeed) {}

		static const Uuid Type;
	};
}