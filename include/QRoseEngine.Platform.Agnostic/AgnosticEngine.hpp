#pragma once

#include <QRoseEngine.Platform/Engine.hpp>
#include <QRoseEngine.Graphics.OpenGL/OpenGLGraphics.hpp>

namespace QRose
{
	class AgnosticEngine : public Engine
	{
	public:
		AgnosticEngine(Ptr<EntitiesComponentsService> pEntitiesComponentsService);
		virtual ~AgnosticEngine();

		void Initialize(const GraphicsDesc& graphicsDesc);

		Uuid LoadMesh(const std::string& path) override;
		Uuid LoadBoxMesh(const Vector3& size) override;
		void PresentScene(Scene& scene) override;

	private:
		std::vector<Ptr<System>> systems;
		Ptr<OpenGLGraphics> pGraphics;
	};
}