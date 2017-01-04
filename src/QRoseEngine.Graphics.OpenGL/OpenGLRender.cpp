#include "QRoseEngine.Graphics.OpenGL/OpenGLRender.hpp"

using namespace QRose;

OpenGLRender::OpenGLRender(Ptr<OpenGLResourcesManager> pResourcesManager, GLFWwindow* pWindow) : pResourcesManager(pResourcesManager),
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

void OpenGLRender::DrawMesh(Handle meshId, const Matrix4x4& transformation)
{
	GLuint meshVAO = pResourcesManager->GetMeshVertexArrayObject(meshId);
	GLuint shaderProgram = pResourcesManager->GetDefaultShaderProgram();
	glUseProgram(shaderProgram);
	GLuint transformLoc = glGetUniformLocation(shaderProgram, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, transformation.GetArray());
	glBindVertexArray(meshVAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glUseProgram(0);
	glBindVertexArray(0);
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