#pragma once

#include <vector>
#include <GL/glew.h>
#include <QRoseEngine.Core/Vector3.hpp>
#include <QRoseEngine.Graphics/MeshHandle.hpp>
#include "OpenGlMesh.hpp"

namespace QRose
{
	class OpenGlResourcesManager
	{
	public:
		OpenGlResourcesManager();
		~OpenGlResourcesManager();

		typedef GLushort Index;
		static const int IndexType = GL_UNSIGNED_SHORT;

		MeshHandle LoadMesh(const std::string& path);
		MeshHandle LoadBoxMesh(const Vector3& size);

		void LoadDefaultShaderProgram(const std::string& pathToVertexShader, const std::string& pathToFragmentShader);
		GLuint GetDefaultShaderProgram() const;

		const OpenGlMesh* GetMeshVertexArrayObject(MeshHandle meshId) const;

	private:
		std::vector<OpenGlMesh> meshes;
		GLuint defaultShaderProgram;
	};
}
