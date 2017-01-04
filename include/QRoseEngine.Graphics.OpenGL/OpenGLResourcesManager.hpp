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

		void LoadDefaultShaderProgram(const std::string& pathToVertexShader, const std::string& pathToFragmentShader);
		GLuint GetDefaultShaderProgram() const;

		GLuint GetMeshVertexArrayObject(Handle meshId);

	private:
		std::map<Handle, GLuint> meshesVertexArrayObjects;
		GLuint defaultShaderProgram;
	};
}