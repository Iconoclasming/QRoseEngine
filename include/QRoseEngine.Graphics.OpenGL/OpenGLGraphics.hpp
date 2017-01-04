#pragma once

#include <QRoseEngine.Graphics/Graphics.hpp>
#include <QRoseEngine.Graphics/GraphicsDesc.hpp>
#include "OpenGLRender.hpp"

namespace QRose
{
	class OpenGLGraphics : public Graphics
	{
	public:
		OpenGLGraphics();
		~OpenGLGraphics();

		void Initialize(const GraphicsDesc& graphicsDesc);

		Handle LoadMesh(const std::string& path) override;
		Handle CreateBoxMesh(const Vector3& size) override;

		Ptr<OpenGLRender> GetRender() const;
		GLFWwindow* GetWindow() const;

	private:
		Ptr<OpenGLRender> pRender;
		Ptr<OpenGLResourcesManager> pResourcesManager;
		GLFWwindow* pWindow;
	};
}