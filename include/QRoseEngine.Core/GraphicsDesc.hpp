#pragma once

#include "WindowDesc.hpp"
#include "Color.hpp"

namespace QRose
{
	struct GraphicsDesc
	{
		GraphicsDesc(const WindowDesc& windowDesc, const Color& backgroundColor) 
			: windowDesc(windowDesc), backgroundColor(backgroundColor) {}
		~GraphicsDesc() {}

		const WindowDesc windowDesc;
		const Color backgroundColor;
	};
}