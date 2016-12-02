#pragma once

#include <vector>

#include <QRoseEngine.Core/EntitiesComponentsService.hpp>
#include <QRoseEngine.Core/Vector.hpp>

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