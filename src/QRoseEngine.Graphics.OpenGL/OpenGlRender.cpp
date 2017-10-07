#include <QRoseEngine.Graphics.OpenGL/OpenGlRender.hpp>

using namespace QRose;

OpenGlRender::OpenGlRender(Ptr<OpenGlResourcesManager> pResourcesManager, GLFWwindow* pWindow)
	: pResourcesManager(pResourcesManager),
	pWindow(pWindow)
{
	int windowWidth;
	int windowHeight;
	glfwGetWindowSize(pWindow, &windowWidth, &windowHeight);
	projectionMatrix = Matrix4x4::Projection(45.0f, (float)windowWidth / windowHeight, 0.1f, 100.0f);
	glEnable(GL_DEPTH_TEST);
}

OpenGlRender::~OpenGlRender()
{
}

void OpenGlRender::ClearView()
{
	glClearColor(clearColor.GetRed(), clearColor.GetGreen(), clearColor.GetBlue(), clearColor.GetAlpha());
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGlRender::BeginDrawing()
{
}

void OpenGlRender::DrawMesh(MeshHandle meshId, const Matrix4x4& modelMatrix)
{
	const OpenGlMesh* pMesh = pResourcesManager->GetMeshVertexArrayObject(meshId);
	GLuint shaderProgram = pResourcesManager->GetDefaultShaderProgram();
	glUseProgram(shaderProgram);
	GLuint modelLoc = glGetUniformLocation(shaderProgram, "model");
	GLuint viewLoc = glGetUniformLocation(shaderProgram, "view");
	GLuint projectionLoc = glGetUniformLocation(shaderProgram, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, projectionMatrix.GetArray());
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, modelMatrix.GetArray());
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, viewMatrix.GetArray());
	glBindVertexArray(pMesh->vao);
	if(pMesh->numIndices == 0)
	{
		glDrawArrays(GL_TRIANGLES, 0, pMesh->numVertices);		
	}
	else
	{
		glDrawElements(GL_TRIANGLES, pMesh->numIndices, OpenGlResourcesManager::IndexType, 
			static_cast<void*>(nullptr));
	}
	glUseProgram(0);
	glBindVertexArray(0);
}

void OpenGlRender::Present()
{
	glfwSwapBuffers(pWindow);
}

Color OpenGlRender::GetClearColor()
{
	return clearColor;
}

void OpenGlRender::SetClearColor(const Color& color)
{
	clearColor = color;
}

void OpenGlRender::SetViewMatrix(const Matrix4x4& viewMatrix)
{
	this->viewMatrix = viewMatrix;
}
