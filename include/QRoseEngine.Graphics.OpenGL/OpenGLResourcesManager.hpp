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
		Uuid LoadMesh(const std::string& path);
		Uuid LoadBoxMesh(const Vector3& size);

		GLuint GetMeshVertexArrayObject(Handle meshId);

	private:
		std::map<Handle, GLuint> meshesVertexArrayObjects;

	};
}