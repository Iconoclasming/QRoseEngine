#pragma once

#include <QRoseEngine.Core/Handle.hpp>
#include <QRoseEngine.Core/EntitiesComponentsService.hpp>
#include <QRoseEngine.Core/ManagedPtr.hpp>
#include <QRoseEngine.Graphics/Graphics.hpp>

namespace QRose
{
	class DemoGame
	{
	public:
		DemoGame(Ptr<EntitiesComponentsService> pEntitiesComponentsService, Ptr<Graphics> pGraphics);
		virtual ~DemoGame();

		void Load();
		void Update(double millisecondsElapsed);

	private:
		Handle entity1;

		Ptr<EntitiesComponentsService> pECS;
		Ptr<Graphics> pGraphics;
	};
}