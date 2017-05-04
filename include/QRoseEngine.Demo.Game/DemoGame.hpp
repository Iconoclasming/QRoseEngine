#pragma once

#include <QRoseEngine.Core/EntityHandle.hpp>
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
		EntityHandle entity1;
		EntityHandle cameraEntity;

		World world;

		Ptr<Graphics> pGraphics;
		Ptr<Render> pRender;
		Ptr<Input> pInput;

		Ptr<RenderSystem> pRenderSystem;
		Ptr<MovementSystem> pMovementSystem;
	};
}
