#pragma once

#include "Engine.hpp"
#include "ManagedPtr.hpp"
#include <System.hpp>
#include <OpenGLGraphics.hpp>
#include <GraphicsDesc.hpp>

namespace QRose
{
	class Win32Engine : public Engine
	{
	public:
		Win32Engine(MPtr<EntitiesComponentsService> pEntitiesComponentsService);
		virtual ~Win32Engine();

		void Initialize(const GraphicsDesc& graphicsDesc);

		Uuid LoadMesh(const std::string& path) override;
		Uuid LoadBoxMesh(const Vector3& size) override;
		void PresentScene() override;

	private:
		std::vector<MPtr<System>> systems;
		MPtr<OpenGLGraphics> pGraphics;
	};
}