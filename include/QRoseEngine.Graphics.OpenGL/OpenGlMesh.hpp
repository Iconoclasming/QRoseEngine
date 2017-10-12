#pragma once

#include <GL/glew.h>
#include <QRoseEngine.Graphics/MeshHandle.hpp>

namespace QRose
{
	struct OpenGlMesh
	{
		OpenGlMesh(MeshHandle id, GLuint vao, int numVertices, int numIndices)
			: id(id), vao(vao), numVertices(numVertices), numIndices(numIndices)
		{
		}

		const MeshHandle id;
		const GLuint vao;
		const int numVertices;
		const int numIndices;
	};
}
