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

struct OpenGlRender::Line2D
{
	Line2D(const Vector2& from, const Vector2& to, float thickness, const Color& colorStart, const Color& colorEnd)
		: from(from), to(to), thickness(thickness), colorStart(colorStart), colorEnd(colorEnd)
	{
	}

	const Vector2 from;
	const Vector2 to;
	const float thickness;
	const Color colorStart;
	const Color colorEnd;
};

struct OpenGlRender::Line3D
{
	Line3D(const Vector3& from, const Vector3& to, float thickness, const Color& colorStart, const Color& colorEnd)
		: from(from), to(to), thickness(thickness), colorStart(colorStart), colorEnd(colorEnd)
	{
	}

	const Vector3 from;
	const Vector3 to;
	const float thickness;
	const Color colorStart;
	const Color colorEnd;
};

GLuint CreateShaderProgram(const std::string& vertexShaderText, const std::string& fragmentShaderText);

OpenGlRender::OpenGlRender(Ptr<OpenGlResourcesManager> pResourcesManager, GLFWwindow* pWindow)
	: pResourcesManager(pResourcesManager), pWindow(pWindow), isDebugDrawingInitialized(false),
	lineScreenSpaceShaderProgram(0), lineWorldSpaceShaderProgram(0)
{
	int windowWidth;
	int windowHeight;
	glfwGetWindowSize(pWindow, &windowWidth, &windowHeight);
	projectionMatrix = Matrix4x4::Projection(45.0f, (float)windowWidth / windowHeight, 0.1f, 100.0f);
	glEnable(GL_DEPTH_TEST);
}

