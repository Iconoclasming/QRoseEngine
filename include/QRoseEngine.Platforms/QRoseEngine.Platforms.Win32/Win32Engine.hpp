#pragma once

#include "Engine.hpp"
#include "ManagedPtr.hpp"

namespace QRose
{
	class Win32Engine : public Engine
	{
	public:
		Win32Engine(MPtr<EntitiesComponentsService> pEntitiesComponentsService, std::vector<System*> systems);
		virtual ~Win32Engine();

		void PresentScene(const Scene& scene) override;
	};
}