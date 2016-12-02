#pragma once

#include <vector>
#include "Scene.hpp"
#include "EntitiesComponentsService.hpp"
#include "Vector.hpp"

namespace QRose
{
	class Engine
	{
	public:
		Engine(Ptr<EntitiesComponentsService> pEntitiesComponentsService);
		virtual ~Engine();

		virtual void PresentScene() abstract;
		virtual Uuid LoadMesh(const std::string& path) abstract;
		virtual Uuid LoadBoxMesh(const Vector3& size) abstract;

		Ptr<EntitiesComponentsService> GetEntitiesComponentsService() const { return pEntitiesComponentsService; }

	protected:
		Ptr<EntitiesComponentsService> pEntitiesComponentsService;
	};
}