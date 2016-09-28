#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Render.hpp>
#include <ManagedPtr.hpp>
#include "OpenGLResourcesManager.hpp"

namespace QRose
{
	class OpenGLRender : public Render
	{
	public:
		OpenGLRender(MPtr<OpenGLResourcesManager> pResourcesManager, GLFWwindow* pWindow);
		virtual ~OpenGLRender();

		void ClearView() override;
		void BeginDrawing() override;
		void DrawMesh(const Uuid& meshId, const Vector3& position) override;
		void Present() override;
		Color GetClearColor() override;
		void SetClearColor(const Color& color) override;

	private:
		MPtr<OpenGLResourcesManager> pResourcesManager;
		GLFWwindow* pWindow;

		Color clearColor;
	};
}