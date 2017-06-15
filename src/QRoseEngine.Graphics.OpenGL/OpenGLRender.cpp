#include <QRoseEngine.Graphics.OpenGL/OpenGLRender.hpp>

using namespace QRose;

OpenGLRender::OpenGLRender(Ptr<OpenGLResourcesManager> pResourcesManager, GLFWwindow* pWindow)
	: pResourcesManager(pResourcesManager),
	pWindow(pWindow)
{
	int windowWidth;
	int windowHeight;
	glfwGetWindowSize(pWindow, &windowWidth, &windowHeight);
	projectionMatrix = Matrix4x4::Projection(45.0f, (float)windowWidth / windowHeight, 0.1f, 100.0f);
	glEnable(GL_DEPTH_TEST);
}

OpenGLRender::~OpenGLRender()
{
}

void OpenGLRender::ClearView()
{
	glClearColor(clearColor.GetRed(), clearColor.GetGreen(), clearColor.GetBlue(), clearColor.GetAlpha());
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLRender::BeginDrawing()
{
}

void OpenGLRender::DrawMesh(MeshHandle meshId, const Matrix4x4& modelMatrix)
{
	GLuint meshVAO = pResourcesManager->GetMeshVertexArrayObject(meshId);
	GLuint shaderProgram = pResourcesManager->GetDefaultShaderProgram();
	glUseProgram(shaderProgram);
	GLuint modelLoc = glGetUniformLocation(shaderProgram, "model");
	GLuint viewLoc = glGetUniformLocation(shaderProgram, "view");
	GLuint projectionLoc = glGetUniformLocation(shaderProgram, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, projectionMatrix.GetArray());
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, modelMatrix.GetArray());
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, viewMatrix.GetArray());
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

void OpenGLRender::SetViewMatrix(const Matrix4x4& viewMatrix)
{
	this->viewMatrix = viewMatrix;
}
