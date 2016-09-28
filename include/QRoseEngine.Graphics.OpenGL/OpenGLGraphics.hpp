#pragma once

#include <Uuid.hpp>
#include <Vector.hpp>
#include <ManagedPtr.hpp>
#include "OpenGLRender.hpp"

namespace QRose
{
	class OpenGLGraphics
	{
	public:
		OpenGLGraphics();
		virtual ~OpenGLGraphics();

		Uuid LoadMesh(const std::string& path);
		Uuid LoadBoxMesh(const Vector3& size);

		MPtr<OpenGLRender> GetRender() const;

	private:
		MPtr<OpenGLRender> pRender;
		MPtr<OpenGLResourcesManager> pResourcesManager;
	};
}