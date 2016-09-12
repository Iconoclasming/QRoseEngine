#pragma once

#include "Scene.hpp"

namespace QRose
{
	class Engine
	{
	public:
		virtual ~Engine() {}

		virtual void PresentScene(const Scene& scene) abstract;

		virtual Uuid LoadMesh(const std::string& path) abstract;

		template<typename TComponent>
		void AttachComponent(const Entity& entity, const TComponent& component);
	};
}