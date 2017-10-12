#pragma once

#include <QRoseEngine.Core/System.hpp>
#include <QRoseEngine.Core/ManagedPtr.hpp>
#include <QRoseEngine.Core/World.hpp>
#include <QRoseEngine.Core/Components/TransformComponent.hpp>
#include "Render.hpp"
#include "Components/CameraComponent.hpp"
#include "Components/MeshComponent.hpp"
#include "Components/LightComponent.hpp"

namespace QRose
{
	class RenderSystem : public System
	{
	public:
		RenderSystem(Ptr<Render> pRender, Ptr<World> pWorld);
		virtual ~RenderSystem();

		void Update(double millisecondsElapsed) override;

	private:
		Ptr<Render> pRender;
		Ptr<World> pWorld;
		Storage<CameraComponent>* pCameraComponentStorage;
		Storage<TransformComponent>* pTransformComponentStorage;
		Storage<MeshComponent>* pMeshComponentStorage;
		Storage<LightComponent>* pLightComponentStorage;
	};
}
