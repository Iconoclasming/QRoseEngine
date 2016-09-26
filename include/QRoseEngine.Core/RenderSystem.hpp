#pragma once

#include "System.hpp"
#include "Render.hpp"

namespace QRose
{
	class RenderSystem : public System
	{
	public:
		RenderSystem(ManagedPtr<Render> pRender);
		virtual ~RenderSystem();

		void Update(double millisecondsElapsed) override;

	private:
		ManagedPtr<Render> pRender;
	};
}
