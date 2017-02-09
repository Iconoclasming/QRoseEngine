#pragma once

#include <vector>
#include <QRoseEngine.Core/System.hpp>
#include <QRoseEngine.Core/ManagedPtr.hpp>
#include <QRoseEngine.Core/Manager.hpp>
#include <QRoseEngine.Core/Components/TransformationComponent.hpp>
#include "Components/MeshComponent.hpp"
#include "Components/CameraComponent.hpp"
#include "Render.hpp"

namespace QRose
{
	class RenderSystem : public System
	{
	public:
		RenderSystem(Ptr<Render> pRender, Ptr<Manager<TransformationComponent>> pTransformationComponentManager,
			Ptr<Manager<MeshComponent>> pMeshComponentManager, Ptr<Manager<CameraComponent>> pCameraComponentManager);
		virtual ~RenderSystem();

		void Update(double millisecondsElapsed) override;

	private:
		Ptr<Render> pRender;
		Ptr<Manager<TransformationComponent>> pTransformationComponentManager;
		Ptr<Manager<MeshComponent>> pMeshComponentManager;
		Ptr<Manager<CameraComponent>> pCameraComponentManager;
	};
}
