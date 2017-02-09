#pragma once

#include <QRoseEngine.Core/Vector3.hpp>
#include <QRoseEngine.Core/Uuid.hpp>

namespace QRose
{
	struct CameraComponent
	{
		float fov;

		static const Uuid Type;

		CameraComponent(float fov) : fov(fov) {}
	};
}