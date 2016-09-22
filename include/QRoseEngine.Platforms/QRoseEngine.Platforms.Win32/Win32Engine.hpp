#pragma once

#include "Engine.hpp"

namespace QRose
{
	class Win32Engine : public Engine
	{
	public:
		Win32Engine(ECService* pEcService) : Engine(pEcService) {}
		/*();
		~Win32Engine() override;
		void PresentScene(const Scene& scene) override;
		Uuid LoadMesh(const std::string& path) override;*/
	};
}