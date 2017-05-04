#pragma once

#include <vector>
#include "EntityHandle.hpp"
#include "QCE.hpp"

namespace QRose
{
	template<typename TComponent>
	class Manager
	{
	public:
		bool Contains(const EntityHandle& id);

		template<typename ... TArgs>
		TComponent& CreateComponent(const EntityHandle& id, TArgs ... args);

		TComponent& GetComponent(const EntityHandle& id);
		void UpdateComponent(const TComponent& component, const EntityHandle& id);
		void DeleteComponent(const EntityHandle& id);

		int ComponentsTotal() const { return components.size(); }
		const std::vector<std::pair<EntityHandle, TComponent>>& GetAllComponents() { return components; }

	private:
		std::vector<std::pair<EntityHandle, TComponent>> components;
	};

	template<typename TComponent>
	inline bool Manager<TComponent>::Contains(const EntityHandle & id)
	{
		return QCE::ContainsAny(components, [&id](const auto& component){ return component.first == id; });
	}

	template<typename TComponent>
	template<typename ... TArgs>
	TComponent& Manager<TComponent>::CreateComponent(const EntityHandle& id, TArgs ... args)
	{
		if (!Contains(id))
		{
			components.push_back(std::make_pair(id, TComponent(args...)));
		}
		return GetComponent(id);
	}

	template<typename TComponent>
	inline TComponent& Manager<TComponent>::GetComponent(const EntityHandle & id)
	{
		return QCE::Find<std::pair<EntityHandle, TComponent>>(components,
			[&id](const auto& component){ return component.first == id; }).second;
	}
}