#pragma once

#include <QRoseEngine.Core/EntityHandle.hpp>
#include <QRoseEngine.Core/Vector3.hpp>

namespace QRose
{
	struct MovableComponent
	{
		static const unsigned int Type = 2;

		float forwardSpeed;
		float backwardSpeed;
		float rightSpeed;
		float leftSpeed;
		Vector3 front;
		const EntityHandle id;
		Vector3 up;
		int padding;

		explicit MovableComponent(EntityHandle id) : MovableComponent(id, 0.0f, 0.0f, 0.0f, 0.0f,
		                                                              Vector3(0.0f, 0.0f, -1.0f),
		                                                              Vector3(0.0f, 1.0f, 0.0f))
		{
		}

		MovableComponent(EntityHandle id, float forwardSpeed, float backwardSpeed, float rightSpeed, float leftSpeed,
		                 Vector3 front, Vector3 up)
			: forwardSpeed(forwardSpeed), backwardSpeed(backwardSpeed), rightSpeed(rightSpeed), leftSpeed(leftSpeed),
			  front(front), id(id), up(up), padding(0)
		{
		}
	};
}
