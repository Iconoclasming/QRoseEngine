#include "OpenGLRender.hpp"

using namespace QRose;

OpenGLRender::OpenGLRender(MPtr<OpenGLResourcesManager> pResourcesManager, GLFWwindow* pWindow) : pResourcesManager(pResourcesManager),
	pWindow(pWindow)
{
}

OpenGLRender::~OpenGLRender()
{
}

void OpenGLRender::ClearView()
{
	glClearColor(clearColor.GetRed(), clearColor.GetGreen(), clearColor.GetBlue(), clearColor.GetAlpha());
	glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLRender::BeginDrawing()
{
}

void OpenGLRender::DrawMesh(const Uuid& meshId, const Vector3& position)
{
}

void OpenGLRender::Present()
{
	glfwSwapBuffers(pWindow);
}

Color OpenGLRender::GetClearColor()
{
	return clearColor;
}

void OpenGLRender::SetClearColor(const Color& color)
{
	clearColor = color;
}