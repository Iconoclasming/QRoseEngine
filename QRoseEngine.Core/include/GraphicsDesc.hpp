#pragma once

#include "WindowDesc.hpp"
#include "Color.hpp"

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