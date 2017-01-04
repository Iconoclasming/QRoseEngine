#pragma once

#include <vector>

#include <QRoseEngine.Core/EntitiesComponentsService.hpp>
#include <QRoseEngine.Core/Vector.hpp>

namespace QRose
{
	class Scene;

	class Engine : std::enable_shared_from_this<Engine>
	{
	public:
		Engine(Ptr<EntitiesComponentsService> pEntitiesComponentsService);
		virtual ~Engine();

		virtual void PresentScene(Scene& scene) abstract;
		virtual Uuid LoadMesh(const std::string& path) abstract;
		virtual Uuid LoadBoxMesh(const Vector3& size) abstract;

		Ptr<EntitiesComponentsService> GetEntitiesComponentsService() const { return pEntitiesComponentsService; }

	protected:
		Ptr<EntitiesComponentsService> pEntitiesComponentsService;

		void SetScene(Scene& scene);
	};
}