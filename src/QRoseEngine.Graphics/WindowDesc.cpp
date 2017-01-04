#include <QRoseEngine.Graphics/WindowDesc.hpp>

using namespace QRose;

WindowDesc::WindowDesc(const std::string& windowName, const Size<int>& windowSize)
	: windowName(windowName), windowSize(windowSize)
{
}

WindowDesc::~WindowDesc()
{
}

std::string WindowDesc::GetWindowName() const
{
	return windowName;
}

Size<int> WindowDesc::GetWindowSize() const
{
	return windowSize;
}