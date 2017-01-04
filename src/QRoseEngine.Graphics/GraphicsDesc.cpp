#include <QRoseEngine.Graphics/GraphicsDesc.hpp>

using namespace QRose;

GraphicsDesc::GraphicsDesc(const WindowDesc& windowDesc, const Color& backgroundColor)
	: windowDesc(windowDesc), backgroundColor(backgroundColor)
{
}

GraphicsDesc::~GraphicsDesc()
{
}