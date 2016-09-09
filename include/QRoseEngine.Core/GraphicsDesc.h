#pragma once

#include "WindowDesc.h"
#include "Color.h"

namespace QRose
{
	class GraphicsDesc
	{
	public:
		GraphicsDesc(const WindowDesc& windowDesc, const Color& backgroundColor);
		~GraphicsDesc();

	private:
		WindowDesc windowDesc;
		Color backgroundColor;
	};
}