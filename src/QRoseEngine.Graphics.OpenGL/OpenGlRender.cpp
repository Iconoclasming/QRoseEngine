#include <QRoseEngine.Graphics.OpenGL/OpenGlRender.hpp>

#include <cassert>
#include <sstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace QRose;

struct OpenGlRender::PointLight
{
	PointLight(unsigned id, GLfloat x, GLfloat y, GLfloat z, GLfloat r, GLfloat g, GLfloat b, GLfloat a)
		: id(id), position{ x, y, z }, intensity{ r,g,b,a }
	{
	}

	unsigned id;
	GLfloat position[3];
	GLfloat intensity[4];
};

struct OpenGlRender::Line
{
	Line(const Vector3& from, const Vector3& to, float thickness, const Color& colorStart, const Color& colorEnd)
		: from(from),
		to(to),
		thickness(thickness),
		colorStart(colorStart),
		colorEnd(colorEnd)
	{
	}

	const Vector3 from;
	const Vector3 to;
	const float thickness;
	const Color colorStart;
	const Color colorEnd;
};

OpenGlRender::OpenGlRender(Ptr<OpenGlResourcesManager> pResourcesManager, GLFWwindow* pWindow)
	: pResourcesManager(pResourcesManager), pWindow(pWindow), isDebugDrawingInitialized(false),
	lineShaderProgram(0)
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
	_pointLights.clear();
}

void OpenGlRender::DrawMesh(MeshHandle meshId, const Matrix4x4& modelMatrix)
{
	const OpenGlMesh* pMesh = pResourcesManager->GetMeshVertexArrayObject(meshId);
	GLuint shaderProgram = pResourcesManager->GetDefaultShaderProgram();
	glUseProgram(shaderProgram);
	GLuint modelLoc = glGetUniformLocation(shaderProgram, "model");
	GLuint viewLoc = glGetUniformLocation(shaderProgram, "view");
	GLuint projectionLoc = glGetUniformLocation(shaderProgram, "projection");
	GLuint lightPositionLoc = glGetUniformLocation(shaderProgram, "light.position");
	GLuint lightIntensitiesLoc = glGetUniformLocation(shaderProgram, "light.intensity");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, projectionMatrix.Flatten());
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, modelMatrix.Flatten());
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, viewMatrix.Flatten());
	if (_pointLights.size() > 0)
	{
		const PointLight& light = _pointLights[0];
		GLfloat lightPosition[3] = { light.position[0], light.position[1], light.position[2] };
		GLfloat lightIntensities[4] = { light.intensity[0], light.intensity[1], light.intensity[2], light.intensity[3] };
		glUniform3fv(lightPositionLoc, 1, lightPosition);
		glUniform3fv(lightIntensitiesLoc, 1, lightIntensities);
	}
	glBindVertexArray(pMesh->vao);
	if (pMesh->numIndices == 0)
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
	if(isDebugDrawingInitialized)
	{
		glUseProgram(lineShaderProgram);
		GLuint lineVao;
		glGenVertexArrays(1, &lineVao);
		glBindVertexArray(lineVao);
		std::vector<GLfloat> vertices;
		std::vector<GLfloat> colors;
		for(auto& line : lines)
		{
			vertices.push_back(line.from.GetX());
			vertices.push_back(line.from.GetY());
			vertices.push_back(line.from.GetZ());
			vertices.push_back(line.to.GetX());
			vertices.push_back(line.to.GetY());
			vertices.push_back(line.to.GetZ());
			colors.push_back(line.colorStart.GetRed());
			colors.push_back(line.colorStart.GetGreen());
			colors.push_back(line.colorStart.GetBlue());
			colors.push_back(line.colorStart.GetAlpha());
			colors.push_back(line.colorEnd.GetRed());
			colors.push_back(line.colorEnd.GetGreen());
			colors.push_back(line.colorEnd.GetBlue());
			colors.push_back(line.colorEnd.GetAlpha());
		}
		GLuint lineVertexBuffer;
		glGenBuffers(1, &lineVertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, lineVertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
		GLuint lineColorBuffer;
		glGenBuffers(1, &lineColorBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, lineColorBuffer);
		glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(GLfloat), colors.data(), GL_STATIC_DRAW);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, nullptr);
		glDrawArrays(GL_LINES, 0, lines.size() * 2);
		glBindVertexArray(0);
		glUseProgram(0);
		glDeleteVertexArrays(1, &lineVao);
	}
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