OpenGlRender::~OpenGlRender()
{
	glDeleteProgram(lineScreenSpaceShaderProgram);
	glDeleteProgram(lineWorldSpaceShaderProgram);
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
		if(linesScreenSpace.size() > 0)
		{
			glUseProgram(lineScreenSpaceShaderProgram);
			GLuint linesScreenSpaceVao;
			glGenVertexArrays(1, &linesScreenSpaceVao);
			glBindVertexArray(linesScreenSpaceVao);
			std::vector<GLfloat> verticesScreenSpace;
			std::vector<GLfloat> colorsScreenSpace;
			for (auto& line : linesScreenSpace)
			{
				verticesScreenSpace.push_back(line.from.GetX());
				verticesScreenSpace.push_back(line.from.GetY());
				verticesScreenSpace.push_back(line.to.GetX());
				verticesScreenSpace.push_back(line.to.GetY());
				colorsScreenSpace.push_back(line.colorStart.GetRed());
				colorsScreenSpace.push_back(line.colorStart.GetGreen());
				colorsScreenSpace.push_back(line.colorStart.GetBlue());
				colorsScreenSpace.push_back(line.colorStart.GetAlpha());
				colorsScreenSpace.push_back(line.colorEnd.GetRed());
				colorsScreenSpace.push_back(line.colorEnd.GetGreen());
				colorsScreenSpace.push_back(line.colorEnd.GetBlue());
				colorsScreenSpace.push_back(line.colorEnd.GetAlpha());
			}
			GLuint linesScreenSpaceVertexBuffer;
			glGenBuffers(1, &linesScreenSpaceVertexBuffer);
			glBindBuffer(GL_ARRAY_BUFFER, linesScreenSpaceVertexBuffer);
			glBufferData(GL_ARRAY_BUFFER, verticesScreenSpace.size() * sizeof(GLfloat),
				verticesScreenSpace.data(), GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
			GLuint linesScreenSpaceColorBuffer;
			glGenBuffers(1, &linesScreenSpaceColorBuffer);
			glBindBuffer(GL_ARRAY_BUFFER, linesScreenSpaceColorBuffer);
			glBufferData(GL_ARRAY_BUFFER, colorsScreenSpace.size() * sizeof(GLfloat),
				colorsScreenSpace.data(), GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, nullptr);
			glDrawArrays(GL_LINES, 0, linesScreenSpace.size() * 2);
			glBindVertexArray(0);
			glUseProgram(0);
			glDeleteVertexArrays(1, &linesScreenSpaceVao);
			linesScreenSpace.clear();			
		}

		if(linesWorldSpace.size() > 0)
		{
			glUseProgram(lineWorldSpaceShaderProgram);
			GLuint linesWorldSpaceVao;
			glGenVertexArrays(1, &linesWorldSpaceVao);
			glBindVertexArray(linesWorldSpaceVao);
			std::vector<GLfloat> verticesWorldSpace;
			std::vector<GLfloat> colorsWorldSpace;
			for(auto& line : linesWorldSpace)
			{
				verticesWorldSpace.push_back(line.from.GetX());
				verticesWorldSpace.push_back(line.from.GetY());
				verticesWorldSpace.push_back(line.from.GetZ());
				verticesWorldSpace.push_back(line.to.GetX());
				verticesWorldSpace.push_back(line.to.GetY());
				verticesWorldSpace.push_back(line.to.GetZ());
				colorsWorldSpace.push_back(line.colorStart.GetRed());
				colorsWorldSpace.push_back(line.colorStart.GetGreen());
				colorsWorldSpace.push_back(line.colorStart.GetBlue());
				colorsWorldSpace.push_back(line.colorStart.GetAlpha());
				colorsWorldSpace.push_back(line.colorEnd.GetRed());
				colorsWorldSpace.push_back(line.colorEnd.GetGreen());
				colorsWorldSpace.push_back(line.colorEnd.GetBlue());
				colorsWorldSpace.push_back(line.colorEnd.GetAlpha());
			}
			GLuint linesWorldSpaceVertexBuffer;
			glGenBuffers(1, &linesWorldSpaceVertexBuffer);
			glBindBuffer(GL_ARRAY_BUFFER, linesWorldSpaceVertexBuffer);
			glBufferData(GL_ARRAY_BUFFER, verticesWorldSpace.size() * sizeof(GLfloat),
				verticesWorldSpace.data(), GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
			GLuint linesWorldSpaceColorBuffer;
			glGenBuffers(1, &linesWorldSpaceColorBuffer);
			glBindBuffer(GL_ARRAY_BUFFER, linesWorldSpaceColorBuffer);
			glBufferData(GL_ARRAY_BUFFER, colorsWorldSpace.size() * sizeof(GLfloat),
				colorsWorldSpace.data(), GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, nullptr);
			GLuint viewLoc = glGetUniformLocation(lineWorldSpaceShaderProgram, "view");
			GLuint projectionLoc = glGetUniformLocation(lineWorldSpaceShaderProgram, "projection");
			glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, projectionMatrix.Flatten());
			glUniformMatrix4fv(viewLoc, 1, GL_FALSE, viewMatrix.Flatten());
			glDrawArrays(GL_LINES, 0, linesWorldSpace.size() * 2);
			glBindVertexArray(0);
			glUseProgram(0);
			glDeleteVertexArrays(1, &linesWorldSpaceVao);
			linesWorldSpace.clear();			
		}
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

void OpenGlRender::DrawLine(Vector2 from, Vector2 to, float thickness, Color colorStart, Color colorEnd)
{
	assert(isDebugDrawingInitialized);
	linesScreenSpace.push_back(Line2D(from, to, thickness, colorStart, colorEnd));
}

void OpenGlRender::DrawLine(Vector3 from, Vector3 to, float thickness, Color colorStart, Color colorEnd)
{
	assert(isDebugDrawingInitialized);
	linesWorldSpace.push_back(Line3D(from, to, thickness, colorStart, colorEnd));
}

void OpenGlRender::InitializeDebugDrawing()
{
	static const std::string versionLine = "#version 330 core\n";
	std::stringstream ss;
	ss << versionLine;
	ss << "layout (location = 0) in vec2 position;\n";
	ss << "layout (location = 1) in vec4 color;\n";
	ss << "out vec4 fragmentColor;\n";
	ss << "void main()\n";
	ss << "{\n";
	ss << "gl_Position = vec4(position.xy, 0.0f, 1.0f);\n";
	ss << "fragmentColor = color;\n";
	ss << "}\n";
	std::string screenSpaceVertexShader = ss.str();

	ss = std::stringstream();
	ss << versionLine;
	ss << "in vec4 fragmentColor;\n";
	ss << "out vec4 color;\n";
	ss << "void main()\n";
	ss << "{\n";
	ss << "color = fragmentColor;\n";
	ss << "}\n";
	std::string fragmentShader = ss.str();

	ss = std::stringstream();
	ss << versionLine;
	ss << "uniform mat4 view;\n";
	ss << "uniform mat4 projection;\n";
	ss << "layout (location = 0) in vec3 position;\n";
	ss << "layout (location = 1) in vec4 color;\n";
	ss << "out vec4 fragmentColor;\n";
	ss << "void main()\n";
	ss << "{\n";
	ss << "gl_Position = projection * view * vec4(position, 1.0f);\n";
	ss << "fragmentColor = color;\n";
	ss << "}\n";
	std::string worldSpaceVertexShader = ss.str();

	lineScreenSpaceShaderProgram = CreateShaderProgram(screenSpaceVertexShader, fragmentShader);
	lineWorldSpaceShaderProgram = CreateShaderProgram(worldSpaceVertexShader, fragmentShader);
	isDebugDrawingInitialized = true;
}

GLuint CreateShaderProgram(const std::string& vertexShaderText, const std::string& fragmentShaderText)
{
	const char* vertexShader = vertexShaderText.c_str();
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
	const char* fragmentShader = fragmentShaderText.c_str();
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
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, lineVertexShaderId);
	glAttachShader(shaderProgram, lineFragmentShaderId);
	glLinkProgram(shaderProgram);
	GLint programLinkSuccess;
	glGetShaderiv(shaderProgram, GL_LINK_STATUS, &programLinkSuccess);
	if (!programLinkSuccess)
	{
		GLchar infoLog[512];
		glGetShaderInfoLog(shaderProgram, 512, nullptr, infoLog);
		throw std::runtime_error("failed to link shader program:\n" + std::string(infoLog));
	}
	glDeleteShader(lineVertexShaderId);
	glDeleteShader(lineFragmentShaderId);
	return shaderProgram;
}