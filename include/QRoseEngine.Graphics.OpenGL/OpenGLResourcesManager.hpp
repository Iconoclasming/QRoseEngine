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

		GLuint GetMeshVertexArrayObject(const Uuid& meshId);

	private:
		std::map<Uuid, GLuint> meshesVertexArrayObjects;

	};
}