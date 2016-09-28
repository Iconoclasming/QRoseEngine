#pragma once

#include "WindowDesc.hpp"
#include "Color.hpp"

namespace QRose
{
	struct GraphicsDesc
	{
		GraphicsDesc(const WindowDesc& windowDesc, const Color& backgroundColor) 
			: WindowDesc(windowDesc), BackgroundColor(backgroundColor) {}
		~GraphicsDesc() {}

		const WindowDesc WindowDesc;
		const Color BackgroundColor;
	};
}