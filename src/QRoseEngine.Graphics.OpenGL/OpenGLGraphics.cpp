#include "OpenGLGraphics.hpp"

using namespace QRose;

OpenGLGraphics::OpenGLGraphics()
{
}

OpenGLGraphics::~OpenGLGraphics()
{
}

Uuid OpenGLGraphics::LoadMesh(const std::string& path)
{
	return pResourcesManager->LoadMesh(path);
}

Uuid OpenGLGraphics::LoadBoxMesh(const Vector3& size)
{
	return pResourcesManager->LoadBoxMesh(size);
}

MPtr<OpenGLRender> OpenGLGraphics::GetRender() const
{
	return pRender;
}