#pragma once

#include <QRoseEngine.Core/Uuid.hpp>
#include "Engine.hpp"

namespace QRose
{
	class Scene
	{
	public:
		Scene() : engine(nullptr) {}
		virtual ~Scene() {}

		virtual void OnLoad() {}
		virtual void OnUpdate(double millisecondsElapsed) {}

	protected:
		Ptr<Engine> GetEngine() { return engine; }

	private:
		Ptr<Engine> engine;

		friend class Engine;
		void SetEngine(Ptr<Engine> engine) { this->engine = engine; }
	};
}