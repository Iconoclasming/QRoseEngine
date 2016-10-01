#include "OpenGLResourcesManager.hpp"

using namespace QRose;

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

GLuint OpenGLResourcesManager::GetMeshVertexArrayObject(const Uuid& meshId)
{
	if(meshesVertexArrayObjects.count(meshId) == 0)
	{
		throw std::invalid_argument("mesh with id " + meshId.ToString() + " not found");
	}
	return meshesVertexArrayObjects[meshId];
}