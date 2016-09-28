#pragma once

#include <Render.hpp>
#include <ManagedPtr.hpp>
#include "OpenGLResourcesManager.hpp"

namespace QRose
{
	class OpenGLRender : public Render
	{
	public:
		OpenGLRender(MPtr<OpenGLResourcesManager> pResourcesManager);
		virtual ~OpenGLRender();

		void ClearView() override;
		void BeginDrawing() override;
		void DrawMesh(const Uuid& meshId, const Vector3& position) override;
		void Present() override;
		Color GetClearColor() override;
		void SetClearColor(const Color& color) override;

	private:
		MPtr<OpenGLResourcesManager> pResourcesManager;

		Color clearColor;
	};
}