#include "QRoseEngine.Graphics.OpenGL/OpenGLRender.hpp"

#include <sstream>
using namespace QRose;

OpenGLRender::OpenGLRender(Ptr<OpenGLResourcesManager> pResourcesManager, GLFWwindow* pWindow) : pResourcesManager(pResourcesManager),
	pWindow(pWindow)
{
	// TODO refactor
	std::stringstream vertexShaderSS;
	vertexShaderSS << "#version 330 core" << std::endl;
	vertexShaderSS << "layout (location = 0) in vec3 position;" << std::endl;
	vertexShaderSS << "void main()" << std::endl;
	vertexShaderSS << "{" << std::endl;
	vertexShaderSS << "gl_Position = vec4(position.x, position.y, position.z, 1.0);" << std::endl;
	vertexShaderSS << "}" << std::endl;
	GLuint vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	std::string vertexShaderString = vertexShaderSS.str();
	const char* vertexShaderSource = vertexShaderString.c_str();
	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	glCompileShader(vertexShader);
	GLint compilationSuccess;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compilationSuccess);
	if (!compilationSuccess)
	{
		GLchar infoLog[512];
		glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
		throw std::runtime_error("failed to compile vertex shader:\n" + std::string(infoLog));
	}

	std::stringstream fragmentShaderSS;
	fragmentShaderSS << "#version 330 core" << std::endl;
	fragmentShaderSS << "out vec4 color;" << std::endl;
	fragmentShaderSS << "void main()" << std::endl;
	fragmentShaderSS << "{" << std::endl;
	fragmentShaderSS << "color = vec4(1.0f, 0.5f, 0.2f, 1.0f);" << std::endl;
	fragmentShaderSS << "}" << std::endl;
	GLuint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	std::string fragmentShaderString = fragmentShaderSS.str();
	const char* fragmentShaderSource = fragmentShaderString.c_str();
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &compilationSuccess);
	if (!compilationSuccess)
	{
		GLchar infoLog[512];
		glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
		throw std::runtime_error("failed to compile fragment shader:\n" + std::string(infoLog));
	}

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	GLint programLinkSuccess;
	glGetShaderiv(shaderProgram, GL_LINK_STATUS, &programLinkSuccess);
	if (!programLinkSuccess)
	{
		GLchar infoLog[512];
		glGetShaderInfoLog(shaderProgram, 512, nullptr, infoLog);
		throw std::runtime_error("failed to link shader program:\n" + std::string(infoLog));
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

OpenGLRender::~OpenGLRender()
{
	glDeleteProgram(shaderProgram);
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
	GLuint meshVAO = pResourcesManager->GetMeshVertexArrayObject(meshId);
	glUseProgram(shaderProgram);
	glBindVertexArray(meshVAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
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