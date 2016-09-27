#pragma once

#include <map>
#include <sstream>
#include "Streaming.hpp"

namespace QRose
{
	class ComponentsRepository
	{
	public:	
		template<typename TComponent>
		void Add(const TComponent& component);

		template<typename TComponent>
		bool Contains(const TComponent& component);

	private:
		std::map<Uuid, std::string> components;
	};

	template <typename TComponent>
	void ComponentsRepository::Add(const TComponent& component)
	{
		std::stringstream ss;
		bool result = Streaming::Serialize(&component, ss);
		if(result)
		{
			components[component.GetID()] = ss.str();
		}
	}

	template <typename TComponent>
	bool ComponentsRepository::Contains(const TComponent& component)
	{
		return components.find(component.GetID()) != components.end();
	}
}