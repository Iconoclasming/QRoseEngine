#pragma once

#include "Engine.hpp"

namespace QRose
{
	class Win32Engine : public Engine
	{
	public:
		Win32Engine(ECService* pEcService, std::vector<System*> systems);
		virtual ~Win32Engine();

		void PresentScene(const Scene& scene) override;
	};
}