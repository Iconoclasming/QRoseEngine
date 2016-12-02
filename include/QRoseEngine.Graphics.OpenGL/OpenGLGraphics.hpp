#pragma once

#include <QRoseEngine.Graphics/GraphicsDesc.hpp>
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

		Ptr<OpenGLRender> GetRender() const;
		GLFWwindow* GetWindow() const;

	private:
		Ptr<OpenGLRender> pRender;
		Ptr<OpenGLResourcesManager> pResourcesManager;
		GLFWwindow* pWindow;
	};
}