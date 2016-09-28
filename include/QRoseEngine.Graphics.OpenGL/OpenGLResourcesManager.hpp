#pragma once

#include <string>
#include <Uuid.hpp>
#include <Vector.hpp>

namespace QRose
{
	class OpenGLResourcesManager
	{
	public:
		Uuid LoadMesh(const std::string& path);
		Uuid LoadBoxMesh(const Vector3& size);
	};
}