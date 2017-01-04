#pragma once

#include <string>
#include <map>
#include <Uuid.hpp>
#include <Vector.hpp>
#include <GL/glew.h>

namespace QRose
{
	class OpenGLResourcesManager
	{
	public:
		OpenGLResourcesManager();
		~OpenGLResourcesManager();

		Uuid LoadMesh(const std::string& path);
		Uuid LoadBoxMesh(const Vector3& size);

		void LoadDefaultShaderProgram();

		GLuint GetMeshVertexArrayObject(const Uuid& meshId) const;
		GLuint GetDefaultShaderProgram() const;

	private:
		std::map<Uuid, GLuint> meshesVertexArrayObjects;
		GLuint defaultShaderProgram;
	};
}