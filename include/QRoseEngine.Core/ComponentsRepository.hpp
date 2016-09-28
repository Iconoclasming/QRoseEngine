#pragma once

#include <map>
#include <sstream>
#include "Streaming.hpp"
#include "Uuid.hpp"

namespace QRose
{
	class ComponentsRepository
	{
	public:	
		template<typename TComponent>
		void Add(const TComponent& component);

		bool Contains(const Uuid& componentId);

		template<typename TComponent>
		TComponent Get(const Uuid& componentId);

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
	TComponent ComponentsRepository::Get(const Uuid& componentId)
	{
		std::stringstream ss;
		if(!Contains(componentId))
		{
			throw std::invalid_argument("component with id " + componentId.ToString() + " not found");
		}
		ss << components[componentId] << std::endl;
		return Streaming::Deserialize<TComponent>(ss);
	}
}