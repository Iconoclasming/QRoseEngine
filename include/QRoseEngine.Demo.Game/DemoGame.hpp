#pragma once

#include <QRoseEngine.Core/Handle.hpp>
#include <QRoseEngine.Core/Manager.hpp>
#include <QRoseEngine.Core/ManagedPtr.hpp>
#include <QRoseEngine.Core/EntitiesService.hpp>
#include <QRoseEngine.Core/Components/TransformationComponent.hpp>
#include <QRoseEngine.Graphics/Components/MeshComponent.hpp>
#include <QRoseEngine.Graphics/Graphics.hpp>

namespace QRose
{
	class DemoGame
	{
	public:
		DemoGame(Ptr<EntitiesService> pEntitiesService, Ptr<Graphics> pGraphics,
			Ptr<Manager<TransformationComponent>> pTransformationComponentManager, 
			Ptr<Manager<MeshComponent>> pMeshComponentManager);
		virtual ~DemoGame();

		void Load();
		void Update(double millisecondsElapsed);

	private:
		Handle entity1;

		Ptr<Graphics> pGraphics;
		Ptr<EntitiesService> pEntitiesService;
		Ptr<Manager<TransformationComponent>> pTransformationComponentManager;
		Ptr<Manager<MeshComponent>> pMeshComponentManager;
	};
}