#include "OpenGLRender.hpp"

using namespace QRose;

OpenGLRender::OpenGLRender(MPtr<OpenGLResourcesManager> pResourcesManager) : pResourcesManager(pResourcesManager)
{
}

OpenGLRender::~OpenGLRender()
{
}

void OpenGLRender::ClearView()
{
}

void OpenGLRender::BeginDrawing()
{
}

void OpenGLRender::DrawMesh(const Uuid& meshId, const Vector3& position)
{
}

void OpenGLRender::Present()
{
}

Color OpenGLRender::GetClearColor()
{
	return clearColor;
}

void OpenGLRender::SetClearColor(const Color& color)
{
	clearColor = color;
}