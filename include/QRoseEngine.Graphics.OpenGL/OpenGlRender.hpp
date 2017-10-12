#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <QRoseEngine.Core/ManagedPtr.hpp>
#include <QRoseEngine.Graphics/Render.hpp>
#include <QRoseEngine.Graphics.OpenGL/OpenGlResourcesManager.hpp>


namespace QRose
{
	class OpenGlRender : public Render
	{
	public:
		OpenGlRender(Ptr<OpenGlResourcesManager> pResourcesManager, GLFWwindow* pWindow);
		virtual ~OpenGlRender();

		void ClearView() override;
		void SetViewMatrix(const Matrix4x4 & viewMatrix) override;
		void DrawMesh(MeshHandle meshId, const Matrix4x4& modelMatrix) override;
		void Present() override;
		Color GetClearColor() override;
		void SetClearColor(const Color& color) override;

	private:
		Ptr<OpenGlResourcesManager> pResourcesManager;
		GLFWwindow* pWindow;

		Color clearColor;
		Matrix4x4 projectionMatrix;
		Matrix4x4 viewMatrix;
	};
}
