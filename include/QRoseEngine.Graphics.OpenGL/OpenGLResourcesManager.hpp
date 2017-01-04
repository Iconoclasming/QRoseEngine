#pragma once

#include <string>
#include <map>
#include <GL/glew.h>
#include <QRoseCore.hpp>

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

		GLuint GetDefaultShaderProgram() const;

		GLuint defaultShaderProgram;
		GLuint GetMeshVertexArrayObject(Handle meshId);

	private:
		std::map<Handle, GLuint> meshesVertexArrayObjects;
	};
}