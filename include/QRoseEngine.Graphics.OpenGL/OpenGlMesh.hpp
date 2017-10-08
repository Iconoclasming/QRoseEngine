#pragma once

#include <GL/glew.h>
#include <QRoseEngine.Graphics/MeshHandle.hpp>

namespace QRose
{
	struct OpenGlMesh
	{
		explicit OpenGlMesh(MeshHandle id, GLuint vao, GLuint vertexBuffer, GLuint elementBuffer,
		                    const void* verticesPtr, const void* indicesPtr, int numVertices, int numIndices)
			: id(id), vao(vao), vertexBuffer(vertexBuffer), elementBuffer(elementBuffer), verticesPtr(verticesPtr),
			  indicesPtr(indicesPtr), numVertices(numVertices), numIndices(numIndices)
		{
		}

		const MeshHandle id;
		const GLuint vao;
		const GLuint vertexBuffer;
		const GLuint elementBuffer;
		const void* verticesPtr;
		const void* indicesPtr;
		const int numVertices;
		const int numIndices;
	};
}
