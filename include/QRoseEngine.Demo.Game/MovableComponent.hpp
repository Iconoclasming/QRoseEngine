#pragma once

#include <QRoseEngine.Core/Uuid.hpp>
#include <QRoseEngine.Core/Vector3.hpp>

namespace QRose
{
	struct MovableComponent
	{
		float forwardSpeed;
		float backwardSpeed;
		float rightSpeed;
		float leftSpeed;

		Vector3 front;
		Vector3 up;

		MovableComponent() : MovableComponent(0.0f, 0.0f, 0.0f, 0.0f, Vector3(0.0f, 0.0f, -1.0f),
			Vector3(0.0f, 1.0f, 0.0f)) {}
		MovableComponent(float forwardSpeed, float backwardSpeed, float rightSpeed, float leftSpeed,
			Vector3 front, Vector3 up)
			: forwardSpeed(forwardSpeed), backwardSpeed(backwardSpeed), rightSpeed(rightSpeed), leftSpeed(leftSpeed),
			front(front), up(up) {}

		static const Uuid Type;
	};
}