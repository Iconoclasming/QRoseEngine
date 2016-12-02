#pragma once

#include <string>
#include <QRoseEngine.Core/Size.hpp>

namespace QRose
{
	class WindowDesc
	{
	public:
		WindowDesc(const std::string& windowName, const Size<int>& windowSize);
		~WindowDesc();

		std::string GetWindowName() const;
		Size<int> GetWindowSize() const;

	private:
		std::string windowName;
		Size<int> windowSize;
	};
}