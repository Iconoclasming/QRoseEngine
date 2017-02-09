#pragma once

#include <QRoseEngine.Core/Handle.hpp>
#include <QRoseEngine.Core/Manager.hpp>
#include <QRoseEngine.Core/ManagedPtr.hpp>
#include <QRoseEngine.Graphics/Graphics.hpp>
#include <QRoseEngine.Core/Components/TransformationComponent.hpp>
#include <QRoseEngine.Graphics/Components/MeshComponent.hpp>
#include <QRoseEngine.Graphics/Components/CameraComponent.hpp>
#include "MovableComponent.hpp"

namespace QRose
{
	class DemoGame
	{
	public:
		DemoGame(Ptr<Graphics> pGraphics);
		virtual ~DemoGame();

		void Load();
		void Update(double millisecondsElapsed);

		Ptr<Manager<TransformationComponent>> GetTransformationComponentManager() const { return pTransformationComponentManager; }
		Ptr<Manager<MeshComponent>> GetMeshComponentManager() const { return pMeshComponentManager; }
		Ptr<Manager<MovableComponent>> GetMovableComponentManager() const { return pMovableComponentManager; }
		Ptr<Manager<CameraComponent>> GetCameraComponentManager() const { return pCameraComponentManager; }

	private:
		Handle entity1;
		Handle cameraEntity;

		Ptr<Graphics> pGraphics;
		Ptr<Manager<TransformationComponent>> pTransformationComponentManager;
		Ptr<Manager<MeshComponent>> pMeshComponentManager;
		Ptr<Manager<MovableComponent>> pMovableComponentManager;
		Ptr<Manager<CameraComponent>> pCameraComponentManager;
	};
}