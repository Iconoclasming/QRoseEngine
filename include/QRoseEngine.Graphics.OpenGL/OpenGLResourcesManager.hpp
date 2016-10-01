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
		Uuid LoadMesh(const std::string& path);
		Uuid LoadBoxMesh(const Vector3& size);

		GLuint GetMeshVertexArrayObject(const Uuid& meshId);

	private:
		std::map<Uuid, GLuint> meshesVertexArrayObjects;

	};
}