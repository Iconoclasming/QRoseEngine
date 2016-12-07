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

		Handle LoadMesh(const std::string& path);
		Handle LoadBoxMesh(const Vector3& size);

		Ptr<OpenGLRender> GetRender() const;
		GLFWwindow* GetWindow() const;

	private:
		Ptr<OpenGLRender> pRender;
		Ptr<OpenGLResourcesManager> pResourcesManager;
		GLFWwindow* pWindow;
	};
}