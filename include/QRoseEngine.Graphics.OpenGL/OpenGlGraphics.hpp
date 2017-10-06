#pragma once

#include <QRoseEngine.Graphics/Graphics.hpp>
#include <QRoseEngine.Graphics/GraphicsDesc.hpp>
#include <QRoseEngine.Graphics.OpenGL/OpenGlRender.hpp>

namespace QRose
{
	class OpenGlGraphics : public Graphics
	{
	public:
		OpenGlGraphics();
		~OpenGlGraphics();

		void Initialize(const GraphicsDesc& graphicsDesc, const std::string& assetsDirectory);

		MeshHandle LoadMesh(const std::string& path) override;
		MeshHandle CreateBoxMesh(const Vector3& size) override;

		Ptr<OpenGlRender> GetRender() const;
		GLFWwindow* GetWindow() const;

	private:
		Ptr<OpenGlRender> pRender;
		Ptr<OpenGlResourcesManager> pResourcesManager;
		GLFWwindow* pWindow;
	};
}

// TODO: preprocessor flag to define coordinate system:
// QRE_GRAPHICS_AXES_X_RIGHT_Y_UP_Z_BACKWARD - opengl
// QRE_GRAPHICS_AXES_X_RIGHT_Y_UP_Z_FORWARD - directx