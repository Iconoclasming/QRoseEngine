#pragma once

#include <QRoseEngine.Core/Handle.hpp>
#include <QRoseEngine.Core/ManagedPtr.hpp>
#include <QRoseEngine.Graphics/Graphics.hpp>
#include <QRoseEngine.Core/Components/TransformationComponent.hpp>
#include "World.hpp"
#include <QRoseEngine.Graphics/RenderSystem.hpp>
#include "MovementSystem.hpp"

namespace QRose
{
	class DemoGame
	{
	public:
		DemoGame(Ptr<Graphics> pGraphics, Ptr<Render> pRender, Ptr<Input> pInput);
		virtual ~DemoGame();

		void Load();
		void Update(double millisecondsElapsed);

	private:
		Handle entity1;
		Handle cameraEntity;

		World world;

		Ptr<Graphics> pGraphics;
		Ptr<Render> pRender;
		Ptr<Input> pInput;

		Ptr<RenderSystem> pRenderSystem;
		Ptr<MovementSystem> pMovementSystem;
	};
}
