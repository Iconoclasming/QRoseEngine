#pragma once

#include <QRoseEngine.Core/Color.hpp>
#include "WindowDesc.hpp"

namespace QRose
{
	struct GraphicsDesc
	{
		GraphicsDesc(const WindowDesc& windowDesc, const Color& backgroundColor);
		~GraphicsDesc();

		const WindowDesc windowDesc;
		const Color backgroundColor;
	};
}