#pragma once

#include <QRoseEngine.Core/Vector3.hpp>
#include "MeshHandle.hpp"

namespace QRose
{
	class Graphics
	{
	public:
		virtual ~Graphics() = default;

		virtual MeshHandle LoadMesh(const std::string& path) abstract;
		virtual MeshHandle CreateBoxMesh(const Vector3& size) abstract;
	};
}