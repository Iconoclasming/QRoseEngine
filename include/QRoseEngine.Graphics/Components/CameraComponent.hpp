#pragma once

#include <QRoseEngine.Core/EntityHandle.hpp>

namespace QRose
{
	struct CameraComponent
	{
		CameraComponent(EntityHandle id, float fov) : id(id), fov(fov) {}

		static const unsigned int Type = 3;

		const EntityHandle id;
		float fov;
	};
}