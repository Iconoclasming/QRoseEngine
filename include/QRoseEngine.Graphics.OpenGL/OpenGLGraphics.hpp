#pragma once

#include <QRoseCore.hpp>
#include "OpenGLRender.hpp"

namespace QRose
{
	class OpenGLGraphics
	{
	public:
		OpenGLGraphics();
		~OpenGLGraphics();

		void Initialize(const GraphicsDesc& graphicsDesc);

		Uuid LoadMesh(const std::string& path);
		Uuid LoadBoxMesh(const Vector3& size);

		MPtr<OpenGLRender> GetRender() const;
		GLFWwindow* GetWindow() const;

	private:
		MPtr<OpenGLRender> pRender;
		MPtr<OpenGLResourcesManager> pResourcesManager;
		GLFWwindow* pWindow;
	};
}