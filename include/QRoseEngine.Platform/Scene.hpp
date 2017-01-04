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

		// TODO: remove GetEngine(), add instead:
		// Handle CreateEntity();
		// TransformationComponentManager GetTransformationComponentManager();
		// MeshComponentManager GetMeshComponentManager();
		// ... and so on.
		// All static typed, without templates. 
		// Try implement http://gameprogrammingpatterns.com/subclass-sandbox.html pattern. In fact, this should serve
		// as an API for the actual game code.

	private:
		Ptr<Engine> engine;

		friend class Engine;
		void SetEngine(Ptr<Engine> engine) { this->engine = engine; }
	};
}