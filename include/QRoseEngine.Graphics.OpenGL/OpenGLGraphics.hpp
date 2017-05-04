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

		void Initialize(const GraphicsDesc& graphicsDesc, const std::string& assetsDirectory);

		MeshHandle LoadMesh(const std::string& path) override;
		MeshHandle CreateBoxMesh(const Vector3& size) override;

		Ptr<OpenGLRender> GetRender() const;
		GLFWwindow* GetWindow() const;

	private:
		Ptr<OpenGLRender> pRender;
		Ptr<OpenGLResourcesManager> pResourcesManager;
		GLFWwindow* pWindow;
	};
}

// TODO: preprocessor flag to define coordinate system:
// QRE_GRAPHICS_AXES_X_RIGHT_Y_UP_Z_BACKWARD - opengl
// QRE_GRAPHICS_AXES_X_RIGHT_Y_UP_Z_FORWARD - directx