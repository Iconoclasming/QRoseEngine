#pragma once

#include <string>
#include "Size.h"

namespace QRose
{
	class WindowDesc
	{
	public:
		WindowDesc(const std::string& windowName, const SizeD& windowSize);
		~WindowDesc();

		std::string GetWindowName() const;
		SizeD GetWindowSize() const;

	private:
		std::string windowName;
		SizeD windowSize;
	};
}