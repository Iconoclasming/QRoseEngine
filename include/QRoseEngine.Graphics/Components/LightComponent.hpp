#pragma once

#include <QRoseEngine.Core/EntityHandle.hpp>
#include <QRoseEngine.Core/Color.hpp>

namespace QRose
{
	struct LightComponent
	{
		explicit LightComponent(EntityHandle id, Color intensity = Color::White)
			: id(id), intensity(intensity)
		{			
		}
		
		static const unsigned int Type = 5;

		const EntityHandle id;
		Color intensity;
	};
}
