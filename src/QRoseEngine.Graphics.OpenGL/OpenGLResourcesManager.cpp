#include "OpenGLResourcesManager.hpp"

#include <sstream>

using namespace QRose;

OpenGLResourcesManager::OpenGLResourcesManager() : defaultShaderProgram(-1)
{
}

OpenGLResourcesManager::~OpenGLResourcesManager()
{
	for(auto& meshVAO : meshesVertexArrayObjects)
	{
		glDeleteVertexArrays(1, &meshVAO.second);
	}
}

Uuid OpenGLResourcesManager::LoadMesh(const std::string& path)
{
	return Uuid::GenerateUuid();
}

Uuid OpenGLResourcesManager::LoadBoxMesh(const Vector3& size)
{
	float sizeX = size.GetX();
	float sizeY = size.GetY();
	float sizeZ = size.GetZ();
	GLfloat vertices[] = {
		-sizeX, -sizeY, -sizeZ,
		sizeX, -sizeY, -sizeZ,
		sizeX,  sizeY, -sizeZ,
		sizeX,  sizeY, -sizeZ,
		-sizeX,  sizeY, -sizeZ,
		-sizeX, -sizeY, -sizeZ,

		-sizeX, -sizeY,  sizeZ,
		sizeX, -sizeY,  sizeZ,
		sizeX,  sizeY,  sizeZ,
		sizeX,  sizeY,  sizeZ,
		-sizeX,  sizeY,  sizeZ,
		-sizeX, -sizeY,  sizeZ,

		-sizeX,  sizeY,  sizeZ,
		-sizeX,  sizeY, -sizeZ,
		-sizeX, -sizeY, -sizeZ,
		-sizeX, -sizeY, -sizeZ,
		-sizeX, -sizeY,  sizeZ,
		-sizeX,  sizeY,  sizeZ,

		sizeX,  sizeY,  sizeZ,
		sizeX,  sizeY, -sizeZ,
		sizeX, -sizeY, -sizeZ,
		sizeX, -sizeY, -sizeZ,
		sizeX, -sizeY,  sizeZ,
		sizeX,  sizeY,  sizeZ,

		-sizeX, -sizeY, -sizeZ,
		sizeX, -sizeY, -sizeZ,
		sizeX, -sizeY,  sizeZ,
		sizeX, -sizeY,  sizeZ,
		-sizeX, -sizeY,  sizeZ,
		-sizeX, -sizeY, -sizeZ,

		-sizeX,  sizeY, -sizeZ,
		sizeX,  sizeY, -sizeZ,
		sizeX,  sizeY,  sizeZ,
		sizeX,  sizeY,  sizeZ,
		-sizeX,  sizeY,  sizeZ,
		-sizeX,  sizeY, -sizeZ,
	};


	GLuint boxMeshVAO;
	glGenVertexArrays(1, &boxMeshVAO);
	glBindVertexArray(boxMeshVAO);
	GLuint boxMeshVBO;
	glGenBuffers(1, &boxMeshVBO);
	glBindBuffer(GL_ARRAY_BUFFER, boxMeshVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), static_cast<GLvoid*>(nullptr));
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);

	Uuid meshId = Uuid::GenerateUuid();
	meshesVertexArrayObjects[meshId] = boxMeshVAO;
	return meshId;
}

void OpenGLResourcesManager::LoadDefaultShaderProgram()
{
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

	defaultShaderProgram = glCreateProgram();
	glAttachShader(defaultShaderProgram, vertexShader);
	glAttachShader(defaultShaderProgram, fragmentShader);
	glLinkProgram(defaultShaderProgram);
	GLint programLinkSuccess;
	glGetShaderiv(defaultShaderProgram, GL_LINK_STATUS, &programLinkSuccess);
	if (!programLinkSuccess)
	{
		GLchar infoLog[512];
		glGetShaderInfoLog(defaultShaderProgram, 512, nullptr, infoLog);
		throw std::runtime_error("failed to link shader program:\n" + std::string(infoLog));
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

GLuint OpenGLResourcesManager::GetMeshVertexArrayObject(const Uuid& meshId) const
{
	if(meshesVertexArrayObjects.count(meshId) == 0)
	{
		throw std::invalid_argument("mesh with id " + meshId.ToString() + " not found");
	}
	return meshesVertexArrayObjects.at(meshId);
}

GLuint OpenGLResourcesManager::GetDefaultShaderProgram() const
{
	return defaultShaderProgram;
}