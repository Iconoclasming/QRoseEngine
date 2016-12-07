#pragma once

#include <vector>
#include <algorithm>
#include "ManagedPtr.hpp"
#include "Manager.hpp"
#include "Handle.hpp"

namespace QRose
{
	class EntitiesComponentsService
	{
	public:
		EntitiesComponentsService();
		~EntitiesComponentsService();

		template<typename TComponent>
		Ptr<Manager<TComponent>> GetManager()
		{
			auto it = std::find_if(componentsManagers.begin(), componentsManagers.end(), [](const auto& managerPair)
				{
					return managerPair.first == TComponent::Type;
				});
			if (it != componentsManagers.end())
			{
				return std::static_pointer_cast<Manager<TComponent>>(it->second);
			}
			else
			{
				Ptr<Manager<TComponent>> componentsManager = Managed<Manager<TComponent>>();
				componentsManagers.push_back(std::make_pair(TComponent::Type, componentsManager));
				return componentsManager;
			}
		}

		Handle CreateEntity();
		
	private:
		std::vector<std::pair<Uuid, Ptr<void>>> componentsManagers;
	};
}