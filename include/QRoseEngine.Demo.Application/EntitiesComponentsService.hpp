#pragma once

#include <vector>
#include <algorithm>
#include <QRoseEngine.Core/ManagedPtr.hpp>
#include <QRoseEngine.Core/Manager.hpp>
#include <QRoseEngine.Core/EntitiesService.hpp>

namespace QRose
{
	class EntitiesComponentsService : public EntitiesService
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
				Ptr<Manager<TComponent>> componentsManager = NewManaged<Manager<TComponent>>();
				componentsManagers.push_back(std::make_pair(TComponent::Type, componentsManager));
				return componentsManager;
			}
		}

		Handle CreateEntity() override;
		
	private:
		std::vector<std::pair<Uuid, Ptr<void>>> componentsManagers;
		// TODO: components managers are known at compile time and not stored in collection
	};
}