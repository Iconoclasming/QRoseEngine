#pragma once

#include <map>
#include <GL/glew.h>
#include <QRoseEngine.Core/Vector3.hpp>
#include <QRoseEngine.Graphics/MeshHandle.hpp>

namespace QRose
{
	class OpenGLResourcesManager
	{
	public:
		OpenGLResourcesManager();
		~OpenGLResourcesManager();

		MeshHandle LoadMesh(const std::string& path);
		MeshHandle LoadBoxMesh(const Vector3& size);

		void LoadDefaultShaderProgram(const std::string& pathToVertexShader, const std::string& pathToFragmentShader);
		GLuint GetDefaultShaderProgram() const;

		GLuint GetMeshVertexArrayObject(MeshHandle meshId);

	private:
		std::map<MeshHandle, GLuint> meshesVertexArrayObjects;
		GLuint defaultShaderProgram;
	};
}
