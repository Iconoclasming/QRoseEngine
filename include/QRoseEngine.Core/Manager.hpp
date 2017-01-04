#pragma once

#include <vector>
#include "Handle.hpp"
#include "QCE.hpp"

namespace QRose
{
	template<typename TComponent>
	class Manager
	{
	public:
		bool Contains(const Handle& id);

		template<typename ... TArgs>
		TComponent& CreateComponent(const Handle& id, TArgs ... args);

		TComponent& GetComponent(const Handle& id);
		void UpdateComponent(const TComponent& component, const Handle& id);
		void DeleteComponent(const Handle& id);

		int ComponentsTotal() const { return components.size(); }
		const std::vector<std::pair<Handle, TComponent>>& GetAllComponents() { return components; }

	private:
		std::vector<std::pair<Handle, TComponent>> components;
	};

	template<typename TComponent>
	inline bool Manager<TComponent>::Contains(const Handle & id)
	{
		return QCE::ContainsAny(components, [&id](const auto& component){ return component.first == id; });
	}

	template<typename TComponent>
	template<typename ... TArgs>
	TComponent& Manager<TComponent>::CreateComponent(const Handle& id, TArgs ... args)
	{
		if (!Contains(id))
		{
			components.push_back(std::make_pair(id, TComponent(args...)));
		}
		return GetComponent(id);
	}

	template<typename TComponent>
	inline TComponent& Manager<TComponent>::GetComponent(const Handle & id)
	{
		return QCE::Find<std::pair<Handle, TComponent>>(components,
			[&id](const auto& component){ return component.first == id; }).second;
	}
}