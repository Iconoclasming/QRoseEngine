#pragma once

#include <vector>
#include "Uuid.hpp"
#include "QCE.hpp"

namespace QRose
{
	template<typename TComponent>
	class Manager
	{
	public:
		bool Contains(const Uuid& id);

		template<typename ... TArgs>
		TComponent& CreateComponent(const Uuid& id, TArgs ... args);

		TComponent& GetComponent(const Uuid& id);
		void UpdateComponent(const TComponent& component, const Uuid& id);
		void DeleteComponent(const Uuid& id);

		int ComponentsTotal() const { return components.size(); }
		const std::vector<std::pair<Uuid, TComponent>>& GetAllComponents() { return components; }

	private:
		std::vector<std::pair<Uuid, TComponent>> components;
	};

	template<typename TComponent>
	inline bool Manager<TComponent>::Contains(const Uuid & id)
	{
		return QCE::ContainsAny(components, [&id](const auto& component){ return component.first == id; });
	}

	template<typename TComponent>
	template<typename ... TArgs>
	TComponent& Manager<TComponent>::CreateComponent(const Uuid& id, TArgs ... args)
	{
		if (!Contains(id))
		{
			components.push_back(std::make_pair(id, TComponent(args...)));
		}
		return GetComponent(id);
	}

	template<typename TComponent>
	inline TComponent& Manager<TComponent>::GetComponent(const Uuid & id)
	{
		return QCE::Find<std::pair<Uuid, TComponent>>(components,
			[&id](const auto& component){ return component.first == id; }).second;
	}
}