void OpenGlRender::AddPointLight(const Vector3& position, const Color& intensity)
{
	// Currently only 1 active light supported
	if (_pointLights.size() == 0)
	{
		_pointLights.push_back(PointLight(0, position.GetX(), position.GetY(), position.GetZ(),
			intensity.GetRed(), intensity.GetGreen(), intensity.GetBlue(), intensity.GetAlpha()));
	}
	else
	{
		_pointLights[0] = PointLight(0, position.GetX(), position.GetY(), position.GetZ(),
			intensity.GetRed(), intensity.GetGreen(), intensity.GetBlue(), intensity.GetAlpha());
	}
}

void OpenGlRender::DrawLine(Vector3 from, Vector3 to, float thickness, Color colorStart, Color colorEnd)
{
	assert(isDebugDrawingInitialized);

	lines.push_back(Line(from, to, thickness, colorStart, colorEnd));
}

void OpenGlRender::InitializeDebugDrawing()
{
	std::stringstream ss;
	ss << "#version 330 core\n";
	ss << "layout(location = 0) in vec3 position;\n";
	ss << "layout(location = 1) in vec4 color;\n";
	ss << "out vec4 fragmentColor;\n";
	ss << "void main()\n";
	ss << "{\n";
	ss << "gl_Position = vec4(position.xyz, 1.0f);\n";
	ss << "fragmentColor = color;\n";
	ss << "}\n";
	std::string vertexShaderString = ss.str();
	const char* vertexShader = vertexShaderString.c_str();
	GLuint lineVertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(lineVertexShaderId, 1, &vertexShader, nullptr);
	glCompileShader(lineVertexShaderId);
	GLint compilationSuccess;
	glGetShaderiv(lineVertexShaderId, GL_COMPILE_STATUS, &compilationSuccess);
	if (!compilationSuccess)
	{
		GLchar infoLog[512];
		glGetShaderInfoLog(lineVertexShaderId, 512, nullptr, infoLog);
		throw std::runtime_error("failed to compile vertex shader:\n" + std::string(infoLog));
	}

	ss = std::stringstream();
	ss << "#version 330 core\n";
	ss << "in vec4 fragmentColor;\n";
	ss << "out vec4 color;\n";
	ss << "void main()\n";
	ss << "{\n";
	ss << "color = fragmentColor;\n";
	ss << "}\n";
	std::string fragmentShaderString = ss.str();
	const char* fragmentShader = fragmentShaderString.c_str();
	GLuint lineFragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(lineFragmentShaderId, 1, &fragmentShader, nullptr);
	glCompileShader(lineFragmentShaderId);
	glGetShaderiv(lineFragmentShaderId, GL_COMPILE_STATUS, &compilationSuccess);
	if (!compilationSuccess)
	{
		GLchar infoLog[512];
		glGetShaderInfoLog(lineFragmentShaderId, 512, nullptr, infoLog);
		throw std::runtime_error("failed to compile vertex shader:\n" + std::string(infoLog));
	}

	lineShaderProgram = glCreateProgram();
	glAttachShader(lineShaderProgram, lineVertexShaderId);
	glAttachShader(lineShaderProgram, lineFragmentShaderId);
	glLinkProgram(lineShaderProgram);
	GLint programLinkSuccess;
	glGetShaderiv(lineShaderProgram, GL_LINK_STATUS, &programLinkSuccess);
	if (!programLinkSuccess)
	{
		GLchar infoLog[512];
		glGetShaderInfoLog(lineShaderProgram, 512, nullptr, infoLog);
		throw std::runtime_error("failed to link shader program:\n" + std::string(infoLog));
	}

	glDeleteShader(lineVertexShaderId);
	glDeleteShader(lineFragmentShaderId);

	isDebugDrawingInitialized = true;
}
