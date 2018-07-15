#include <QRoseEngine.Graphics.OpenGL/BoxMesh.hpp>

std::vector<GLfloat> QRose::BoxMesh::CreateVertices(GLfloat sizeX, GLfloat sizeY, GLfloat sizeZ)
{
	return
	{
		-sizeX, -sizeY, -sizeZ,
		-sizeX,  sizeY, -sizeZ,
		sizeX, sizeY, -sizeZ,
		sizeX, -sizeY, -sizeZ,

		-sizeX, -sizeY, sizeZ,
		sizeX, -sizeY, sizeZ,
		sizeX,  sizeY, sizeZ,
		-sizeX,  sizeY, sizeZ,

		-sizeX, sizeY, -sizeZ,
		-sizeX, sizeY,  sizeZ,
		sizeX, sizeY,  sizeZ,
		sizeX, sizeY, -sizeZ,

		-sizeX, -sizeY, -sizeZ,
		sizeX, -sizeY, -sizeZ,
		sizeX, -sizeY,  sizeZ,
		-sizeX, -sizeY,  sizeZ,

		-sizeX, -sizeY,  sizeZ,
		-sizeX,  sizeY,  sizeZ,
		-sizeX,  sizeY, -sizeZ,
		-sizeX, -sizeY, -sizeZ,

		sizeX, -sizeY, -sizeZ,
		sizeX,  sizeY, -sizeZ,
		sizeX,  sizeY,  sizeZ,
		sizeX, -sizeY,  sizeZ,
	};
}

std::vector<GLushort> QRose::BoxMesh::CreateIndices()
{
	return
	{
		0, 1, 2,
		0, 2, 3,

		4, 5, 6,
		4, 6, 7,

		8, 9, 10,
		8, 10, 11,

		12, 13, 14,
		12, 14, 15,

		16, 17, 18,
		16, 18, 19,

		20, 21, 22,
		20, 22, 23
	};
}

std::vector<GLfloat> QRose::BoxMesh::CreateNormals()
{
	return
	{
		-1.0f, -1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,

		-1.0f, -1.0f, 1.0f,
		1.0f, -1.0f, 1.0f,
		1.0f,  1.0f, 1.0f,
		-1.0f,  1.0f, 1.0f,

		-1.0f, 1.0f, -1.0f,
		-1.0f, 1.0f,  1.0f,
		1.0f, 1.0f,  1.0f,
		1.0f, 1.0f, -1.0f,

		-1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,

		1.0f, -1.0f, -1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f, -1.0f,  1.0f,
	};
}
