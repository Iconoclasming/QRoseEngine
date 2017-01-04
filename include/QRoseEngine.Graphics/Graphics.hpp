#pragma once

#include <string>
#include <QRoseEngine.Core/Handle.hpp>
#include <QRoseEngine.Core/Vector3.hpp>
#include <QRoseEngine.Graphics/Render.hpp>
#include <QRoseEngine.Core/ManagedPtr.hpp>

namespace QRose
{
	class Graphics
	{
	public:
		virtual Handle LoadMesh(const std::string& path) abstract;
		virtual Handle CreateBoxMesh(const Vector3& size) abstract;
	};
}