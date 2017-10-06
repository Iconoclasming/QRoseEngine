#include "QRoseEngine.Graphics.OpenGL/OpenGlResourcesManager.hpp"

#include <fstream>
#include <sstream>

using namespace QRose;

OpenGlResourcesManager::OpenGlResourcesManager() : defaultShaderProgram(-1)
{
}

OpenGlResourcesManager::~OpenGlResourcesManager()
{
	for(auto& meshVAO : meshesVertexArrayObjects)
	{
		glDeleteVertexArrays(1, &meshVAO.second);
	}
}

MeshHandle OpenGlResourcesManager::LoadMesh(const std::string& path)
{
	return Uuid::GenerateUuid();
}

MeshHandle OpenGlResourcesManager::LoadBoxMesh(const Vector3& size)
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

void OpenGlResourcesManager::LoadDefaultShaderProgram(const std::string& pathToVertexShader, 
	const std::string& pathToFragmentShader)
{
	std::fstream vertexShaderInputStream(pathToVertexShader);
	if (!vertexShaderInputStream.is_open())
	{
		throw std::invalid_argument("vertex shader file not found: " + pathToVertexShader);
	}
	GLuint vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	std::stringstream vertexShaderStringStream;
	vertexShaderStringStream << vertexShaderInputStream.rdbuf();
	vertexShaderInputStream.close();
	std::string vertexShaderString = vertexShaderStringStream.str();
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

	std::fstream fragmentShaderInputStream(pathToFragmentShader, std::fstream::in);
	if (!fragmentShaderInputStream.is_open())
	{
		throw std::invalid_argument("fragment shader file not found: " + pathToFragmentShader);
	}
	GLuint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	std::stringstream fragmentShaderStringStream;
	fragmentShaderStringStream << fragmentShaderInputStream.rdbuf();
	std::string fragmentShaderString = fragmentShaderStringStream.str();
	fragmentShaderInputStream.close();
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

GLuint OpenGlResourcesManager::GetMeshVertexArrayObject(MeshHandle meshId)
{
	if(meshesVertexArrayObjects.count(meshId) == 0)
	{
		throw std::invalid_argument("mesh with id " + meshId.ToString() + " not found");
	}
	return meshesVertexArrayObjects.at(meshId);
}

GLuint OpenGlResourcesManager::GetDefaultShaderProgram() const
{
	return defaultShaderProgram;
}